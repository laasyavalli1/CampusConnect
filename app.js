// app.js - Skill Sharing Hub Messaging & Interactivity

document.addEventListener("DOMContentLoaded", () => {
    const messageForm = document.querySelector("form");
    const messageInput = document.getElementById("message");

    messageForm.addEventListener("submit", (e) => {
        e.preventDefault();

        const msgText = messageInput.value.trim();
        if (!msgText) return;

        // Create new message card
        const newCard = document.createElement("div");
        newCard.classList.add("card");
        newCard.innerHTML = `<p><strong>You:</strong></p><p><em>"${msgText}"</em></p>`;
        messageForm.parentElement.insertBefore(newCard, messageForm);

        messageInput.value = "";
        messageInput.focus();
    });

    // Hover effect for all cards
    const cards = document.querySelectorAll(".card");
    cards.forEach(card => {
        card.addEventListener("mouseenter", () => {
            card.style.transform = "scale(1.02)";
            card.style.transition = "transform 0.3s ease";
        });
        card.addEventListener("mouseleave", () => {
            card.style.transform = "scale(1)";
        });
    });
});
