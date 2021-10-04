const API_URL = 'https://api.themoviedb.org/3/discover/movie?sort_by=popularity.desc&api_key=5353d48f7da7212950f0cdc1a9ec6313&page=1'

const images = 'https://image.tmdb.org/t/p/w500';

const Search_URL = 'https://api.themoviedb.org/3/search/movie?api_key=5353d48f7da7212950f0cdc1a9ec6313&query="'

const main = document.querySelector('.main');
const form = document.querySelector('#form');
const search = document.querySelector('#search');

getMovies(API_URL);

async function getMovies(url) {
  const res = await fetch(url);
  const data = await res.json();

  showMovies(data.results);
}

function showMovies(movies) {
  main.innerHTML = '';

  movies.forEach((movie) => {
    const {
      title,
      poster_path,
      vote_average,
      overview
    } = movie;

    const movieEl = document.createElement('div');
    movieEl.classList.add('movie');

    movieEl.innerHTML =
      `
    <img src="${images + poster_path}" alt="${title}">
<div class="movie-info">
    <div class="movie--title">${title}</div>
    <span class="movie--rating">9.8</span>
</div>
<div class="overeview">
    <h3>Overeview</h3>
    Lorem ipsum dolor, sit amet consectetur adipisicing elit. 

</div>`
    main.appendChild(movieEl);
  })
}

form.addEventListener('submit', (e) => {
  e.preventDefault();

  const searchTerm = search.value;

  if (searchTerm && searchTerm !== '') {
    getMovies(Search_URL + searchTerm);
    search.value = '';
  } else {
    window.location.reload();
  }
})