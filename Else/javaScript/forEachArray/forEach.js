
var months = ['jan', 'febr', 'march', 'apr', 'may' ];
var copy =[];

for(let i = 0; i < months.length; i++){
    copy.push(months[i]);
}

console.log(copy);

var numbers = [1, 2, 3, 4, 5, 6];
var numberCopy = [];

numbers.forEach(function(number){
    numberCopy.push(number);
})

console.log(numberCopy);