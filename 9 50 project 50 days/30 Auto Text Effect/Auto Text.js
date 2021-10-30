const text = document.querySelector('.text');
const speed = document.querySelector('.speed');
let speedEl = 300 / speed.value;
let index = 1;
const textEl = "I love programming";

autoRunText();
speed.addEventListener('input', (e) => {
    speedEl = 300 / e.target.value;
})

function autoRunText() {
    text.innerText = textEl.slice(0, index)
    index++;
    if (index > textEl.length) index = 1;
    setTimeout(autoRunText,speedEl);
}