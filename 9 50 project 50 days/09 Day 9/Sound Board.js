const sounds = ['applause', 'boo', 'gasp', 'tada', 'victory', 'wrong'];

sounds.forEach((sound) => {
    const btn = document.createElement('button'); // he creates a button
    btn.classList.add('btn'); // add a btn class to style it
    btn.innerText = `${sound}`;

    const head = document.createElement('h1');
    head.classList.add('heading');
    head.innerText = 'Hi';
    document.querySelector('#buttons').appendChild(btn);

    btn.addEventListener('click', () => {
        // Stop other playing songs

        sounds.forEach((sound) => {
            const song = document.querySelector(`#${sound}`);
            song.pause();
            song.currentTime = 0;
            btn.appendChild(head);
        })
        document.querySelector(`#${sound}`).play();
    })
})