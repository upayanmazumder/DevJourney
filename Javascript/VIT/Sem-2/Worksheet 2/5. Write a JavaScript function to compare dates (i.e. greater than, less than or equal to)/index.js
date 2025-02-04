function compareDates(date1, date2) {
    const d1 = new Date(date1);
    const d2 = new Date(date2);

    if (d1 > d2) {
        return `${date1} is after ${date2}`;
    } else if (d1 < d2) {
        return `${date1} is before ${date2}`;
    } else {
        return `${date1} is same as ${date2}`;
    }
}

console.log(compareDates('2025-10-01', '2025-10-02'));
console.log(compareDates('2025-10-02', '2025-10-01'));
console.log(compareDates('2025-10-01', '2025-10-01'))