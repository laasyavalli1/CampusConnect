// assets/js/main.js
(function(){
  // set year across pages
  document.querySelectorAll('#year, #year2, #year3, #year4, #year5, #year6, #year7, #year8').forEach(el => {
    if(el) el.textContent = new Date().getFullYear();
  });

  // render building cards into specified containers
  function renderGrid(containerId) {
    const container = document.getElementById(containerId);
    if(!container) return;
    container.innerHTML = '';
    (typeof buildings !== 'undefined' ? buildings : []).forEach(b => {
      const card = document.createElement('div');
      card.className = 'building-card';
      card.innerHTML = `
        <img src="${b.thumbnail}" alt="${b.name}" onerror="this.src='assets/images/placeholder-building.jpg'"/>
        <div class="card-body">
          <h3>${b.name}</h3>
          <p class="muted">${b.short || ''}</p>
          <div class="meta">${(b.facilities||[]).slice(0,3).join(' • ')}</div>
          <div style="margin-top:10px">
            <button class="btn btn-primary" data-id="${b.id}">more info</button>
          </div>
        </div>
      `;
      container.appendChild(card);
    });
  }

  // open modal
  const modal = document.getElementById('modal');
  const modalContent = document.getElementById('modal-content');
  function openModal(b){
    if(!b) return;
    const imgs = (b.images || []).map(src => `<img style="width:100%;max-width:100%;margin-bottom:8px;border-radius:8px" src="${src}" onerror="this.src='assets/images/placeholder-building.jpg'">`).join('');
    modalContent.innerHTML = `
      <div style="padding:18px">
        <h2 style="color:var(--maroon)">${b.name}</h2>
        <div class="muted">${(b.facilities||[]).join(' • ')}</div>
        <div style="margin-top:12px">${imgs}</div>
        <div style="margin-top:12px">${b.description || ''}</div>
      </div>
    `;
    modal.classList.remove('hidden');
    modal.setAttribute('aria-hidden','false');
  }
  function closeModal(){ modal.classList.add('hidden'); modal.setAttribute('aria-hidden','true'); }

  // delegate more-info clicks
  document.addEventListener('click', function(e){
    const btn = e.target.closest('button[data-id]');
    if(btn){
      const id = btn.getAttribute('data-id');
      const b = (typeof buildings !== 'undefined' ? buildings : []).find(x=>x.id===id);
      if(b) openModal(b);
    }
    if(e.target.classList.contains('modal-backdrop') || e.target.id==='modal-close') closeModal();
  });

  // render on index/feature pages
  document.addEventListener('DOMContentLoaded', function(){
    renderGrid('cards-grid');
    renderGrid('cards-grid-2');
  });

})();
