const tagsEl = document.querySelector('#tags');
const textArea = document.querySelector('#textarea');
// Doi background khi focus vao
textArea.addEventListener('focus', (e) => {
    e.target.style.background = 'pink';
})
textArea.addEventListener('blur', (e) => {
    e.target.style.background = 'white';
})

textArea.focus();

// Get input from keyboard
textArea.addEventListener('keyup', (e) => {
    createTags(e.target.value);
    if (e.key === 'Enter') {
        setTimeout(() => {
            e.target.value = '';
        }, 90)
        randomSelector();
    }
})
var i = 0;

textArea.addEventListener('keyup', (e) => {
    createTags(e.target.value);
})

// function createTags(input) {
//     const newBoxes = input.split(',').filter(box => box.trim() !== '').map(box => box.trim());

//     tagsEl.innerHTML = '';
//     newBoxes.forEach(box => {
//         const newChoice = document.createElement('span');
//         newChoice.classList.add('tag');
//         newChoice.innerText = box;
//         tagsEl.appendChild(newChoice);
//     })
// }

function createTags(input) {
    const tags = input.split(',').filter(tag => tag.trim() !== '').map(tag => tag.trim());
    tagsEl.innerHTML = '';
    tags.forEach(tag => {
        const tagEl = document.createElement('span');
        tagEl.classList.add('tag');
        tagEl.innerText = tag;
        tagsEl.appendChild(tagEl);
    })
}

function randomSelector() {
    const times = 30;

    const interval = setInterval(() => {
        const randomTag = pickRandomTag();

        highlightTag(randomTag);

        setTimeout(() => {
            unhighlightTag(randomTag);
        }, 100);
    }, 100);

    setTimeout(() => {
        clearInterval(interval)

        setTimeout(() => {
            const randomTag = pickRandomTag()

            highlightTag(randomTag)
        }, 100)

    }, times * 100)
    i = 0;
}


function pickRandomTag() {
    const tags = document.querySelectorAll('.tag');
    // return tags[i++];
    return tags[Math.floor(Math.random() * tags.length)];
}

function highlightTag(tag) {
    tag.classList.add('highlight');
}

function unhighlightTag(tag) {
    tag.classList.remove('highlight');
}