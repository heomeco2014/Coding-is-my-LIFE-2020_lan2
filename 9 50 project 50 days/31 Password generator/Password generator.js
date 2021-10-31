const showPass = document.querySelector('#password');
const clipBoard = document.querySelector('.fa-clipboard');
const passLength = document.querySelector('#password__length');
const upperCase = document.querySelector('#uppercase');
const lowerCase = document.querySelector('#lowercase');
const numbers = document.querySelector('#numbers');
const symbols = document.querySelector('#symbols');
const generateEl = document.querySelector('.generate-btn');

var upperCaseLetters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
var lowerCaseLetters = 'abcdefghijklmnopqrstuvwxyz';
var numbersLetters = '0123456789';
const randomFunctions = {
    lower: getRandomLower,
    upper: getRandomUpper,
    number: getRandomNumbers,
    symbol: randomSpecialChar
}


generateEl.addEventListener('click', () => {
    const length = +passLength.value; // string to number

    const hasNum = numbers.checked;
    const hasUps = upperCase.checked;
    const hasLows = lowerCase.checked;
    const hasSyms = symbols.checked;
    showPass.innerText = generatePassword(hasLows, hasUps, hasNum, hasSyms, length);

})

function generatePassword(lower, upper, number, symbol, length) {
    let generatedPassword = ''
    const typesCount = lower + upper + number + symbol
    const typesArr = [{
        lower
    }, {
        upper
    }, {
        number
    }, {
        symbol
    }].filter(item => Object.values(item)[0])

    console.log(123);
    if (typesCount === 0) {
        return ''
    }

    for (let i = 0; i < length; i += typesCount) {
        typesArr.forEach(type => {
            const funcName = Object.keys(type)[0]
            generatedPassword += randomFunctions[funcName]()
        })
    }

    const finalPassword = generatedPassword.slice(0, length)
    return finalPassword
}


clipBoard.addEventListener('click', () => {
    const textarea = document.querySelector('textarea');
    console.log(showPass.innerText);
    if (!password) {
        return
    }
    navigator.clipboard.writeText(showPass.innerText);
    alert('Password copied to clipboard!')
})

function getRandomUpper() {
    return upperCaseLetters[Math.floor(Math.random() * lowerCaseLetters.length)];
}

function getRandomLower() {
    return lowerCaseLetters[Math.floor(Math.random() * lowerCaseLetters.length)];
}

function getRandomNumbers() {
    return numbersLetters[Math.floor(Math.random() * numbersLetters.length)];
}
// I found this on the internet
function randomSpecialChar() {
    // example set of special chars as a string in no particular order
    const s = "!\"§$%&/()=?\u{20ac}";

    // generating a random index into the string and extracting the character at that position
    return s.substr(Math.floor(s.length * Math.random()), 1);
}