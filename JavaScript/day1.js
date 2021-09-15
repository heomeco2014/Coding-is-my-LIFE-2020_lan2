const date = new Date();

const days = ['Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday'];
const months = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];

let day = days[date.getDay()];

let month = months[date.getMonth()];

let year = date.getFullYear();


console.log(`Today is ${day} ${month} ${year}`);
let me = () => {
    for (let i = 0; i < 10; i++) {
        setTimeout(() => {
            let plus = i * 2;
            let min = date.getMinutes();
            if (plus === 60) {
                plus = 0;
                min++;
            }
            console.log(`Current time is: ${date.getHours()}:${min}:${date.getSeconds()}`);
        }, i * 2000);
    }
}
// me();