function getYesterday() {
    const today = new Date();
    const yesterday = new Date(today);
    yesterday.setDate(today.getDate() - 1);

    const options = { weekday: 'long' };
    return yesterday.toLocaleDateString('en-US', options);
}

console.log("Yesterday was: " + getYesterday());