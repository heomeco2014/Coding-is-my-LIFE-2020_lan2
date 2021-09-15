//21. Write a JavaScript program to create a new string adding "Py" in front of a given string. If the given string begins with "Py" then return the original string.

function addPyInFront(string) {
    if (string[0] === 'P' && string[1] === 'y') return string;
    else return "Py" + string;
}

function addPyInFront2(string) {
    if (string.substring(0, 2) === 'py') return string;
    else return "Py" + string;
}
// console.log(addPyInFront2('PY'));
// 22. Write a JavaScript program to remove a character at the specified position of a given string and return the new string.
// Many ways, one function is different way
const removedString = (string, pos) => {
    return string.slice(0, pos) + string.slice(pos + 1);
}

function removeStringAtPos(string, pos) {
    return string.replace(string.charAt(pos), "");
}

function removeStringAtPos2(string, pos) {
    return string.replace(string[pos], "");
}
// console.log(removedString('w3resource', 5));
// console.log(removeStringAtPos('w3resource', 5));
// console.log(removeStringAtPos2('w3resource',5));

//23. Write a JavaScript program to create a new string from a given string changing the position of first and last characters. The string length must be greater than or equal to 1.
function swapFirstAndLast(string) {
    let swap = [...string];
    swap.shift();
    swap.pop();
    swap.push(string[0]);
    swap.unshift(string[string.length - 1]);
    return swap.join('');
}

// console.log(swapFirstAndLast('minh'));

function addFristAndEnd(string) {
    return string[0] + string + string[0];
}

// console.log(addFristAndEnd('Minh'));

//26. Write a JavaScript program to create a new string from a given string taking the last 3 characters and added at both the front and back. The string length must be 3 or more. 

function _26(string) {
    const lastThree = string.substring(string.length - 3);
    if (string.length >= 3) return lastThree + string + lastThree;
    return false;
}

// console.log(_26('Swift'));

//27. Write a JavaScript program to check whether a string starts with 'Java' and false otherwise. 

function _27(string, stringToCompare) {
    return string.substr(0, stringToCompare.length) === stringToCompare;
}

// console.log(_27('Javasdklfj', 'Java'));

// 30. Write a JavaScript program to check whether a string "Script" presents at 5th (index 4) position in a given string, if "Script" presents in the string return the string without "Script" otherwise return the original one.

const _30 = (string) => {
    if (string.substr(4, 'string'.length).toLowerCase() == 'script') {
        return string.substr(0, 4) + string.substr(4 + 'string'.length);
    }
    return string;
}

// console.log(_30('JavaScript'));

// 31. Write a JavaScript program to find the largest of three given integers.  Go to the editor
const _31 = (a, b, c) => {
    return Math.max(a, b, c);
}

// 35. Write a program to check whether a specified character exists within the 2nd to 4th position in a given string.

const _35 = (giveString, char) => {
    for (let i = 1; i < 4; i++) {
        if (giveString[i] === char) return true;
    }
    return false
}
// 36 Write a JavaScript program to check whether the last digit of the three given positive integers is same.

const _36 = (a, b, c) => {
    return (a % 10 === b % 10) && (b % 10 === a % 10) && (c % 10 === a % 10);
}

// console.log(_36(20, 30, 40));

//37. Write a JavaScript program to create new string with first 3 characters are in lower case from a given string. If the string length is less than 3 convert all the characters in upper case.  
const _37 = (string) => {
    if (string.length < 3) return string.toUpperCase();
    return string.substr(0, 3).toLowerCase() + string.substr(3);
}

// console.log(_37('PYTHON'));

//42. Write a JavaScript program to check whether three given numbers are increasing in strict mode or in soft mode.  Go to the editor
// Note: Strict mode -> 10, 15, 31 : Soft mode -> 24, 22, 31 or 22, 22, 31

function strictOrSoft(a, b, c) {
    if (a < b && b < c) return 'Strict Mode';
    else if (a < c) return 'Soft Mode';
}

// console.log(strictOrSoft(24,22,31));

// 48. Write a JavaScript program to reverse a given string.
// C++ way
function revereseString(string) {
    let res = [];
    for (let i = string.length - 1; i >= 0; i--) {
        res += string[i];
    }
    return res;
}

function revereseStringJavaScript(string) {
    return string.split("").reverse().join("");
}
// console.log(revereseString('Minh'));
// console.log(revereseStringJavaScript('Minh'));
//49. Write a JavaScript program to replace every character in a given string with the character following it in the alphabet.
const _49 = (string) => {
    let res = "";
    for (let i = 0; i < string.length; i++) {
        let nextString = (string.codePointAt(i)) + 1;
        let stringFromChar = String.fromCharCode(nextString);
        if (stringFromChar === '{') stringFromChar = 'a';
        res += stringFromChar;
    }
    return res;
}

// console.log(_49(''));

//50. Write a JavaScript program to capitalize the first letter of each word of a given string.
// ES6 Syntax
const _50 = (string) => {
    let str = string.replace(/\s+/g, ' ').trim().split(' ');
    return str.map(word => word[0].toUpperCase() + word.substr(1)).join(' ');
}

function capital_letter(str) {
    str = str.trim().split(" ");

    for (var i = 0, x = str.length; i < x; i++) {
        str[i] = str[i][0].toUpperCase() + str[i].substr(1);
    }

    return str.join(" ");
}
console.log(_50('hello this is me right'));
//Check whether the characters a and b are separated by exactly 3 places anywhere in a given string
const _53 = (string) => {
    let aPos = string.indexOf('a');
    let bPos = string.indexOf('b');
    return Math.abs(bPos - aPos) === 4;
}
// console.log(_53('a124b'));

