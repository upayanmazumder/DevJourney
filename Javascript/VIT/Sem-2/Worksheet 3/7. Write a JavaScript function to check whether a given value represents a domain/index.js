function isValidDomain(domain) {
    const domainPattern = /^(?!:\/\/)([a-zA-Z0-9-_]+\.)*[a-zA-Z0-9][a-zA-Z0-9-_]+\.[a-zA-Z]{2,11}?$/;
    return domainPattern.test(domain);
}

console.log(isValidDomain("upayan.dev"));
console.log(isValidDomain("sub.upayan.dev"));
console.log(isValidDomain("upayan"));
console.log(isValidDomain("http://upayan.dev"));