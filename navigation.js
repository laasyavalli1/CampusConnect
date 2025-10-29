// ======= CAMPUS MAP ZONE + NODE SYSTEM =======

// Map and modal references
const map = document.getElementById('map');
const modal = document.getElementById('hotspotModal');
const modalClose = document.getElementById('modalClose');
const modalTitle = document.getElementById('modalTitle');
const modalDetails = document.getElementById('modalDetails');
const photo1 = document.getElementById('photo1');
const photo2 = document.getElementById('photo2');

// ----- Level 1: Zones -----
let zones = {
  "Sports Zone": { x: 10, y: 60 },
  "Academic Zone": { x: 40, y: 40 },
  "Hostel Zone": { x: 70, y: 55 },
  "Quarters Zone": { x: 85, y: 70 },
  "Shopping Zone": { x: 55, y: 80 },
};

// ----- Level 2: Nodes inside zones -----
let zoneNodes = {
  "Sports Zone": {
    "Indoor Stadium": { x: 15, y: 55, img1: "indoor1.jpg", img2: "indoor2.jpg", details: "Indoor sports complex" },
    "NSO Ground": { x: 20, y: 65, img1: "ground1.jpg", img2: "ground2.jpg", details: "Athletics and football ground" },
    "Swimming Pool": { x: 25, y: 60, img1: "pool1.jpg", img2: "pool2.jpg", details: "Olympic-size swimming pool" },
  },
  "Academic Zone": {
    "CSE Department": { x: 45, y: 40, img1: "cse1.jpg", img2: "cse2.jpg", details: "Computer Science Department" },
    "EEE Department": { x: 50, y: 45, img1: "eee1.jpg", img2: "eee2.jpg", details: "Electrical and Electronics" },
    "Central Library": { x: 40, y: 50, img1: "lib1.jpg", img2: "lib2.jpg", details: "Central library with study halls" },
  },
  "Hostel Zone": {
    "Ruby Hostel": { x: 70, y: 60, img1: "ruby1.jpg", img2: "ruby2.jpg", details: "Girls Hostel Ruby" },
    "Emerald Hostel": { x: 75, y: 65, img1: "emerald1.jpg", img2: "emerald2.jpg", details: "Boys Hostel Emerald" },
    "Sapphire Hostel": { x: 68, y: 70, img1: "sapp1.jpg", img2: "sapp2.jpg", details: "Sapphire Hostel for 2nd years" },
  },
  "Quarters Zone": {
    "Faculty Quarters": { x: 80, y: 75, img1: "fq1.jpg", img2: "fq2.jpg", details: "Faculty Residential Area" },
    "Staff Quarters": { x: 85, y: 78, img1: "sq1.jpg", img2: "sq2.jpg", details: "Staff Quarters" },
  },
  "Shopping Zone": {
    "Market": { x: 60, y: 82, img1: "market1.jpg", img2: "market2.jpg", details: "Campus Market" },
    "Juice Shop": { x: 58, y: 85, img1: "juice1.jpg", img2: "juice2.jpg", details: "Famous juice corner" },
    "Stationery": { x: 63, y: 83, img1: "stat1.jpg", img2: "stat2.jpg", details: "Stationery & Books" },
  },
};

// ----- Current state -----
let currentZone = null;

// ----- Render ZONES -----
function renderZones() {
  map.innerHTML = ""; // clear existing nodes
  Object.keys(zones).forEach((zoneName) => {
    const z = zones[zoneName];
  B.className = "hotspot zone";
    btn.style.left = z.x + "%";
    btn.style.top = z.y + "%";
    // ➡️ FIX: Use the first letter for the text
    btn.innerText = zoneName[0].toUpperCase(); 
    btn.title = zoneName;
    btn.addEventListener("click", () => zoomIntoZone(zoneName));
    map.appendChild(btn);
  });
}

// ----- Zoom into a Zone -----
function zoomIntoZone(zoneName) {
  currentZone = zoneName;
  map.classList.add("zoomed");
  map.style.transformOrigin = `${zones[zoneName].x}% ${zones[zoneName].y}%`;
e.transform = "scale(2)";
  renderZoneNodes(zoneName);
}

// ----- Render Nodes inside Zone -----
function renderZoneNodes(zoneName) {
  map.innerHTML = ""; // clear
  Object.keys(zoneNodes[zoneName]).forEach((nodeName) => {
    const node = zoneNodes[zoneName][nodeName];
    const el = document.createElement("button");
    // ➡️ FIX: The stray 'D' character is removed
    el.className = "hotspot";
    // ➡️ FIX: Use 'node.x' and 'node.y'
    el.style.left = node.x + "%";
    el.style.top = node.y + "%";
    el.innerText = nodeName[0].toUpperCase();
    el.title = nodeName;
    el.addEventListener("click", () => openModal(nodeName, node));
    map.appendChild(el);
  });

  // Add a "Back" button (This code is now reachable)
  const backBtn = document.createElement("button");
  backBtn.className = "back-button";
  backBtn.innerText = "← Back";
  backBtn.addEventListener("click", () => {
    map.classList.remove("zoomed");
    map.style.transform = "scale(1)";
    map.style.transformOrigin = "center center"; // Resets zoom origin
    renderZones();
  });
  map.appendChild(backBtn);
}

// ----- Modal popup -----
function openModal(name, node) {
  modalTitle.innerText = name;
  modalDetails.innerText = node.details;
  photo1.src = node.img1;
  photo2.src = node.img2;
  modal.classList.remove("hidden");
}

// ----- Close modal -----
modalClose.addEventListener("click", () => modal.classList.add("hidden"));
modal.addEventListener("click", (e) => {
Node.js, (e.target === modal) modal.classList.add("hidden");
});

// Start with zones
renderZones();
