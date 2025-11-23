// navigation.js - for indoor/outdoor maps and hotspot modals

document.addEventListener("DOMContentLoaded", () => {
    const hotspots = [
        { id: "admin", title: "Administration Block", photos: ["admin1.jpeg", "admin2.jpeg"], details: "Main administrative block of NIT Trichy." },
        { id: "library", title: "Library", photos: ["library1.jpeg", "library2.jpeg"], details: "Central library with vast collection." },
        // Add more hotspots as needed
    ];

    const modal = document.getElementById("hotspotModal");
    const modalTitle = document.getElementById("modalTitle");
    const modalDetails = document.getElementById("modalDetails");
    const photo1 = document.getElementById("photo1");
    const photo2 = document.getElementById("photo2");
    const modalClose = document.getElementById("modalClose");

    // Example hotspots on map - replace with actual clickable areas or use HTML map
    hotspots.forEach(hotspot => {
        const elem = document.createElement("div");
        elem.classList.add("hotspot");
        elem.style.position = "absolute";
        elem.style.width = "40px";
        elem.style.height = "40px";
        elem.style.borderRadius = "50%";
        elem.style.backgroundColor = "#f5c518";
        elem.style.cursor = "pointer";
        elem.style.boxShadow = "0 0 10px #ffd633";
        elem.title = hotspot.title;

        // Random positions for demo - replace with real coordinates
        elem.style.top = Math.random() * 500 + "px";
        elem.style.left = Math.random() * 900 + "px";

        elem.addEventListener("click", () => {
            modalTitle.textContent = hotspot.title;
            modalDetails.textContent = hotspot.details;
            photo1.src = hotspot.photos[0];
            photo2.src = hotspot.photos[1];
            modal.classList.remove("hidden");
        });

        document.getElementById("map").appendChild(elem);
    });

    modalClose.addEventListener("click", () => {
        modal.classList.add("hidden");
    });

    window.addEventListener("click", (e) => {
        if (e.target === modal) modal.classList.add("hidden");
    });
});
