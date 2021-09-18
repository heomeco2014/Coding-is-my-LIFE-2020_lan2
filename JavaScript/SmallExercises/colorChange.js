$ = document.querySelector.bind(document);
const btn = $('#btn');
const h1 = $('h1');

function changeColor() {
    const r = Math.floor(Math.random() * 255);
    const g = Math.floor(Math.random() * 255);
    const b = Math.floor(Math.random() * 255);
    return `rgba(${r}, ${g}, ${b})`;
}
btn.addEventListener('mouseover', function () {
    document.body.style.backgroundColor = changeColor();
    h1.innerText = changeColor();
})