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
  setActiveSlide();
})
leftBtn.addEventListener('click', () => {
  activeSlide--;
  if (activeSlide < 0) {
    activeSlide = slides.length;
  }
  setBgToBody();
  setActiveSlide();
})

function setBgToBody() {
  body.style.backgroundImage = slides[activeSlide].style.backgroundImage;
}

function setActiveSlide() {
  slides.forEach(slide => {
    slide.classList.remove('active');
    slides[activeSlide].classList.add('active');
  })
}