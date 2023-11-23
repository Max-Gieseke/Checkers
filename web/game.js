window.addEventListener("load", loadHandler);


let possibleMoves = [];
function loadHandler(){
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
    let setUp = document.getElementById("playGame");
    setUp.addEventListener("click", setPlayers);

    let goodSquares = document.getElementsByClassName("valid");
    for(let sq of goodSquares){
        sq.addEventListener("click", showSquares);
    }
}
let humanBlack = true;
let humanWhite = false;
let currentTurn = 1;

async function setPlayers() {
    let blackP = document.getElementById("blackPlayer");
    let whiteP = document.getElementById("whitePlayer");
    humanBlack = blackP.value == "Human";
    humanWhite = whiteP.value == "Human";
    currentTurn = 1;
    let response = await fetch("/api/getMove", {method: "GET", headers: {"Content-Type": "application/json"}});
    let data = await response.json();
    console.log(data);
    possibleMoves = data["moves"];
}


function showSquares(event){
    let curSquare = event.target.id;
    for(let move of possibleMoves){
        if(move["start"] == curSquare){
            document.getElementById
        }
    }
}