let swiper = new Swiper(".mySwiper", {
    slidesPerView: 1,
    spaceBetween: 30,
    loop: true,
    pagination: {
      el: ".swiper-pagination",
      clickable: true,
    },
    navigation: {
      nextEl: ".swiper-button-next",
      prevEl: ".swiper-button-prev",
    },
});


$('.owl-carousel').owlCarousel({
    loop:true,
    margin:0,
    nav:true,
    responsive:{
        0:{
            items:2
        },
        600:{
            items:3
        },
        1000:{
            items:6
        }
    }
})






const nav = document.querySelector(".nav-items")
const open = document.getElementById("open")
const close = document.getElementById("close")

open.addEventListener("click", () => {
    nav.style.display="flex";
    nav.style.top="0%"
})
close.addEventListener("click", () => {
    nav.style.top="-110%"
})
