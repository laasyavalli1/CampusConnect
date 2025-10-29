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
  "Sports Zone": { x: 25, y: 50 },
  "Academic Zone": { x: 45.7, y: 54.5 },
  "Hostel Zone": { x: 78, y: 50 },
  "Quarters Zone": { x: 40, y: 75 },
  "Shopping Zone": { x: 57, y: 70 },
};

// ----- Level 2: Nodes inside zones -----
let zoneNodes = {
  "Sports Zone": {
    "Indoor Stadium": { x: 15, y: 56, img1: "indoor1.jpg", img2: "indoor2.jpg", details: "Indoor sports complex" },
    "NSO Ground": { x: 25, y: 40, img1: "ground1.jpg", img2: "ground2.jpg", details: "Athletics and football ground" },
    "Swimming Pool": { x: 24, y: 56, img1: "pool1.jpg", img2: "pool2.jpg", details: "Olympic-size swimming pool" },
  },
  "Academic Zone": {
    "CSE Department": { x: 42, y: 65, img1: "cse1.jpg", img2: "cse2.jpg", details: "Computer Science Department" },
    "EEE Department": { x: 35, y: 45, img1: "eee1.jpg", img2: "eee2.jpg", details: "Electrical and Electronics" },
    "Central Library": { x: 26, y: 65, img1: "lib1.jpg", img2: "lib2.jpg", details: "Central library with study halls" },
    "Ojas": { x: 50, y: 12, img1: "ojas1.jpg", img2: "ojas2.jpg", details: "Ojas Auditorium/Block" },
    "Orion": { x: 41, y: 20, img1: "orion1.jpg", img2: "orion2.jpg", details: "Orion Academic Block" },
    "Architecture Dept": { x: 46.6, y: 15, img1: "arch1.jpg", img2: "arch2.jpg", details: "Department of Architecture" },
    "Chemical Engg Dept": { x: 38, y: 35, img1: "chem1.jpg", img2: "chem2.jpg", details: "Department of Chemical Engineering" },
    "Admin Block": { x: 38.5, y: 34.5, img1: "admin1.jpg", img2: "admin2.jpg", details: "Administrative Block (Main Office)" },
    "Barn Hall": { x: 42, y: 38, img1: "barn1.jpg", img2: "barn2.jpg", details: "Barn Hall Examination and Lecture Complex" },
    "Golden Jubilee": { x: 50, y: 25, img1: "gj1.jpg", img2: "gj2.jpg", details: "Golden Jubilee Complex" },
    "Logos": { x: 55, y: 40, img1: "logos1.jpg", img2: "logos2.jpg", details: "Logos Lecture Hall Complex" },
    "Octagon": { x: 49, y: 50, img1: "oct1.jpg", img2: "oct2.jpg", details: "Octagon Block" },
    "Third-i": { x: 57, y: 45, img1: "thirdi1.jpg", img2: "thirdi2.jpg", details: "Third-I Innovation Center" },
    "Production Engg Dept": { x: 53, y: 52, img1: "prod1.jpg", img2: "prod2.jpg", details: "Department of Production Engineering" },
    "Mechanical Engg Dept": { x: 39, y: 47, img1: "mech1.jpg", img2: "mech2.jpg", details: "Department of Mechanical Engineering" },
    "Mettalurgical Engg Dept": { x: 39, y: 50, img1: "metta1.jpg", img2: "metta2.jpg", details: "Department of Metallurgical & Materials Engg" },
    "Civil Engg Dept": { x: 37, y: 58, img1: "civil1.jpg", img2: "civil2.jpg", details: "Department of Civil Engineering" },
    "Lyceum Block": { x: 42, y: 59, img1: "lyc1.jpg", img2: "lyc2.jpg", details: "Lyceum Lecture Hall" },
    "Instrumentation Dept": { x: 50, y: 65, img1: "instru1.jpg", img2: "instru2.jpg", details: "Dept. of Instrumentation and Control Engg" },
    "Management Studies Dept": { x: 57, y: 60, img1: "mgmt1.jpg", img2: "mgmt2.jpg", details: "Dept. of Management Studies" },
  },
  "Hostel Zone": {
    "Ruby Hostel": { x: 75, y: 60, img1: "ruby1.jpg", img2: "ruby2.jpg", details: "Girls Hostel Ruby" },
    "Emerald Hostel": { x: 75, y: 65, img1: "emerald1.jpg", img2: "emerald2.jpg", details: "Boys Hostel Emerald" },
    "Sapphire Hostel": { x: 68, y: 70, img1: "sapp1.jpg", img2: "sapp2.jpg", details: "Sapphire Hostel for 2nd years" },
  },
  "Quarters Zone": {
    "Faculty Quarters": { x: 80, y: 75, img1: "fq1.jpg", img2: "fq2.jpg", details: "Faculty Residential Area" },
    "Staff Quarters": { x: 85, y: 78, img1: "sq1.jpg", img2: "sq2.jpg", details: "Staff Quarters" },
  },
  "Shopping Zone": {
    "2K Market": { x: 56.5, y: 75, img1: "market1.jpg", img2: "market2.jpg", details: "2K Market" },
    "Juice Shop": { x: 58, y: 71, img1: "juice1.jpg", img2: "juice2.jpg", details: "Famous juice corner" },
    "Stationery": { x: 52, y: 71, img1: "stat1.jpg", img2: "stat2.jpg", details: "Stationery & Books" },
  },
};

// ----- Current state -----
let currentZone = null;

// ----- Render ZONES -----
function renderZones() {
  map.innerHTML = ""; // clear existing nodes
  Object.keys(zones).forEach((zoneName) => {
    const z = zones[zoneName];
    const btn = document.createElement("button"); // CRITICAL: 'btn' variable defined
    btn.className = "hotspot zone";
    btn.style.left = z.x + "%";
    btn.style.top = z.y + "%";
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
  map.style.transform = "scale(2)"; // CRITICAL: Fixes typo 'e.transform' to 'map.style.transform'
  renderZoneNodes(zoneName);
}

// ----- Render Nodes inside Zone -----
function renderZoneNodes(zoneName) {
  map.innerHTML = ""; // clear
  Object.keys(zoneNodes[zoneName]).forEach((nodeName) => {
    const node = zoneNodes[zoneName][nodeName];
    const el = document.createElement("button");
    el.className = "hotspot";
    // CRITICAL FIX: Use 'node' instead of 'z'
    el.style.left = node.x + "%";
    el.style.top = node.y + "%";
    el.innerText = nodeName[0].toUpperCase();
    el.title = nodeName;
    el.addEventListener("click", () => openModal(nodeName, node));
    map.appendChild(el);
  });

  // Add a "Back" button (Now guaranteed to run)
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
  if (e.target === modal) modal.classList.add("hidden"); // CRITICAL: Fixes stray text
});

// Start with zones
renderZones();
