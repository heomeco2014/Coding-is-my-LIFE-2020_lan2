'use strict';
const darkMode = document.querySelector('.toggle');
const hoursEl = document.querySelector('.hours');
const minutesEl = document.querySelector('.minutes');
const secondsEl = document.querySelector('.seconds');
const timeEl = document.querySelector('.time');
const dateEl = document.querySelector('.date');

const days = ['Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday'];

const months = ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December'];


darkMode.addEventListener('click', (e) => {
    const html = document.querySelector('html');
    if (html.classList.contains('dark')) {
        html.classList.remove('dark');
    } else {
        html.classList.add('dark');
        e.target.innerHTML = 'Light Mode';
    }
})
setInterval(displayDate, 1000);

function scale(number, inMin, inMax, outMin, outMax) {
    return (number - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
}

function displayDate() {
    const time = new Date();
    const month = time.getMonth();
    const day = time.getDay();
    const hours = time.getHours();
    const minutes = time.getMinutes();
    const seconds = time.getSeconds();
    const date = time.getDate();
    hoursEl.style.transform = `translate(-50%,-100%) rotate(${scale(hours % 12,0,11,0,360)}deg)`;
    minutesEl.style.transform = `translate(-50%,-100%) rotate(${scale(minutes,0,59,0,360)}deg)`;
    secondsEl.style.transform = `translate(-50%,-100%) rotate(${scale(seconds,0,59,0,360)}deg)`;
    timeEl.innerText = `${hours % 12}:${minutes < 10 ? `0${minutes}`: minutes} ${hours >= 12 ? `PM` :'AM'} `;
    dateEl.innerHTML = `${days[day]} ${months[month].slice(0,3)}<span class="circle"> ${date} </span>`;
}