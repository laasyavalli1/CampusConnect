const map = document.getElementById('map');
const modal = document.getElementById('hotspotModal');
const modalClose = document.getElementById('modalClose');
const modalTitle = document.getElementById('modalTitle');
const modalDetails = document.getElementById('modalDetails');
const photo1 = document.getElementById('photo1');
const photo2 = document.getElementById('photo2');

// DSA part: Graph representation
let graph = {
  "Main Gate": {"Library":50,"Hostel A":100},
  "Library":{"Main Gate":50,"Hostel A":60},
  "Hostel A":{"Main Gate":100,"Library":60},
  "Central Library":{"Main Gate":20,"Library":70},
};

// Hotspot nodes
let nodes = {
  "Main Gate":{x:15,y:70,img1:'main_gate1.jpg',img2:'main_gate2.jpg',details:"Main entrance"},
  "Library":{x:50,y:40,img1:'library1.jpg',img2:'library2.jpg',details:" library"},
  "Hostel A":{x:70,y:60,img1:'hostelA1.jpg',img2:'hostelA2.jpg',details:"First year hostel"},
  "Central Library":{x:25,y:70,img1:'cl1.jpg',img2:'cl2.jpg',details:"Central Library"},
  
};

function renderHotspots(){
  Object.keys(nodes).forEach(name=>{
    const node=nodes[name];
    const el=document.createElement('button');
    el.className='hotspot';
    el.style.left=node.x+'%';
    el.style.top=node.y+'%';
    el.innerText=name[0].toUpperCase();
    el.title=name;
    el.addEventListener('click',()=>openModal(name));
    map.appendChild(el);
  });
}

function openModal(name){
  const node=nodes[name];
  modalTitle.innerText=name;
  modalDetails.innerText=node.details;
  photo1.src=node.img1;
  photo2.src=node.img2;
  modal.classList.remove('hidden');
}

modalClose.addEventListener('click',()=>modal.classList.add('hidden'));
modal.addEventListener('click',e=>{if(e.target===modal) modal.classList.add('hidden');});

renderHotspots();
