var swiper = new Swiper(".swiper", {
    effect: "coverflow",
    grabCursor: true,
    centeredSlides: true,
    coverflowEffect: {
        rotate: 0,
        stretch: 0,
        depth: 100,
        modifier: 4,
        slideShadows: false
    },
    loop: true,
    keyboard: {
        enabled: true
    },
    mousewheel: {
        thresholdDelta: 70
    },
    breakpoints: {
        560: {
            slidesPerView: 2.5
        },
        768: {
            slidesPerView: 3
        },
        1024: {
            slidesPerView: 3
        }
    }
});