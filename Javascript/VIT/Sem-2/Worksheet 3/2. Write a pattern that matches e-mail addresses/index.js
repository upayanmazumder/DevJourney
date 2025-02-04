const emailPattern = /^[a-zA-Z0-9!#$%&'*+/=?^_`{|}~-]+(?:\.[a-zA-Z0-9!#$%&'*+/=?^_`{|}~-]+)*@[a-zA-Z0-9-]+(?:\.[a-zA-Z0-9-]+)*\.[a-zA-Z]{2,}$/;

// Test the pattern
const testEmails = [
    "test.email@upayan.dev",
    "user+name@sub.upayan.dev",
    "user_name@upayan.dev",
    "user-name@subdomain.upayan.dev",
    "user@sub.subdomain.upayan.dev",
    "user@domain.com",
    "user@upayan.com",
    "user@upayan.dev.com",
    ".user@upayan.dev",
    "user.@upayan.dev"
];

testEmails.forEach(email => {
    console.log(`${email} : ${emailPattern.test(email)}`);
});