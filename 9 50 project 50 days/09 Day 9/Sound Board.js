const sounds = ['applause', 'boo', 'gasp', 'tada', 'victory', 'wrong'];

sounds.forEach((sound) => {
    const btn = document.createElement('button');
    btn.classList.add('btn');

    btn.addEventListener('click', () => {
        // Stop other playing songs
        
        sounds.forEach((sound) => {
            document.querySelector(`#${sound}`).pause();
        })

        document.querySelector(`#${sound}`).play();
    })

    btn.innerText = sound;
    document.querySelector('#buttons').appendChild(btn);
})