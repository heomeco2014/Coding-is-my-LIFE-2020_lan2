const lables = document.querySelectorAll('.form-input label');

lables.forEach((lable) => {
    lable.innerHTML = lable.innerText
        .split("")
        .map((letter, idx) => `<span style="transition-delay:${idx*15}ms">${letter}</span>`)
        .join("");
})