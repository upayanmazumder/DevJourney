function is_date(input) {
    return Object.prototype.toString.call(input) === '[object Date]';
}

console.log(is_date(new Date("October 13, 2014 11:13:00")));
console.log(is_date(86400000));
console.log(is_date(new Date(99, 5, 24, 11, 33, 30, 0)));
console.log(is_date(new Date(1, 2, 4, 0)));
console.log(is_date("Abcd1234"));
