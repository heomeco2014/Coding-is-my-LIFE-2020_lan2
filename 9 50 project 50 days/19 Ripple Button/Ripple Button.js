const buttons = document.querySelectorAll('.btn');

    buttons.forEach(button => {
        button.addEventListener('click', function (e) {
            const x = e.clientX;
            const y = e.clientY;

            const buttonTop = e.target.offsetTop;
            const buttonLeft = e.target.offsetLeft;

            const xInside = x - buttonLeft;
            const yInside = y - buttonTop;
            const white = document.createElement('span');
            white.classList.add('circle');
            white.style.top = yInside + 'px';
            white.style.left = xInside + 'px';
            this.appendChild(white);
        })
    })

    
setInterval(() => {
    buttons.forEach(btn => {
        btn.removeChild();
    })
}, 50);