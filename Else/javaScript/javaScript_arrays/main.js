'use strict';
// - Create (dynamically*) a two dimensional list
//   with the following matrix**. Use a loop!
//
//   0 0 0 1
//   0 0 1 0
//   0 1 0 0
//   1 0 0 0
//
// - Print this two dimensional list to the console
//
// * size should depend on a variable
// ** Relax, a matrix is just like an array

let size = 5;

for (let i = 0; i < size; i++) {
    for (let j = 0; j < size; j++){
        if(i==j){
            console.log("1")
        } else{
            console.log("0")
        }
    }
}

// - Create a variable named `numbers` with the following content: `[4, 5, 6, 7]`
// - Log each the element of `numbers` to the console*
// *hint: use a loop, console.log(numbers) won't cut it
// - bonus for using the correct built in array method


let numbers = [4, 5, 6, 7];
for (let k = 0; k < numbers.length; k++) {
    console.log(numbers[k]);
}

// - Create an array named `s` with the following content: `[1, 2, 3, 8, 5, 6]`
// - Change the 8 to 4 with the `.map` method 
// - Print the fourth element as a test

let s = [1, 2, 3, 8, 5, 6];

for (let m = 0; m < s.length; m++) {
    if(s[m]=== 8){
        s[m]=4;
    }    
}
console.log(s);

// - Create a variable named `animals`
//   with the following content: `['koal', 'pand', 'zebr']`
// - Add all elements an `"a"` at the end
// - try to use built in functions instead of loops

let animals = ['koal', 'pand', 'zebr'];
for (let n = 0; n < animals.length; n++) {
    animals[n]= animals[n] + 'a';    
}

console.log(animals);

// - Create a variable named `aj`
//   with the following content: `[3, 4, 5, 6, 7]`
// - Reverse the order of the elements in `aj`
// 		- do it with the built in method
//		- do it with creating a new temp array and a loop
// - Print the elements of the reversed `aj`


let aj = [3, 4, 5, 6, 7];
let tempArray = [];
for (let o = aj.length; o < aj.length; o) {
    
}