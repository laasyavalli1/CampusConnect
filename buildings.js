/* assets/js/buildings.js
   Simple array of building objects.
   Add one object per building. Use relative paths.
*/
const buildings = [
  {
    id: "clock_tower",
    name: "NIT Trichy Clock Tower",
    thumbnail: "assets/images/buildings/clock_thumb.jpg",
    images: [
      "assets/images/buildings/clock_1.jpg",
      "assets/images/buildings/clock_2.jpg"
    ],
    short: "The iconic Clock Tower near the main gate.",
    description: "<p>The Clock Tower is the central meeting point of NIT Trichy.</p>",
    facilities: ["landmark","photo-spot"],
    coords: { lat: 0, lng: 0 }
  }
  // Add more building objects (copy the pattern above)
];
