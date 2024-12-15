document.addEventListener('DOMContentLoaded', async () => {
    const headerContainer = document.getElementById('header-container');
    const footerContainer = document.getElementById('footer-container');

    if (headerContainer) {
        try {
            const response = await fetch('../components/header/header.html');
            if (response.ok) {
                const headerHTML = await response.text();
                headerContainer.innerHTML = headerHTML;
            } else {
                console.error('Failed to load header:', response.status, response.statusText);
            }
        } catch (error) {
            console.error('Error fetching header:', error);
        }
    }

    if (footerContainer) {
        try {
            const response = await fetch('../components/footer/footer.html');
            if (response.ok) {
                const footerHTML = await response.text();
                footerContainer.innerHTML = footerHTML;
            } else {
                console.error('Failed to load footer:', response.status, response.statusText);
            }
        } catch (error) {
            console.error('Error fetching footer:', error);
        }
    }
});
