

var number = 5;
let line = "";

for(let i = 0; i < number; i++){
    for(let j = 0; j < i; j++){
        line = line + "*";
    }
    console.log(line);
    line = "";
}