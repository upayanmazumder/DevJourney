function searchDateInString(inputString) {
    const datePattern = /\b\d{2}[\/-]\d{2}[\/-]\d{4}\b/;
    const result = inputString.match(datePattern);
    return result ? result[0] : "No date found in the string";
}

// Example usage
const testString = "Today's date is 15/10/2023 and tomorrow's date is 16-10-2023.";
console.log(searchDateInString(testString));