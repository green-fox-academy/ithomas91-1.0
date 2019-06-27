

function clickToRegister(){
    document.getElementById("register-box").style.display="block";
}

function clickToLogin(){
    document.getElementById("login-box").style.display = "block";
}

let value;

function analyseClick(id){
    switch(id)
    {
        case "login" :
                clickToLogin();
                break;
        case "register" : 
                clickToRegister();
                break;
            default:
                alert("Try again!");
                break;
    }   

}
