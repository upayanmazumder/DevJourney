// Bg blue on mouseenter and bg red on double click outside of nav
document.addEventListener('DOMContentLoaded', (event) => {
    const body = document.querySelector('body');

    body.addEventListener('mouseenter', () => {
        body.style.backgroundColor = 'blue';
    });

    body.addEventListener('mouseleave', () => {
        body.style.backgroundColor = '';
    });

    // Change background to red on double-click outside nav
    body.addEventListener('dblclick', (e) => {
        const nav = document.querySelector('nav');
        if (!nav.contains(e.target)) {
            body.style.backgroundColor = 'red';
        }
    });
});

// Header dropdown 
document.addEventListener('DOMContentLoaded', function() {
    var dropdown = document.querySelector('.dropdown');
    var dropdownContent = document.querySelector('.dropdown-content');

    dropdown.addEventListener('mouseover', function() {
        dropdownContent.style.display = 'block';
    });

    dropdown.addEventListener('mouseout', function() {
        dropdownContent.style.display = 'none';
    });
});

// Nav selection name display
document.addEventListener('DOMContentLoaded', () => {
    const links = document.querySelectorAll('.dropdown-content a');
    const selectionDiv = document.getElementById('selection');

    links.forEach(link => {
        link.addEventListener('click', (event) => {
            event.preventDefault();
            selectionDiv.textContent = link.textContent;
        });
    });

    const selection = document.getElementById('selection');

    selection.addEventListener('mouseenter', () => {
        selection.style.color = 'red';
    });

    selection.addEventListener('mouseleave', () => {
        selection.style.color = '';
    });
});