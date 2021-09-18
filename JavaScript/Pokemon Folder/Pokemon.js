// https://github.com/PokeAPI/sprites/blob/master/sprites/pokemon/1.png 

// Key word for this: lias shorthand javascript
$ = document.querySelector.bind(document)
$$ = document.querySelectorAll.bind(document)
cout = console.log.bind(document);

const container = document.querySelector('#container');
const baseURL = 'https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/back/';

function createPage() {
    for (let i = 1; i <= 151; i++) {
        const pokemon = document.createElement('div');
        pokemon.classList.add('pokemon');
        const label = document.createElement('span');
        label.innerText = `#${i}`;
        const newImg = document.createElement('img');
        newImg.src = `${baseURL}${i}.png`;

        pokemon.appendChild(newImg);
        pokemon.appendChild(label);
        container.appendChild(pokemon);
    }
}
const h1 = $('h1');
h1.onclick = createPage;

const btn3 = $('#v3');
btn3.addEventListener('mouseover', function () {
    alert("Clicked");
})

function twist() {
    console.log("twsist");
}

function shout() {
    console.log("AAAAAAAAAAAAAAHHHHHHHHH");
}


const tasButton = $('#tas');

tasButton.addEventListener('click', shout, {
    once: true
});
tasButton.addEventListener('click', twist);