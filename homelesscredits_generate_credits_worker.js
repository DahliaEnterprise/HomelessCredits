// addEventListener is directly accessible in worker file
addEventListener("message", event => {
    console.log(event.data);
});