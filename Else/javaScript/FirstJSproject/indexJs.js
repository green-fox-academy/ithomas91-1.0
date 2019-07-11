function clickToRegister() {
    document.getElementById("register-box").style.display = "block";
}

function clickToLogin() {
    document.getElementById("login-box").style.display = "block";
}

let value;

function analyseClick(id) {
    switch (id) {
        case "login":
            clickToLogin();
            break;
        case "register":
            clickToRegister();
            break;
        default:
            alert("Try again!");
            break;
    }

}

let userData = {
    fullname: [],
    username: [],
    email: [],
    password: [],
    confirmation: []
};
let users = [];



function getUserData() {
    let nameFull = document.getElementById("name").value;
    let userName = document.getElementById("username").value;
    let email = document.getElementById("e-mail").value;
    let passWord = document.getElementById("password").value;
    let passwordConfirmation = document.getElementById("confirmpassword").value;

    userData.fullname.push(nameFull);
    userData.username.push(userName);
}

users.push(userData);


let register = document.getElementById("register")
let login = document.getElementById("login");

register.addEventListener("click", boxLink);
login.addEventListener("click", boxLink);

function boxLink() {
    let boxId = this.attributes["egister-box"].value;
    let box = document.getElementById(boxId);
    if (box.className === "hide") {
        box.className = "";
    } else {
        box.className = "hide";
    }
}

$(document).ready(function() {
    $('#register').on('click', function() {
        $('#register-box').toggle(500);
        $('#login-box').hide();
    });
});

$(document).ready(function() {
    $('#login').on('click', function() {
        $('#login-box').toggle(500);
        $('#register-box').hide();
    });
});