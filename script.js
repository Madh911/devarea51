document.addEventListener("DOMContentLoaded", function() {
    const passwordForm = document.getElementById("password-form");
    const passwordInput = document.getElementById("password");
    const message = document.getElementById("message");
    const secretContent = document.getElementById("secret-content");
    const copyButton = document.getElementById("copy-button");

    passwordForm.addEventListener("submit", function(event) {
        event.preventDefault();
        const enteredPassword = passwordInput.value.trim();

        if (enteredPassword === "jp") {
            secretContent.classList.remove("hidden");
            passwordForm.style.display = "none";
        } else {
            message.textContent = "Incorrect password. Please try again.";
            passwordInput.value = "";
        }
    });

    copyButton.addEventListener("click", function() {
        const codeToCopy = document.querySelector("pre");
        const tempInput = document.createElement("input");
        tempInput.value = codeToCopy.textContent;
        document.body.appendChild(tempInput);
        tempInput.select();
        document.execCommand("copy");
        document.body.removeChild(tempInput);
        alert("Code copied to clipboard!");
    });
});
