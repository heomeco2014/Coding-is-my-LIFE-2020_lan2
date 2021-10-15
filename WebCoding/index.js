// fetch('https://api.cryptonator.com/api/ticker/btc-usd')
//     .then(res => {
//         console.log("response, waiting to parse", res);
//         return res.json();
//     })
//     .then(data => {
//         console.log("Data parse");
//         console.log(data.ticker.price);
//     })
//     .catch(e => {
//         console.log("OH NO, Error", e);
//     })

const fetchBTCPrice = async () => {
    try{
        const res = await fetch('https://api.cryptonator.com/api/ticker/btc-usd')
        const data = await res.json()
        console.log(data.ticker.price)
    }
 
   catch(e){
       console.log("Something went wrong,",e);
   }
}
