

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

let userData = {};
let users = [];


function getUserData() {
    userData["Full Name"] = document.getElementById("name").value;
    //userData.push(userFullName);
    userData["username"] =  document.getElementById("username").value;
    //userData.push(username);
    userData["emailAdress"] =  document.getElementById("e-mail").value;
    //userData.push(emailAdress);
    userData["password"] =  document.getElementById("password").value;
    //userData.push(password);
    userData["confirmPassword"] =  document.getElementById("confirmpassword").value;
    //userData.push(confirmPassword);
    if(userData["Full Name"] != null || userData["username"] != null || 
    userData["e-mail"] != null || userData["password"] != null
    || userData["confirmPassword"] != null) {
        users.push(userData);
    } else {
        alert("Empty field!");
    }
}
