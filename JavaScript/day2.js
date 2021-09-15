// Bai 3
const date = new Date();
// console.log(date.toLocaleString());

// Bai 4
//Write a JavaScript program to find the area of a triangle where lengths of the three of its sides are 5, 6, 7.
let answer = (a, b, c) => {
    return 1 / 4 * (Math.sqrt(((a + b + c) * (a + b - c) * (b + c - a) * (c + a - b))));
}
// console.log(answer(5,6,7));

// Bai 5 ( Kho vcl :(( )))
// Write a JavaScript program to rotate the string 'w3resource' in right direction by periodically removing one letter from the end of the string and attaching it to the front.

// O trong file RevereString href="../JavaScript/revereseString.html

// Bai 6 check Leap year

function checkLeapYear(year) {
    return (year % 100 === 0) ? (year % 400 === 0) : (year % 4 === 0);
}
// console.log(checkLeapYear(2016));
// console.log(checkLeapYear(2000));
// console.log(checkLeapYear(1700));
// console.log(checkLeapYear(1800));
// console.log(checkLeapYear(100));

// 7. Write a JavaScript program to find 1st January is being a Sunday between 2014 and 2050
function find() {
    for (let year = 2014; year <= 2050; year++) {
        let date = new Date(year, 0, 1);
        if (date.getDay() === 0) {
            console.log("1st January is being a Sunday " + year);
        }
    }
}
// find();

// 8. Write a JavaScript program where the program takes a random integer between 1 to 10, the user is then prompted to input a guess number. If the user input matches with guess number, the program will display a message "Good Work" otherwise display a message "Not matched".
function gessNumGame() {
    let randomNum = Math.floor(Math.random() * (10 - 1 + 1)) + 1;
    let userNum = prompt('Enter your guess number:');
    console.log(randomNum);
    (randomNum === userNum) ? console.log('Good Work') : console.log('Not matched');
}

// console.log(gessNumGame());