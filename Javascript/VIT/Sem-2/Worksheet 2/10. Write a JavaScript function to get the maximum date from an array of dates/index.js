function getMaxDate(dates) {
    if (!Array.isArray(dates) || dates.length === 0) {
        return null;
    }
    const maxDate = new Date(Math.max.apply(null, dates.map(date => new Date(date))));
    return maxDate.toISOString().split('T')[0];
}

const dates = [
    '2025-01-01',
    '2022-12-31',
    '2025-05-15',
    '2024-06-20'
];

console.log(getMaxDate(dates));