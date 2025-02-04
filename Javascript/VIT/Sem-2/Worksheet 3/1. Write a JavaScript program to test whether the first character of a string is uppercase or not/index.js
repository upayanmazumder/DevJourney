function isFirstCharacterUppercase(str) {
    if (str.length === 0) {
        return false;
    }
    const firstChar = str.charAt(0);
    return firstChar === firstChar.toUpperCase();
}

const testString = "Hello World";
console.log(isFirstCharacterUppercase(testString));

const testString2 = "hello World";
console.log(isFirstCharacterUppercase(testString2));