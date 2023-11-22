window.addEventListener("load", loadHandler);

function loadHandler() {
    console.log("Here");
    document.getElementById("black").addEventListener("click", blackPlayer);
    document.getElementById("white").addEventListener("click", whitePlayer);
}

function blackPlayer(){
    let fullUrl = window.location.href;
    let base = fullUrl.split("/")[0];
    let newUrl = base + "/game";
    window.location.href = newUrl;
}

function whitePlayer(){
    let fullUrl = window.location.href;
    let base = fullUrl.split("/")[0];
    let newUrl = base + "/game";
    window.location.href = newUrl;
}