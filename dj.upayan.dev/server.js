require('dotenv').config();
const express = require('express');
const axios = require('axios');
const marked = require('marked');
const path = require('path');
const hljs = require('highlight.js');
const app = express();

// GitHub API setup
const GITHUB_REPO = 'upayanmazumder/devjourney';
const API_BASE = `https://api.github.com/repos/${GITHUB_REPO}/contents`;

// Fetch GitHub contents with authentication
const fetchContents = async (route) => {
    try {
        const url = `${API_BASE}${route ? `/${route}` : ''}`;
        const response = await axios.get(url, {
            headers: {
                Authorization: `token ${process.env.GITHUB_TOKEN}`
            }
        });
        return response.data;
    } catch (error) {
        console.error('Error fetching GitHub content:', error);
        return null;
    }
};

// Fetch specific file's content with syntax highlighting
const fetchFileContent = async (filePath) => {
    try {
        const url = `${API_BASE}/${filePath}`;
        const response = await axios.get(url, {
            headers: {
                Authorization: `token ${process.env.GITHUB_TOKEN}`
            }
        });
        const content = Buffer.from(response.data.content, 'base64').toString('utf8');
        const extension = path.extname(filePath);

        // Syntax highlight for non-Markdown files
        if (extension !== '.md') {
            const language = hljs.getLanguage(extension.slice(1)) ? extension.slice(1) : 'plaintext';
            return hljs.highlight(content, { language }).value;
        }
        // Markdown content is parsed without syntax highlight
        return marked.parse(content);
    } catch (error) {
        console.error('Error fetching file content:', error);
        return null;
    }
};

// Generate breadcrumbs
const generateBreadcrumbs = (route) => {
    const parts = route ? route.split('/') : [];
    let breadcrumbHtml = `<a href="/">Home</a>`;
    parts.forEach((part, index) => {
        const url = parts.slice(0, index + 1).join('/');
        breadcrumbHtml += ` / <a href="/${url}">${part}</a>`;
    });
    return breadcrumbHtml;
};

// Route to handle dynamic folder paths and file viewing
app.get('/*', async (req, res) => {
    const route = req.params[0];
    const contents = await fetchContents(route);

    if (!contents) {
        return res.status(404).send('Directory or file not found.');
    }

    const githubUrl = `https://github.com/${GITHUB_REPO}/tree/main/${route || ''}`;
    const breadcrumbs = generateBreadcrumbs(route);

    let contentHtml;
    if (Array.isArray(contents)) {
        // Directory listing with README display
        const readme = contents.find((item) => item.name === 'README.md');
        const readmeContent = readme ? await fetchFileContent(`${route}/README.md`) : '<p>No README available</p>';

        contentHtml = `
            <div class="readme-content">${readmeContent}</div>
            <h2>Contents:</h2>
            <ul class="file-list">
                ${contents.map((item, index) => `
                    <li style="animation-delay: ${index * 0.1}s;">
                        <span>${item.type === 'dir' ? '📁' : '📄'}</span>
                        <a href="/${route ? route + '/' : ''}${item.name}">${item.name}</a>
                    </li>
                `).join('')}
            </ul>
        `;
    } else {
        // Render file with syntax highlighting
        const fileContent = await fetchFileContent(route);

        contentHtml = `<div class="file-content"><pre><code>${fileContent}</code></pre></div>`;
    }

    res.send(`
        <html>
        <head>
            <title>DevJourney - ${route || 'Home'}</title>
            <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.2.0/styles/github-dark.min.css">
            <style>
                body { font-family: Arial, sans-serif; background-color: #0d0d0d; color: #d3d3d3; margin: 0; padding: 0; overflow-x: hidden; }
                header { background-color: #1f1f1f; padding: 20px; text-align: center; color: #03a9f4; animation: slideInDown 0.6s ease-out; position: sticky; top: 0; z-index: 100; }
                .content { max-width: 800px; margin: 20px auto; padding: 0 20px; }
                .breadcrumbs { margin-bottom: 20px; font-size: 14px; color: #d3d3d3; animation: fadeInLeft 0.7s ease-out; }
                .breadcrumbs a { color: #03a9f4; text-decoration: none; }
                .breadcrumbs a:hover { text-decoration: underline; }
                h1 { font-size: 2em; margin-bottom: 0.5em; color: #e0e0e0; }
                .readme-content, .file-content { background-color: #121212; padding: 20px; border-radius: 8px; color: #d3d3d3; animation: fadeIn 0.8s ease-out; }
                .file-list { list-style-type: none; padding: 0; margin: 0; }
                .file-list li { margin: 10px 0; opacity: 0; transform: translateY(20px); animation: fadeInUp 0.5s ease forwards; }
                .file-list a { color: #03a9f4; text-decoration: none; }
                .file-list a:hover { text-decoration: underline; }
                .github-button { margin-top: 20px; display: flex; justify-content: center; }
                .button { padding: 10px 20px; background-color: #03a9f4; border: none; color: #fff; border-radius: 5px; font-weight: bold; font-size: 16px; cursor: pointer; text-decoration: none; animation: bounceIn 1s ease; transition: all 0.3s ease; }
                .button:hover { background-color: #039be5; box-shadow: 0px 4px 15px rgba(0, 169, 244, 0.6); transform: translateY(-2px); animation: pulse 1s infinite; }
                @keyframes fadeInLeft { from { opacity: 0; transform: translateX(-20px); } to { opacity: 1; transform: translateX(0); } }
                @keyframes fadeInUp { from { opacity: 0; transform: translateY(20px); } to { opacity: 1; transform: translateY(0); } }
                @keyframes bounceIn { 0%, 20%, 50%, 80%, 100% { transform: translateY(0); } 40% { transform: translateY(-15px); } 60% { transform: translateY(-7px); } }
                @keyframes pulse { 0% { transform: scale(1); } 50% { transform: scale(1.05); } 100% { transform: scale(1); } }
                @media (max-width: 600px) {
                    .content { padding: 10px; }
                    h1 { font-size: 1.5em; }
                    .button { font-size: 14px; padding: 8px 16px; }
                }
            </style>
        </head>
        <body>
            <header>DevJourney</header>
            <div class="content">
                <div class="breadcrumbs">${breadcrumbs}</div>
                <h1>${route || 'Home'}</h1>
                ${contentHtml}
                <div class="github-button">
                    <a href="${githubUrl}" target="_blank" class="button">View on GitHub</a>
                </div>
            </div>
        </body>
        </html>
    `);
});

// Start the server
const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
    console.log(`Server is running on http://localhost:${PORT}`);
});
