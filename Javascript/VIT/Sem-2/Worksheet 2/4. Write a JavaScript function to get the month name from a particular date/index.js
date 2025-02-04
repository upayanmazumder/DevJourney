function getMonthName(date) {
    const monthNames = [
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    ];
    return monthNames[date.getMonth()];
}

const date = new Date('2025-10-09');
console.log(getMonthName(date));