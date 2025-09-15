const API = "http://localhost:8080"; // C++ backend server

function createUser() {
    let name = document.getElementById("name").value;
    let email = document.getElementById("email").value;

    fetch(API + "/createUser", {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify({ name, email })
    })
    .then(res => res.json())
    .then(data => {
        document.getElementById("createResult").innerText = data.status;
    });
}

function getUsers() {
    fetch(API + "/getUsers")
    .then(res => res.json())
    .then(data => {
        let list = document.getElementById("userList");
        list.innerHTML = "";
        data.users.forEach(u => {
            let li = document.createElement("li");
            li.innerText = u.name;
            list.appendChild(li);
        });
    });
}

function sendMessage() {
    let sender = document.getElementById("sender").value;
    let receiver = document.getElementById("receiver").value;
    let content = document.getElementById("message").value;

    fetch(API + "/sendMessage", {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify({ sender, receiver, content })
    })
    .then(res => res.json())
    .then(data => {
        document.getElementById("msgResult").innerText = data.status;
    });
}

function getMessages() {
    fetch(API + "/getMessages")
    .then(res => res.json())
    .then(data => {
        let list = document.getElementById("msgList");
        list.innerHTML = "";
        data.messages.forEach(m => {
            let li = document.createElement("li");
            li.innerText = `${m.sender} -> ${m.receiver}: ${m.content}`;
            list.appendChild(li);
        });
    });
}

