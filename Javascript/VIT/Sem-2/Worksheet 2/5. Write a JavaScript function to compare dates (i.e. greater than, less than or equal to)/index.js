function compareDates(date1, date2) {
    const d1 = new Date(date1);
    const d2 = new Date(date2);

    if (d1 > d2) {
        return `${date1} is greater than ${date2}`;
    } else if (d1 < d2) {
        return `${date1} is less than ${date2}`;
    } else {
        return `${date1} is equal to ${date2}`;
    }
}

console.log(compareDates('2023-10-01', '2023-10-02'));
console.log(compareDates('2023-10-02', '2023-10-01'));
console.log(compareDates('2023-10-01', '2023-10-01'))