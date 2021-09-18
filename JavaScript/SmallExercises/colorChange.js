$ = document.querySelector.bind(document);
const btn = $('#btn');
const h1 = $('h1');
const clickMe = $('input');
const tweetForm = document.querySelector('#tweetForm');

function changeColor() {
    const r = Math.floor(Math.random() * 255);
    const g = Math.floor(Math.random() * 255);
    const b = Math.floor(Math.random() * 255);
    return `rgba(${r}, ${g}, ${b})`;
}
btn.addEventListener('click', function () {
    document.body.style.backgroundColor = changeColor();
    h1.innerText = changeColor();
})

clickMe.addEventListener('keydown', function (e) {
    console.log(e.code);
})
clickMe.addEventListener('keyup', function () {
    console.log('KeyUp');
})

const tweetContainer = document.querySelector('#tweetForm');
tweetForm.addEventListener('submit', function (e) {
    e.preventDefault();
    e.stopImmediatePropagation();
    let usernameInput = tweetForm.elements.username;
    let tweetInput = tweetForm.elements.comment;
    addTweet(usernameInput.value, tweetInput.value);
    usernameInput.value = '';
    tweetInput.value = '';
})

const addTweet = (username, tweet) => {

    const newTweet = document.createElement('li');
    const bTag = document.createElement('b');
    bTag.append(username);
    newTweet.append(bTag);
    newTweet.append(`-${tweet}`);

    tweetContainer.append(newTweet);

}

// const lis = document.querySelectorAll('li')
// for (let li of lis) {
//     li.addEventListener('click', () => {
//         li.remove();
//     })
// }
const a = document.querySelector('#tweets');
a.addEventListener('click', (e) => {
    e.target.nodeName ==='LI' && e.target.remove();
})