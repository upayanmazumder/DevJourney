require('dotenv').config();
const express = require('express');
const axios = require('axios');
const marked = require('marked');
const path = require('path');
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

// Fetch specific file's content with authentication
const fetchFileContent = async (filePath) => {
    try {
        const url = `${API_BASE}/${filePath}`;
        const response = await axios.get(url, {
            headers: {
                Authorization: `token ${process.env.GITHUB_TOKEN}`
            }
        });
        return Buffer.from(response.data.content, 'base64').toString('utf8');
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

    if (Array.isArray(contents)) {
        // Directory listing with README display
        const readme = contents.find((item) => item.name === 'README.md');
        let readmeContent = '';
        if (readme) {
            readmeContent = await fetchFileContent(`${route}/README.md`);
            readmeContent = marked.parse(readmeContent);
        }

        const breadcrumbs = generateBreadcrumbs(route);

        let html = `
            <html>
            <head>
                <title>DevJourney - ${route || 'Home'}</title>
                <style>
                    body {
                        font-family: Arial, sans-serif;
                        background-color: #121212;
                        color: #e0e0e0;
                        margin: 0;
                        padding: 0;
                    }
                    header {
                        background-color: #1f1f1f;
                        padding: 20px;
                        text-align: center;
                        color: #fff;
                    }
                    .content {
                        margin: 20px;
                    }
                    .breadcrumbs {
                        margin-bottom: 10px;
                        font-size: 14px;
                    }
                    .breadcrumbs a {
                        color: #03a9f4;
                        text-decoration: none;
                    }
                    .breadcrumbs a:hover {
                        text-decoration: underline;
                    }
                    h1 {
                        font-size: 2em;
                    }
                    h2 {
                        color: #f2f2f2;
                    }
                    .readme-content {
                        background-color: #282828;
                        padding: 20px;
                        border-radius: 5px;
                        color: #f0f0f0;
                    }
                    ul {
                        list-style-type: none;
                        padding: 0;
                    }
                    li {
                        margin: 10px 0;
                    }
                    .folder-icon, .file-icon {
                        margin-right: 10px;
                    }
                    a {
                        color: #03a9f4;
                        text-decoration: none;
                    }
                    a:hover {
                        text-decoration: underline;
                    }
                    footer {
                        text-align: center;
                        background-color: #1f1f1f;
                        color: #fff;
                        padding: 20px;
                        position: fixed;
                        bottom: 0;
                        width: 100%;
                    }
                </style>
            </head>
            <body>
                <header>DevJourney Explorer</header>
                <div class="content">
                    <div class="breadcrumbs">${breadcrumbs}</div>
                    <h1>${route || 'Home'}</h1>
                    ${readme ? `<div class="readme-content">${readmeContent}</div>` : '<p>No README.md available</p>'}
                    <h2>Contents:</h2>
                    <ul>
                        ${contents
                            .map(
                                (item) => `
                                    <li>
                                        <span class="${item.type === 'dir' ? 'folder-icon' : 'file-icon'}">
                                            ${item.type === 'dir' ? '📁' : '📄'}
                                        </span>
                                        <a href="/${route ? route + '/' : ''}${item.name}">
                                            ${item.name}
                                        </a>
                                    </li>
                                `
                            )
                            .join('')}
                    </ul>
                </div>
                <footer>© 2024 DevJourney by Upayan Mazumder</footer>
            </body>
            </html>
        `;

        res.send(html);
    } else {
        // File display with syntax highlighting for Markdown
        const fileContent = Buffer.from(contents.content, 'base64').toString('utf8');
        const fileHtml = contents.name.endsWith('.md') ? marked.parse(fileContent) : `<pre>${fileContent}</pre>`;
        const breadcrumbs = generateBreadcrumbs(route);

        res.send(`
            <html>
            <head>
                <title>${contents.name}</title>
                <style>
                    body {
                        font-family: Arial, sans-serif;
                        background-color: #121212;
                        color: #e0e0e0;
                        margin: 0;
                        padding: 0;
                        overflow-x: hidden;
                    }
                    header {
                        background-color: #1f1f1f;
                        padding: 20px;
                        text-align: center;
                        color: #fff;
                    }
                    .content {
                        margin: 20px;
                    }
                    .breadcrumbs {
                        margin-bottom: 10px;
                        font-size: 14px;
                    }
                    .breadcrumbs a {
                        color: #03a9f4;
                        text-decoration: none;
                    }
                    .breadcrumbs a:hover {
                        text-decoration: underline;
                    }
                    h1 {
                        font-size: 2em;
                    }
                    .file-content {
                        background-color: #282828;
                        padding: 20px;
                        border-radius: 5px;
                        color: #f0f0f0;
                        white-space: pre-wrap;
                        word-wrap: break-word;
                    }
                    footer {
                        text-align: center;
                        background-color: #1f1f1f;
                        color: #fff;
                        padding: 20px;
                        bottom: 0;
                        width: 100%;
                    }
                </style>
            </head>
            <body>
                <header>DevJourney Explorer - ${contents.name}</header>
                <div class="content">
                    <div class="breadcrumbs">${breadcrumbs}</div>
                    <h1>Viewing: ${contents.name}</h1>
                    <div class="file-content">${fileHtml}</div>
                </div>
                <footer>© 2024 DevJourney by Upayan Mazumder</footer>
            </body>
            </html>
        `);
    }
});

// Start the server
const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
    console.log(`Server is running on http://localhost:${PORT}`);
});
