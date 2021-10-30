const leftSlider = document.querySelector('.left-slider');
const rightSlider = document.querySelector('.right-slider');
const leftSliderContents = document.querySelectorAll('.left-slider__content');
const sliderContainer = document.querySelector('.slider-container');

const upBtn = document.querySelector('.up-button');
const downBtn = document.querySelector('.down-button');
const slidesLength = rightSlider.querySelectorAll('div').length;


let activeSlide = 0;
leftSlider.style.top = `-${(slidesLength - 1) * 100}vh`

upBtn.addEventListener('click', () => {
    changeSlide('up');
})
downBtn.addEventListener('click', () => {
    changeSlide('down');
})


const changeSlide = (direction) => {
    const sliderHeight = sliderContainer.clientHeight;
    if (direction == 'up') {
        activeSlide++;
        if (activeSlide > slidesLength - 1) {
            activeSlide = 0;
        }
    } else if (direction == 'down') {
        activeSlide--;
        if (activeSlide < 0) {
            activeSlide = slidesLength - 1;
        }
    }

    rightSlider.style.transform = `translateY(-${activeSlide*sliderHeight}px)`
    leftSlider.style.transform = `translateY(${activeSlide*sliderHeight}px)`
}