const days = document.querySelector('#days');
const hours = document.querySelector('#hours');
const mins = document.querySelector('#mins');
const seconds = document.querySelector('#seconds');


function countDown() {
    const nextChrismax = new Date(2021, 11, 24, 12, 0, 0);
    const currentDate = new Date();

    const totalSeconds = (nextChrismax - currentDate) / 1000;
    const second = Math.floor(totalSeconds % 60);

    const minutes = Math.floor((totalSeconds) / 60) % 60;

    const hour = Math.floor((totalSeconds / 3600) % 24) - 1;

    const day = Math.floor((totalSeconds) / (3600) / 24);
    days.innerHTML = formatTime(day);
    hours.innerHTML = formatTime(hour);
    mins.innerHTML = formatTime(minutes);
    seconds.innerHTML = formatTime(second);
}

function formatTime(time) {
    return time < 10 ? `0${time}` : time; // Neu con duoi 10 giay (vd 9 8 7 )    thi se hien thi la 09 08 07 06 ...
}
countDown();
setInterval(countDown, 1000);