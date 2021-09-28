const data_target = document.querySelectorAll(".number");

data_target.forEach(counter => {
    counter.innerText = '0';

    const updateCounter = () => {
        const target = +counter.getAttribute('data-target');
        const c = +counter.innerText
        console.log(typeof target, target);
        const increment = target / 200;
        if (c < target) {
            counter.innerText = `${Math.ceil(c + increment)}`
            setTimeout(updateCounter, 100);
        } else {
            counter.innerText = target;
        }
    }
    updateCounter();
})