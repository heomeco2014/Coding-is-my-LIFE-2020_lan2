const joke = document.querySelector('.joke');
const jokeID = document.querySelector('#joke');
const anotherJokeBtn = document.querySelector('.btn');

generateJoke()
anotherJokeBtn.addEventListener('click', () => {
    generateJoke()
});

// This one is not syncronus
// function generateJoke() {
//     const config = {
//         headers: {
//             'Accept': 'application/json'
//         }
//     }
//     fetch('https://icanhazdadjoke.com/', config)
//         .then(res => res.json())
//         .then(data => {
//             joke.innerHTML = data.joke;
//         });

// }

async function generateJoke() {
    const config = {
        headers: {
            'Accept': 'application/json'
        }
    }
    const res = await fetch('https://icanhazdadjoke.com/', config);

    const data = await res.json()
    joke.innerHTML = data.joke;

}