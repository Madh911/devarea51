document.addEventListener("DOMContentLoaded", function() {
    const passwordForm = document.getElementById("password-form");
    const passwordInput = document.getElementById("password");
    const message = document.getElementById("message");
    const nextPage = document.getElementById("next-page");

    passwordForm.addEventListener("submit", function(event) {
        event.preventDefault();
        const enteredPassword = passwordInput.value.trim();

      
        if (enteredPassword === "youknow") {
            // Show the next page and hide the password entry page
            nextPage.classList.remove("hidden");
            passwordForm.style.display = "none";
        } else {
          
            message.textContent = "Incorrect password. Please try again.";
            passwordInput.value = "";
        }
    });
});
