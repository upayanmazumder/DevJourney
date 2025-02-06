function countVowels(str) {
    const matches = str.match(/[aeiouAEIOU]/g);
    return matches ? matches.length : 0;
}

const exampleString = "Hello World";
console.log(countVowels(exampleString));
