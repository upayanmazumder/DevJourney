function dateDifferenceInDays(date1, date2) {
    const date1Ms = new Date(date1).getTime();
    const date2Ms = new Date(date2).getTime();

    const differenceMs = Math.abs(date1Ms - date2Ms);

    return Math.ceil(differenceMs / (1000 * 60 * 60 * 24));
}

const date1 = '2025-10-01';
const date2 = '2025-10-10';
console.log(dateDifferenceInDays(date1, date2));