// setTimeout(() => {
//     document.body.style.backgroundColor = 'red';
//     setTimeout(() => {
//         document.body.style.backgroundColor = 'green';
//         setTimeout(() => {
//             document.body.style.backgroundColor = 'blue';
//             setTimeout(() => {
//                 document.body.style.backgroundColor = 'orange';
//             }, 1000);
//         }, 1000);
//     }, 1000);
// }, 1000);

// const delayedColorChange = (newColor, delay, doNext) => {
//     setTimeout(() => {
//         document.body.style.backgroundColor = newColor;
//         doNext && doNext();
//     }, delay);
// }

// delayedColorChange('red', 1000, () => {
//     delayedColorChange('green', 1000, () => {
//         delayedColorChange('blue', 1000);
//     });
// });
// delayedColorChange('green',1000);
// delayedColorChange('blue',1000);
// const fakeRequestCallBack = (url, success, failure) => {
//     const delay = Math.floor(Math.random() * 4500) + 500;
//     setTimeout(() => {
//         if (delay > 4000) {
//             failure("Connection timeout :(");
//         } else {
//             success(`Here is your fake data from ${url}`);
//         }
//     }, delay);
// }
// const fakeRequestPromise = (url) => {
//     return new Promise((resolve, reject) => {
//         const delay = (Math.floor(Math.random() * 4500)) + 500;
//         setTimeout(() => {
//             if (delay > 4000) {
//                 reject("Connection timeout :(")
//             } else {
//                 resolve(`Here is your fake data from ${url}`);
//             }
//         }, delay);
//     })
// }

// fakeRequestCallBack("books.com", function () {
//     console.log('It worked');
// }, () => {
//     console.log("Error");
// })

// const request = fakeRequestPromise('yelp.com/api/coffe')
// request
//     .then(() => {
//         console.log("It worked");
//         fakeRequestPromise('yelp2.com/api/coffe/page2')
//             .then((result) => {
//                 console.log('Yelp2 worked');
//             }).catch((err) => {
//                 console.log('Yelp 2 didn"t work');
//             });
//     })
//     .catch(() => {
//         console.log("Rejected");
//     });

// fakeRequestPromise('yelp.com/api/coffe/page1')
//     .then((data) => {
//         console.log("It worked !! page 1");
//         console.log(data);
//         return fakeRequestPromise("yelp.com/api/coffee/page2");
//     })
//     .then((data) => {
//         console.log("It worked the 2nd times (page 2)");
//         console.log(data);
//         return fakeRequestPromise("yelp.com/api/coffee/page3");
//     })
//     .then((data) => {
//         console.log("it worked the 3st time");
//         console.log(data);
//     })
//     .catch((data) => {
//         console.log(data); 
//         console.log("Oh no, failed");
//     })

// const fakeRequest = (url) => {
//     return new Promise((resolve, reject) => {
//         setTimeout(() => {
//             resolve();
//         }, 1000);
//     })
// }

// const delayedColorChange = (color, delay) => {
//     return new Promise((resolve, reject) => {
//         setTimeout(() => {
//             document.body.style.backgroundColor = color;
//             resolve();
//         }, delay);
//     });
// }

// delayedColorChange('red', 1000)
// .then(() => delayedColorChange('red', 500))
// .then(() => delayedColorChange('orange', 500))
// .then(() => delayedColorChange('yellow', 500))
// .then(() => delayedColorChange('blue', 500))
// .then(() => delayedColorChange('green', 500))
// .then(() => delayedColorChange('purple', 500))

// // async functions

// async function hello() {

// }

// const sing = async () => {
//     return "lalalala";
// }

// // sing().then((data) => {
// //     console.log("Problems resolved with:", data);
// // })


// const login = async (user, password) => {
//     if (!user || !password) throw 'missing credentials'
//     if (password === '123') return 'welcome';
//     throw 'Invalid password';
// }

// login('minh','12')
//     .then(msg => {
//         console.log("logged in");
//         console.log(msg);
//     })
//     .catch((err) => {
//         console.log(err);
//     })

// async function makeTwoRequest(){
//     try{
//         let data1 = await fakeRequest('page1');
//         console.log(data1);
//         let data2 = await fakeRequest('page2');
//         console.log(data2);
//     }catch(e){
//         console.log(e);
//     }
// }