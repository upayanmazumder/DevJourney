require('dotenv').config();
const express = require('express');
const axios = require('axios');
const marked = require('marked');
const path = require('path');
const hljs = require('highlight.js');
const app = express();

app.use(express.static('public'));

const GITHUB_REPO = 'upayanmazumder/devjourney';
const API_BASE = `https://api.github.com/repos/${GITHUB_REPO}/contents`;

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

        if (extension !== '.md') {
            const language = hljs.getLanguage(extension.slice(1)) ? extension.slice(1) : 'plaintext';
            return hljs.highlight(content, { language }).value;
        }
        return marked.parse(content);
    } catch (error) {
        console.error('Error fetching file content:', error);
        return null;
    }
};

const generateBreadcrumbs = (route) => {
    const parts = route ? route.split('/') : [];
    let breadcrumbHtml = `<a href="/">Home</a>`;
    parts.forEach((part, index) => {
        const url = parts.slice(0, index + 1).join('/');
        breadcrumbHtml += ` / <a href="/${url}">${part}</a>`;
    });
    return breadcrumbHtml;
};

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
        const fileContent = await fetchFileContent(route);

        contentHtml = `<div class="file-content"><pre><code>${fileContent}</code></pre></div>`;
    }

    res.send(`
        <html>
        <head>
            <title>DevJourney - ${route || 'Home'}</title>
            <link rel="icon" href="/favicon.ico" type="image/x-icon">
            <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.2.0/styles/github-dark.min.css">
            <link rel="stylesheet" href="/styles.css">
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
            <footer>
                <a href="https://github.com/upayanmazumder/devjourney" target="_blank">GitHub Repository</a>
                <p>This site is under active development and may not work as expected.</p>
            </footer>
        </body>
        </html>
    `);
});

const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
    console.log(`Server is running on http://localhost:${PORT}`);
});
