const leftBtn = document.querySelector('.left-btn');
const rightBtn = document.querySelector('.right-btn');

const leftSide = document.querySelector('#left');
const rightSide = document.querySelector('#right');

leftBtn.addEventListener('click', () => {
    leftSide.classList.add('big');
    if (rightSide.className === 'big') rightSide.classList.remove('big');
})
rightBtn.addEventListener('click', () => {
    rightSide.classList.add('big');
    if (leftSide.className === 'big') leftSide.classList.remove('big');
})