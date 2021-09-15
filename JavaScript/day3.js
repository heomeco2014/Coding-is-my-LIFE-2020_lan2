//9. Write a JavaScript program to calculate days left until next Christmas


function untilNextChristmas(inputDate = new Date().toLocaleDateString(

)) {

    const userInputDay = inputDate.split('/');
    const day = userInputDay[0];
    const month = userInputDay[1];
    const year = userInputDay[2];

    let dayComepare = new Date(year, month, day);
    let today = new Date();
    let ChristmasYear = today.getFullYear();
    let one_day = 1000 * 60 * 60 * 24;
    if (year > ChristmasYear) {
        var plus = 365 * (year - ChristmasYear);
        ChristmasYear = year;
    }
    if (plus === undefined) plus = 0;

    const Christmas = new Date(ChristmasYear, 11, 25);

    console.log(Math.ceil((Math.abs(Christmas.getTime() - dayComepare.getTime())) / (one_day) + plus) + " days left until Christmas");
}
// untilNextChristmas();

// Cai nay tu viet cho vui
function howManyDaysUntilThisDay(inputDate, DateToCompare) {
    const userInputDay = inputDate.split('/');
    const day = userInputDay[0];
    const month = userInputDay[1];
    const year = userInputDay[2];

    const userInputDay2 = DateToCompare.split('/');
    const day2 = userInputDay2[0];
    const month2 = userInputDay2[1];
    const year2 = userInputDay2[2];

    let firstDate = new Date(year, month, day);
    let secondDate = new Date(year2, month2, day2);

    let one_day = 1000 * 60 * 60 * 24;
    const daysLeft = firstDate.getTime() - secondDate.getTime();
    console.log(Math.ceil(Math.abs(daysLeft) / one_day));
}

// howManyDaysUntilThisDay('13/9/2021', '13/9/2021');
//11. Write a JavaScript program to convert temperatures to and from Celsius, Fahrenheit.

function CelsiusToFahrenheit(params) {
    return params * 9 / 5 + 32;
}

function FahrenheitToCelsius(params) {
    return (params - 32) * (5 / 9);
}

// console.log(CelsiusToFahrenheit(60));
// console.log(FahrenheitToCelsius(45));

//Write a JavaScript exercise to get the extension of a filename.
function getExtensionName(fullAppName) {
    let appName = [...fullAppName];
    return appName.slice(appName.lastIndexOf('.') + 1).join('');
}

function getExtensionName2(fullAppName) {
    return fullAppName.substring(fullAppName.lastIndexOf('.'));
}

//15. Write a JavaScript program to get the difference between a given number and 13, if the number is greater than 13 return double the absolute difference.
function greaterThan(num, numToCompare) {
    return num > numToCompare ? (num - numToCompare) : (numToCompare - num) * 2;
}
// console.log(greaterThan(32, 13));

// 19. Write a JavaScript program to check whether a given integer is within 20 of 100 or 400.
const integerInRange = (integer) => {
    return (Math.abs(100 - integer) <= 20) || (Math.abs(400 - integer) <= 20);
}
// console.log(integerInRange(10));
// console.log(integerInRange(90));
// console.log(integerInRange(99));
// console.log(integerInRange(199));
// console.log(integerInRange(200));

// 20. Write a JavaScript program to check from two given integers, whether one is positive and another one is negative.  
const bai20 = (a, b) => {
    return a > 0 && b < 0 || a < 0 && b > 0;
}

// console.log(bai20(10,-20));

