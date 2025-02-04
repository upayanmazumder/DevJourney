function isWeekend(date) {
    const day = date.getDay();
    return day === 0 || day === 6;
}

const date = new Date('2025-02-09');
if (isWeekend(date)) {
    console.log(`Yes, ${date.toDateString()} is a weekend`);
} else {
    console.log(`No, ${date.toDateString()} is not a weekend`);
}