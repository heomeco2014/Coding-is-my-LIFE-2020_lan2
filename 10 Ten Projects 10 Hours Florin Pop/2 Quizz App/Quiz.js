const quizData = [{
    question: 'How ols is Minh',
    a: '1',
    b: '11',
    c: '12',
    d: '21',
    correct: 'a'
}, {
    question: "What's my fucking Name ?",
    a: 'Minh',
    b: 'Nid',
    c: 'TooNy',
    d: 'Not right now',
    correct: 'a'
}, {
    question: 'What is the matter with Ross ?',
    a: 'He dirvorce too many times',
    b: 'He plays with monkeys',
    c: 'He is not good with Kids',
    d: 'About me ?',
    correct: 'a'
}, {
    question: "What's the best programing language to learn",
    a: 'Java',
    b: 'Python',
    c: 'JavaScript',
    d: 'C++',
    correct: 'c'
}, {
    question: 'What is your age if you plus it with age of Tuyen ?',
    a: 'I dont even know',
    b: 'What is your execuses ?',
    c: 'I dont have a thing',
    d: 'Who cares anyway ?',
    correct: 'b'
}];


const quiz = document.getElementById("quiz");
const answerEls = document.querySelectorAll(".answer");
const questionEl = document.querySelector('#question');
const a_text = document.querySelector('#a_text');
const b_text = document.querySelector('#b_text');
const c_text = document.querySelector('#c_text');
const d_text = document.querySelector('#d_text');
const submit = document.querySelector('.btn');
const prev = document.querySelector('.prev');

let currentQuiz = 0;
let score = 0;

loadQuiz();

function loadQuiz() {
    deselectAnswers();
    const currentQuizData = quizData[currentQuiz];

    questionEl.innerText = currentQuizData.question;
    a_text.innerText = currentQuizData.a;
    b_text.innerText = currentQuizData.b;
    c_text.innerText = currentQuizData.c;
    d_text.innerText = currentQuizData.d;
}

submit.addEventListener('click', () => {
    // check to see the answer
    const answer = getSelected();

    if (answer) {
        if (answer === quizData[currentQuiz].correct) {
            score++;
        }

        currentQuiz++;
        if (currentQuiz < quizData.length) {
            loadQuiz();
        } else {
            quiz.innerHTML = `
                <h2>You answered correctly at ${score}/${quizData.length} questions.</h2>
                
                <button class="btn" onclick="location.reload()">Reload</button>
            `;
        }
    }

});

prev.addEventListener('click', () => {
    currentQuiz--;
    if (currentQuiz < 0) {
        currentQuiz = 0;
    }
    loadQuiz();
})

function getSelected() {

    let answer = undefined;

    answerEls.forEach((answerEl) => {
        if (answerEl.checked) {
            answer = answerEl.id;
        }
    });

    return answer;
}

function deselectAnswers() {
    answerEls.forEach((answerEl) => {
        answerEl.checked = false;
    });
}