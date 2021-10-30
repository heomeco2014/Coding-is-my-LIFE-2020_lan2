const APIURL = 'https://api.github.com/users/'
const form = document.querySelector('#form');
const search = document.querySelector('#search');

async function getUserName(username) {
    try {
        const {data} = await axios(APIURL + username)
        console.log(data)
    } catch (error) {
        console.log(error);
    }
}

form.addEventListener('submit',(e)=>{
    e.preventDefault()

    const user = e.target.value
    if(user){
        getUserName(user);
        search.value = '';
    }
})