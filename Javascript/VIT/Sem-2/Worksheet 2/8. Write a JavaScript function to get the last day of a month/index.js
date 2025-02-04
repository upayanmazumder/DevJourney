function getLastDayOfMonth(year, month) {
    return new Date(year, month + 1, 0).getDate();
}

console.log(getLastDayOfMonth(2025, 0));
console.log(getLastDayOfMonth(2025, 1));
console.log(getLastDayOfMonth(2025, 11));