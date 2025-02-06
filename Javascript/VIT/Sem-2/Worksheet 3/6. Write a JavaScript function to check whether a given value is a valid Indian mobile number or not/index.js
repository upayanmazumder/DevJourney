function isValidIndianMobileNumber(number) {
    const regex = /^[6-9]\d{9}$/;
    return regex.test(number);
}

const number = "8798767324";
console.log(isValidIndianMobileNumber(number));