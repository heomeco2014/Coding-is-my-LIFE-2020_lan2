const toasts = document.querySelector('#toasts');
const toast = document.querySelectorAll('.toast');

const button = document.querySelector('.btn');
const messages = [
    'Message first',
    'Message two',
    'Message three',
    'Message four',
    'Message five'
]

const types = [
    'info',
    'success',
    'error'
]
button.addEventListener('click', (e) => {
    showNotif();
})

function showNotif(message = null, type = null) {
    const notif = document.createElement('div');
    notif.classList.add('toast');
    notif.classList.add(type ? type : getRandomType())
    notif.innerText = message ? message : getRandomMessage();
    toasts.appendChild(notif);

    setTimeout(() => {

        notif.remove()
    }, 2000);
}

function getRandomMessage() {
    return messages[Math.floor(Math.random() * (messages.length))];
}

function getRandomType() {
    return types[Math.floor(Math.random() * (types.length))];
}