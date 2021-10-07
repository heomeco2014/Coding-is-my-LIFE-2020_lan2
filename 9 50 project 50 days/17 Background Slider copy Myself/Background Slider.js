const slides = document.querySelectorAll('.slide');
const leftBtn = document.querySelector('#left');
const rightBtn = document.querySelector('#right');
const body = document.body;

let activeSlide = 0;

setBgToBody();
rightBtn.addEventListener('click', () => {
  activeSlide++;
  if (activeSlide === slides.length) {
    activeSlide = 0;
  }
  setBgToBody();
})

leftBtn.addEventListener('click', () => {
  activeSlide--;
  if (activeSlide < 0) {
    activeSlide = slides.length - 1;
  }
  setBgToBody();
})

function setBgToBody() {
  body.style.backgroundImage = slides[activeSlide].style.backgroundImage;
}