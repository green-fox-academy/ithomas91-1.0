
var months = ['jan', 'febr', 'march', 'apr', 'may' ];

months.splice(5, 0, 'june');

console.log(months);

months.splice(0, 1);

console.log(months);

months.splice(0, 1, 'jan');
console.log(months);
