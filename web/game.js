window.addEventListener("load", loadHandler);


let possibleMoves = [];
let startSquare = null;
let lastChecked = [];
let doneWithTurn = false
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
    setUp.addEventListener("click", startGame);

    let goodSquares = document.getElementsByClassName("valid");
    for(let sq of goodSquares){
        sq.addEventListener("click", showSquares);
    }
}

let currentTurn = 1;
let curMove = null;


async function waitForMove() {
    while (curMove === null) {
        await new Promise(resolve => setTimeout(resolve, 100));
    }
    return curMove;
}
async function playerMove() {
    let response = await fetch("/api/getMove", {method: "GET", headers: {"Content-Type": "application/json"}});
    let data = await response.json();
    possibleMoves = data["moves"];
    let next = await waitForMove();
    possibleMoves = [];
    curMove = null;
    return next;
}

async function compMove() {
    let response = await fetch("/api/aiTurn", {method: "GET", headers: {"Content-Type": "application/json"}});
    let move = await response.json();
    return move;
}
async function startGame() {
    let blackP = document.getElementById("blackPlayer");
    let whiteP = document.getElementById("whitePlayer");
    let darkFunction;
    let lightFunction;
    if(blackP.value === "human"){
        darkFunction = playerMove;
    }
    else {
        darkFunction = compMove;
    }
    if(whiteP.value === "human"){
        lightFunction = playerMove;
    }
    else {
        lightFunction = compMove;
    }
    currentTurn = 1;
    startSquare = null;
    lastChecked = [];
    await fetch("/api/restart", {method: "GET", headers: {"Content-Type": "application/json"}});
    playGame(darkFunction, lightFunction);
}

function removeHighlight(){
    for(let sqElem of lastChecked){
        sqElem.classList.toggle("highlight");
    }
    lastChecked = [];
}



function showSquares(event){
    let pot = event.target;
    let curSquare;
    if(pot.classList.contains("valid")){
        curSquare = pot;
    }
    else {
        curSquare = pot.parentElement;
    }
    //If it is highlighted, then we want to do a move
    if(curSquare.classList.contains("highlight")){
        removeHighlight();
        setMove(curSquare.id);
    }
    else {
        removeHighlight();
        startSquare = curSquare.id;
        for(let move of possibleMoves) {
            if(move["start"] == startSquare){
                let end = document.getElementById(move["end"]);
                end.classList.add("highlight");
                lastChecked.push(end);
            }
        }
    }
}


function matchType(square){
    let piece = square.children[0];
    if(piece.classList.contains("dark-pawn")){
        return "dark-pawn";
    }
    else if (piece.classList.contains("light-pawn")) {
        return "light-pawn";
    }
    else if(piece.classList.contains("dark-king")){
        return "dark-king";
    }
    else  {
        return "light-king";
    }
}

function setMove(end){
    for(let move of possibleMoves){
        if(move["start"] == startSquare && move["end"] == end){
            curMove = move;
            return;
        }
    }
}
/*
    Does move on board and sends request to update the server's board
 */
async function doTurn(move) {
    let sSquare = document.getElementById(move["start"]);
    let pieceType = matchType(sSquare);
    sSquare.removeChild(sSquare.children[0]);
    for(let idx of move["jumps"]){
        let holder = document.getElementById(idx);
        holder.removeChild(holder.children[0]);
    }
    let eSquare = document.getElementById(move["end"]);

    if(pieceType === "dark-pawn" && move["end"] >= 28) {
        let newKing = document.createElement("div");
        newKing.classList.add("dark-king");
        eSquare.appendChild(newKing);
    }
    else if(pieceType === "light-pawn" && move["end"] <= 3){
        let newKing = document.createElement("div");
        newKing.classList.add("light-king");
        eSquare.appendChild(newKing);
    }
    else {
        let newPiece = document.createElement("div");
        newPiece.classList.add(pieceType);
        eSquare.appendChild(newPiece);
    }
    let toSend = JSON.stringify(move);
    await fetch("/api/doTurn",
        {method: "POST", headers: {"Content-Type": "application/json"}, body: toSend});
}


async function playGame(blackPlay, whitePlay) {
    let nextMove = null;
    while (true) {
        nextMove = await blackPlay();
        await doTurn(nextMove);
        nextMove = await whitePlay();
        await doTurn(nextMove);
    }
}