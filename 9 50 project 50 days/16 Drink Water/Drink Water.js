const smallCups = document.querySelectorAll('.cup-small');
const liters = document.querySelector('#liters');
const percentage = document.querySelector('.percentage');
const remained = document.querySelector('#remained');


setInterval(() => {
  updateBigCups();
}, 1);
smallCups.forEach((cup, idx) => {
  cup.addEventListener('click', () => {
    highLightCups(idx);
  })
})

function highLightCups(idx) {
  if (smallCups[idx].classList.contains('full') && !smallCups[idx].nextElementSibling.classList.contains('full')) {
    idx--;
  }

  smallCups.forEach((cup, idx2) => {
    if (idx2 <= idx) {
      cup.classList.add('full');
    } else {
      cup.classList.remove('full');
    }
  })
}

function updateBigCups() {
  const fullCup = document.querySelectorAll('.cup-small.full').length;
  const totalCups = smallCups.length;
  if (fullCup === 0) {
    percentage.style.visibility = 'hidden';
    percentage.style.height = 0;
  } else {
    percentage.style.visibility = 'visible';
    percentage.style.height = `${(fullCup / totalCups) * 100 }%`;
    percentage.innerText = `${(fullCup / totalCups) * 100 }%`;
    if (fullCup / totalCups === 1) {
      remained.style.display = 'none';
    } else {
      remained.style.display = 'block';
      liters.innerText = `${2-(250*fullCup / 1000)}L`;
    }
  }
}