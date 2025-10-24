document.addEventListener('DOMContentLoaded', function() {
    // 1. Get the elements (Make sure these IDs match your HTML)
    const exploreBtn = document.getElementById('explore-map-btn');
    const optionsContainer = document.getElementById('navigation-options');
    const insideBtn = document.getElementById('inside-campus-btn');

    // 2. Add the click handler to the main 'Explore The Map' button
    if (exploreBtn) {
        exploreBtn.addEventListener('click', function(e) {
            e.preventDefault(); // Stop the link from jumping/reloading the page
            
            // Toggle the visibility of the options container
            if (optionsContainer.style.display === 'none' || optionsContainer.style.display === '') {
                optionsContainer.style.display = 'block'; // Show it
                exploreBtn.textContent = 'Hide Map Options'; // Optional: Change button text
            } else {
                optionsContainer.style.display = 'none'; // Hide it
                exploreBtn.textContent = 'Explore The Map'; // Revert button text
            }
        });
    }

    // 3. Click handler for 'Inside Campus Navigation' (Placeholder for the map logic)
    if (insideBtn) {
        insideBtn.addEventListener('click', function(e) {
            e.preventDefault();
            
            // 🚨 IMPORTANT: You will replace this alert with the actual code
            // to load and display the Leaflet map in the next step!
            alert('Inside Campus Navigation selected! Map loading soon...');
        });
    }
});
