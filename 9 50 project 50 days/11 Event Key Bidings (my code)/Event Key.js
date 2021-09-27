let key = document.querySelector('.key');
let keyCode = document.querySelector('.keyCode');
let code = document.querySelector('.Code');
let container = document.querySelector('.container');
window.addEventListener('keydown', (e) => {
    // if (e.key === ' ') {
    //     key.innerText = 'Space';
    // } else key.innerText = e.key
    // keyCode.innerText = e.keyCode;
    // code.innerText = e.code;
    container.innerHTML = `
    <div class="wrap">
    <div class="event-text eventKey-text">event.key</div>
    <div class="event key">
    ${e.key}
    </div>
</div>
<div class="wrap">
    <div class="event-text keyCode-text">event.keyCode</div>
    <div class="event keyCode">
    ${e.keyCode}
    </div>
</div>
<div class="wrap">
    <div class="event-text eventCode-text">event.code</div>
    <div class="event Code">
    ${e.code}
    </div>
</div>
</div>`
})

// window.addEventListener('keyup', () => {
//     container.innerHTML = `
//     <div class="btn">Press any key to display</div>`
// })