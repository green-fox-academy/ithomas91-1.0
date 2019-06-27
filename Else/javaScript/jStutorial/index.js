
var numOne = document.getElementById("numOne");
var numTwo = document.getElementById("numTwo");
var sum = document.getElementById("sum");


numOne.addEventListener("input", add);
numTwo.addEventListener("input", add);

function add(){
	var  one = parseFloat(numOne.value) || 0;
	var two = parseFloat(numTwo.value) || 0;
	sum.innerHTML = "your sum is:" +(one+two);
}
