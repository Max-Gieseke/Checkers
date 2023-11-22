window.addEventListener("load", loadHandler);

function loadHandler(){
    let gameContainer = document.getElementById("GameHolder");
    for(let i = 0; i < 12; i++){
        let newDark = document.createElement("div");
        newDark.classList.add("dark-pawn");
        let startSquare = document.getElementById(`${i}`);
        startSquare.appendChild(newDark);
        
    }
    for(let i = 20; i < 32; i++){
        let newLight = document.createElement("div");
        newLight.classList.add("light-pawn");
        let startSquare = document.getElementById(`${i}`);
        startSquare.appendChild(newLight);
        
    }
}