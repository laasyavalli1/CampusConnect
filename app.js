// Skill Sharing messaging (dummy, for UI)
const messageForm = document.querySelector("form");
messageForm.addEventListener("submit", function(e) {
  e.preventDefault();
  const messageBox = document.getElementById("message");
  if(messageBox.value.trim() !== "") {
    const newMessage = document.createElement("div");
    newMessage.classList.add("card");
    newMessage.innerHTML = `<p><strong>You:</strong></p><p><em>${messageBox.value}</em></p>`;
    messageForm.parentNode.insertBefore(newMessage, messageForm);
    messageBox.value = "";
  }
});
