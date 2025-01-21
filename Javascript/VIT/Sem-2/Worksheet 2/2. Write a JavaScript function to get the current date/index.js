function getCurrentDate(sep) {
    const date = new Date();
    const day = String(date.getDate()).padStart(2, '0');
    const month = String(date.getMonth() + 1).padStart(2, '0');
    const year = date.getFullYear();

    return `${month}${sep}${day}${sep}${year}`;
}

console.log(getCurrentDate('/'));
console.log(getCurrentDate('-'));