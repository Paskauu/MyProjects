const ShowPassword = (LoginPassword,LoginIcon) => {
    const PassowordInput = document.getElementById(LoginPassword),
          PasswordIcon = document.getElementById(LoginIcon)

    PasswordIcon.addEventListener('click',() => {
        if(PassowordInput.type === 'password'){
            PassowordInput.type = 'text'

            PasswordIcon.src = 'Images/HidePasswordIcon.png'
        } else {
            PassowordInput.type = 'password'

            PasswordIcon.src = 'Images/ShowPasswordIcon.png'
        }
    })
};

var EmailInp = document.getElementById('EmailInp');
var EmailErro = document.getElementById('EmailError');
var PasswordInp = document.getElementById('PasswordInp');
var PasswordErro = document.getElementById('PasswordError');
var PasswordIcon = document.getElementById('PasswordIcon');
var ErrorMsg = document.getElementById('ErrorMsg');
var LoginMsg = document.getElementById('LoginMsg');
var ForgortPasswordMsgSucceed = document.getElementById('ForgotPasswordSucceed')

function ValidEmail() {
    let Email = EmailInp.value.trim()

    if(!EmailInp.value.match(/^[A-Za-z\._\-0-9]*[@][A-Za-z]*[\.][a-z]{2,4}$/) || Email.length == 0){
        EmailErro.innerHTML = "Enter a valid email";
        EmailInp.classList.add("LoginInfoInpError")
    } else { 
        EmailErro.innerHTML = ""
        EmailInp.classList.remove("LoginInfoInpError")
    }
    
};

function ValidPassword() {
    let Password = PasswordInp.value.trim()

    if(Password.length < 6 || Password.length == 0){
        PasswordErro.innerHTML = "Enter a valid password.";
        PasswordInp.classList.add("LoginInfoInpError");
    } else {
        PasswordErro.innerHTML = "";
        PasswordInp.classList.remove("LoginInfoInpError");
    }
};

function Login() {
    let Email = EmailInp.value.trim();
    let Password = PasswordInp.value.trim()

    if((!EmailInp.value.match(/^[A-Za-z\._\-0-9]*[@][A-Za-z]*[\.][a-z]{2,4}$/) || Email.length == 0) || (Password.length < 6 || Password.length == 0)){        
        ErrorMsg.classList.add("LoginInfoPasswordErrorMsgPopUp");
        LoginMsg.classList.remove("LoginInfoLoginSucceedMsgPopUp")
    } else {
        ErrorMsg.classList.remove("LoginInfoPasswordErrorMsgPopUp");
        LoginMsg.classList.add("LoginInfoLoginSucceedMsgPopUp")
    }
};

function CloseErrorMsg() {
    ErrorMsg.classList.remove("LoginInfoPasswordErrorMsgPopUp");
    LoginMsg.classList.remove("LoginInfoLoginSucceedMsgPopUp")
};

function ForgotPasswordSucceed() {
    let Email = EmailInp.value.trim();

    if((EmailInp.value.match(/^[A-Za-z\._\-0-9]*[@][A-Za-z]*[\.][a-z]{2,4}$/) || Email.length != 0)){        
        ForgortPasswordMsgSucceed.classList.add("ForgotPasswordRequestSucceedPopUp")
    } else {
        ForgortPasswordMsgSucceed.classList.remove("ForgotPasswordRequestSucceedPopUp")
    }
};

function CloseForgotPasswordSucceed() {
    ForgortPasswordMsgSucceed.classList.remove("ForgotPasswordRequestSucceedPopUp")
}


ShowPassword('PasswordInp','PasswordIcon')