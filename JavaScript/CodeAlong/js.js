const p1Button = document.querySelector('#p1Button');
const p2Button = document.querySelector('#p2Button');
const resetButton = document.querySelector('#reset');
const winningScoreSelect = document.querySelector('#playto');

let p1Display = document.querySelector('#p1Display');
let p2Display = document.querySelector('#p2Display');

let p1Score = 0;
let p2Score = 0;
let winningScore = 5;
let isGameOver = false;


p1Button.addEventListener('click', () => {
    if (!isGameOver) {
        p1Score++;
        if (p1Score === winningScore) {
            isGameOver = true;
            p1Display.classList.add('winner');
            p2Display.classList.add('loser');
        }
        p1Display.textContent = p1Score;
    }
})

p2Button.addEventListener('click', () => {
    if (!isGameOver) {
        p2Score++;
        if (p2Score === winningScore) {
            isGameOver = true;
            p1Display.classList.add('loser');
            p2Display.classList.add('winner');
        }
        p2Display.textContent = p2Score;
    }
})

winningScoreSelect.addEventListener('change', function () {
    if (winningScore > parseInt(this.value)) {
        reset();
    }
    winningScore = parseInt(this.value);
    isGameOver = false;
})

resetButton.addEventListener('click', reset)

function reset() {
    isGameOver = false;
    p1Score = 0;
    p2Score = 0;
    p1Display.textContent = p1Score;
    p2Display.textContent = p2Score;
    p1Display.classList.remove('loser', 'winner');
    p2Display.classList.remove('loser', 'winner');
}