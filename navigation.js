// Indoor map hotspots
const hotspots = [
  {
    name: "Main Library",
    x: 300,
    y: 150,
    photo1: "library1.jpg",
    photo2: "library2.jpg",
    details: "The central library with a wide range of academic books."
  },
  {
    name: "CSE Department",
    x: 500,
    y: 220,
    photo1: "cse1.jpg",
    photo2: "cse2.jpg",
    details: "Computer Science & Engineering Department."
  },
  {
    name: "Hostel A",
    x: 200,
    y: 400,
    photo1: "hostelA1.jpg",
    photo2: "hostelA2.jpg",
    details: "Student hostel with all facilities."
  }
];

const map = document.getElementById("map");
const modal = document.getElementById("hotspotModal");
const modalClose = document.getElementById("modalClose");
const modalTitle = document.getElementById("modalTitle");
const modalDetails = document.getElementById("modalDetails");
const photo1 = document.getElementById("photo1");
const photo2 = document.getElementById("photo2");

hotspots.forEach(hotspot => {
  const el = document.createElement("div");
  el.style.position = "absolute";
  el.style.width = "20px";
  el.style.height = "20px";
  el.style.backgroundColor = "#00bcd4";
  el.style.borderRadius = "50%";
  el.style.cursor = "pointer";
  el.style.left = hotspot.x + "px";
  el.style.top = hotspot.y + "px";
  el.title = hotspot.name;
  map.appendChild(el);

  el.addEventListener("click", () => {
    modalTitle.textContent = hotspot.name;
    modalDetails.textContent = hotspot.details;
    photo1.src = hotspot.photo1;
    photo2.src = hotspot.photo2;
    modal.classList.remove("hidden");
  });
});

modalClose.addEventListener("click", () => {
  modal.classList.add("hidden");
});

window.addEventListener("click", e => {
  if (e.target === modal) {
    modal.classList.add("hidden");
  }
});
