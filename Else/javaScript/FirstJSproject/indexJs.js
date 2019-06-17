let a = 10;
let b = 20;

console.log(a, b);

function swapFunction (patameter1, parameter2) {
    let temp = a;
    a = b;
    b = temp;
}

swapFunction(a, b);
console.log (a, b);

// print all even numberst to 100


for (let i = 0; i < 100; i++){
    if (i % 2 == 1){
        console.log(i);
    }
}

