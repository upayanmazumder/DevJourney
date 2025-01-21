function getDaysInMonth(month, year) {
    return new Date(year, month, 0).getDate();
}

console.log(getDaysInMonth(2, 2020));
console.log(getDaysInMonth(2, 2021));
console.log(getDaysInMonth(4, 2021));
console.log(getDaysInMonth(12, 2021));