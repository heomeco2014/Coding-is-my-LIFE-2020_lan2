'use strict';
const loveMe = document.querySelector('.loveMe');
const time = document.querySelector('time');

let click = 0;
loveMe.addEventListener('click', (e) => {
    if (click === 0) {
        click = new Date().getTime();
    } else {
        if (new Date().getTime() - click < 600) {
            createHeart(e);
            click = 0;
        } else {
            click = new Date().getTime();
        }
    }
})

const createHeart = (e) => {
    const heart = document.createElement('i')
    heart.classList.add('fas')
    heart.classList.add('fa-heart')

    const x = e.clientX;
    const y = e.clientY;

    const leftOffSet = e.target.offsetLeft;
    const topOffSet = e.target.offsetTop;

    const xInside = x - leftOffSet;
    const yInside = y - topOffSet;


    heart.style.top = `${yInside}px`
    heart.style.left = `${xInside}px`
    loveMe.appendChild(heart);
    setTimeout(() => heart.remove(), 1000)
}