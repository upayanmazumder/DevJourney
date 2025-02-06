function isValidURL(str) {
    const pattern = new RegExp('^(https?:\\/\\/)?(www\\.)?[a-z0-9]+(\\.[a-z]{2,}){1,3}(\\/.*)?$', 'i');
    return !!pattern.test(str);
}

console.log(isValidURL('http://upayan.dev'));
console.log(isValidURL('upayan'));
