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
