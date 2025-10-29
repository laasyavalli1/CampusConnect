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
        "Indoor Stadium": { x: 15, y: 55, img1: "https://via.placeholder.com/400x300/3498db/ffffff?text=Indoor+Stadium+1", img2: "https://via.placeholder.com/400x300/e74c3c/ffffff?text=Indoor+Stadium+2", details: "Indoor sports complex with facilities for basketball, badminton, and table tennis. Features professional-grade flooring and seating for 500 spectators." },
        "NSO Ground": { x: 20, y: 65, img1: "https://via.placeholder.com/400x300/2ecc71/ffffff?text=NSO+Ground+1", img2: "https://via.placeholder.com/400x300/f39c12/ffffff?text=NSO+Ground+2", details: "Athletics and football ground with 400m synthetic track. Hosts inter-college tournaments and NSO activities throughout the year." },
        "Swimming Pool": { x: 25, y: 60, img1: "https://via.placeholder.com/400x300/9b59b6/ffffff?text=Swimming+Pool+1", img2: "https://via.placeholder.com/400x300/1abc9c/ffffff?text=Swimming+Pool+2", details: "Olympic-size swimming pool with diving boards. Maintained at competitive standards with certified lifeguards always on duty." },
    },
    "Academic Zone": {
        "CSE Department": { x: 45, y: 40, img1: "https://via.placeholder.com/400x300/3498db/ffffff?text=CSE+Building+1", img2: "https://via.placeholder.com/400x300/e74c3c/ffffff?text=CSE+Lab+2", details: "Computer Science Department with state-of-the-art labs, research centers, and faculty offices. Houses the AI Research Center and Cybersecurity Lab." },
        "EEE Department": { x: 50, y: 45, img1: "https://via.placeholder.com/400x300/f39c12/ffffff?text=EEE+Building+1", img2: "https://via.placeholder.com/400x300/2ecc71/ffffff?text=EEE+Lab+2", details: "Electrical and Electronics Engineering department with advanced power systems lab, electronics workshop, and robotics research center." },
        "Central Library": { x: 40, y: 50, img1: "https://via.placeholder.com/400x300/9b59b6/ffffff?text=Library+Exterior", img2: "https://via.placeholder.com/400x300/1abc9c/ffffff?text=Reading+Hall", details: "Central library with study halls, digital resource center, and over 100,000 volumes. Open 24/7 during examination periods." },
    },
    "Hostel Zone": {
        "Ruby Hostel": { x: 70, y: 60, img1: "https://via.placeholder.com/400x300/e74c3c/ffffff?text=Ruby+Hostel+1", img2: "https://via.placeholder.com/400x300/3498db/ffffff?text=Ruby+Common+Room", details: "Girls Hostel Ruby with capacity for 300 students. Features common rooms, study areas, and 24/7 security." },
        "Emerald Hostel": { x: 75, y: 65, img1: "https://via.placeholder.com/400x300/2ecc71/ffffff?text=Emerald+Hostel+1", img2: "https://via.placeholder.com/400x300/f39c12/ffffff?text=Emerald+Mess", details: "Boys Hostel Emerald with modern amenities including gym, recreation room, and high-speed Wi-Fi throughout the building." },
        "Sapphire Hostel": { x: 68, y: 70, img1: "https://via.placeholder.com/400x300/9b59b6/ffffff?text=Sapphire+Hostel+1", img2: "https://via.placeholder.com/400x300/1abc9c/ffffff?text=Sapphire+Room", details: "Sapphire Hostel for 2nd year students with single and double occupancy rooms. Features a dedicated computer lab and music room." },
    },
    "Quarters Zone": {
        "Faculty Quarters": { x: 80, y: 75, img1: "https://via.placeholder.com/400x300/3498db/ffffff?text=Faculty+Quarters+1", img2: "https://via.placeholder.com/400x300/e74c3c/ffffff?text=Faculty+Garden", details: "Faculty Residential Area with spacious apartments, community center, and playgrounds. Located in a quiet, wooded part of campus." },
        "Staff Quarters": { x: 85, y: 78, img1: "https://via.placeholder.com/400x300/f39c12/ffffff?text=Staff+Quarters+1", img2: "https://via.placeholder.com/400x300/2ecc71/ffffff?text=Staff+Parking", details: "Staff Quarters with convenient access to campus facilities. Includes a community hall and grocery store within the complex." },
    },
    "Shopping Zone": {
        "Market": { x: 60, y: 82, img1: "https://via.placeholder.com/400x300/9b59b6/ffffff?text=Campus+Market+1", img2: "https://via.placeholder.com/400x300/1abc9c/ffffff?text=Market+Interior", details: "Campus Market with variety of shops including clothing, electronics, and daily necessities. Also houses a bank branch and ATM." },
        "Juice Shop": { x: 58, y: 85, img1: "https://via.placeholder.com/400x300/e74c3c/ffffff?text=Juice+Shop+1", img2: "https://via.placeholder.com/400x300/3498db/ffffff?text=Juice+Counter", details: "Famous juice corner known for fresh fruit juices, smoothies, and healthy snacks. Popular student hangout spot." },
        "Stationery": { x: 63, y: 83, img1: "https://via.placeholder.com/400x300/2ecc71/ffffff?text=Stationery+Shop", img2: "https://via.placeholder.com/400x300/f39c12/ffffff?text=Book+Section", details: "Stationery & Books store offering textbooks, art supplies, and printing services. Provides special discounts for students." },
    },
};

// ----- Current state -----
let currentZone = null;

// ----- Render ZONES -----
function renderZones() {
    map.innerHTML = ""; // clear existing nodes
    Object.keys(zones).forEach((zoneName) => {
        const z = zones[zoneName];
        const btn = document.createElement("button");
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
    map.style.transform = "scale(2)";
    renderZoneNodes(zoneName);
}

// ----- Render Nodes inside Zone -----
function renderZoneNodes(zoneName) {
    map.innerHTML = ""; // clear
    Object.keys(zoneNodes[zoneName]).forEach((nodeName) => {
        const node = zoneNodes[zoneName][nodeName];
        const el = document.createElement("button");
        el.className = "hotspot";
        el.style.left = node.x + "%";
        el.style.top = node.y + "%";
        el.innerText = nodeName[0].toUpperCase();
        el.title = nodeName;
        el.addEventListener("click", () => openModal(nodeName, node));
        map.appendChild(el);
    });

    // Add a "Back" button
    const backBtn = document.createElement("button");
    backBtn.className = "back-button";
    backBtn.innerText = "← Back to Zones";
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
    // This closes the modal if you click on the background (e.target === modal)
    if (e.target === modal) {
        modal.classList.add("hidden");
    }
});

// Start with zones
renderZones();
