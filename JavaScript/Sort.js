function bubbleSort(a) {
    for (let i = 0; i < a.length; ++i) {
        for (let j = 0; j < a.length - 1; ++j) {
            if (a[i] < a[j])[a[i], a[j]] = [a[j], a[i]];
        }
    }
    return a;
}
d
let arr = [2, 1, 0, 5, 9];
// console.log(bubbleSort(arr));
    
const bubbleSort2 = (array) => {
    let c = 0;
    for (let i = 0; i < arr.length; ++i) {
        for (let j = 0; j < arr.length - 1; j++) {
            if (arr[i] > arr[j]) {
                [arr[i], arr[j]] = [arr[j], arr[i]];
                console.log(c++, arr);
            }
        }
        for (let i = 0; i < arr2.length; i++) {
            for (let index = 0; index < array.length; index++) {
                const element = array[index];
                
            }
        }
    }
    return array;
}
const bubble2 =(array)=>{
    for(let i = 0; i < n; i++){
        if(i<=5)++i;
    }
}

const selectionSort = (array) => {
    let min_Id = -1;
    let c = 0;
    for (let i = 0; i < array.length - 1; i++) {
        min_Id = i;
        for (let j = i + 1; j < array.length; j++) {
            if (array[j] < array[min_Id]) {
                min_Id = j;
                // console.log(c++,"min is",array[min_Id], array);
            }
        }
        [array[min_Id], array[i]] = [array[i], array[min_Id]];
    }
    return array;
}
const sletionArray = [64, 25, 12, 22, 11];
// console.log(selectionSort(sletionArray));

