var hody = [];
let tlacitko = document.getElementById('game');
document.getElementById('game').addEventListener('click',
    function(){
        hod();
        audio();
        console.log(hody);

    }
);
$(function() {
    $('body').removeClass('fade-out');
});
function suma(cisla) {
    var sum = 0;
    cisla.forEach(function(value,index){
        sum += value;
    })
    return sum;
}

function maximum(cisla) {
    var max = 1;
    cisla.forEach(function(value,index){
        if (value > max) max = value;
    })
    return max;
}

function minimum(cisla) {
    var min = 6;
    cisla.forEach(function(value,index){
        if (value < min) min = value;
    })
    return min;
}

function average(sum, count) {
    return (sum / count).toFixed(2);
}

function hod() {
    var obrazek = ["img/kostka1.png","img/kostka2.png","img/kostka3.png","img/kostka4.png","img/kostka5.png","img/kostka6.png"];
    let Interval1 = window.setInterval(function(){
        document.getElementById('cube').src = obrazek[Math.floor(Math.random()*obrazek.length)];
    },150)
    window.setTimeout(function(){
        window.clearInterval(Interval1);
    },25599)
    window.setTimeout(function(){
        var h = Math.ceil(Math.random() * 6);
        hody.push(h);
        if(h==6){
            audio3();
           
        }
        else if(h==1){
            audio2();
        }
        document.getElementById('cube').src='img/kostka' + h + '.png';
        document.getElementById('result').innerHTML = '<p>Hod: ' + h + '</p>';
        document.getElementById('result').innerHTML += 
            '<p>Počet hodů: ' + hody.length + '</p>';
        document.getElementById('result').innerHTML += 
            '<p>Součet hodů: ' + suma(hody) + '</p>';
        document.getElementById('result').innerHTML += 
            '<p>Průměr hodů: ' + average(suma(hody),hody.length) + '</p>';
        document.getElementById('result').innerHTML += 
            '<p>Nejvyšší hod: ' + maximum(hody) + '</p>';
        document.getElementById('result').innerHTML += 
            '<p>Nejnižší hod: ' + minimum(hody) + '</p>';
        return h;
    },26000)
  
}
function audio(){
    tlacitko.hidden= true;
    var zvuk = document.getElementById('diceRoll');
    zvuk.play();
    window.setTimeout(function(){
        zvuk.pause();
        zvuk.currentTime = 0;
        zvuk.volume= 0.7; 
        tlacitko.hidden=false;
    },26000);
}
function audio2(){
    var zvuk = document.getElementById('jedna');
    zvuk.play();
    window.setTimeout(function(){
        zvuk.pause();
        zvuk.currentTime = 0;
        zvuk.volume= 0.7;
    },14000);
}
function audio3(){
    if (window.confirm('Klikni Ok pro Výhru.'))
    {
    window.open('https://www.youtube.com/watch?v=dQw4w9WgXcQ', '_blank');
    };
    var zvuk = document.getElementById('sest');
    zvuk.play();
    window.setTimeout(function(){
        zvuk.pause();
        zvuk.currentTime = 0;
        zvuk.volume= 0.7; 
    },7000);
}