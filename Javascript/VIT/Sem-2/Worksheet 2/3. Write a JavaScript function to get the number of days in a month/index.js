function getDaysInMonth(month, year) {
    return new Date(year, month, 0).getDate();
}

console.log(getDaysInMonth(2, 2024));
console.log(getDaysInMonth(2, 2025));
console.log(getDaysInMonth(4, 2025));
console.log(getDaysInMonth(12, 2025));