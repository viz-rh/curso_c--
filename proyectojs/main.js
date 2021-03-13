function llenarDatos(){
    var stock = Array(100)
    stock.forEach((e)=>{
        stock[indexOf(e)] = new Object();
    })
    stock[0].id=2;
    stock[1].id=4;
    stock[2].id=1;
    stock[3].id=3;
    stock[4].id=5;

    stock[0].producto="leche";
    stock[1].producto="pan";
    stock[2].producto="agua";
    stock[3].producto="huevo";
    stock[4].producto="refresco";

    stock[0].pc=12.35;
    stock[1].pc=5.5;
    stock[2].pc=13.39;
    stock[3].pc=22.4;
    stock[4].pc=10.99;

    stock[0].pv=15.5;
    stock[1].pv=7.95;
    stock[2].pv=18.55;
    stock[3].pv=30.39;
    stock[4].pv=14.75;

    stock[0].existencias=16;
    stock[1].existencias=18;
    stock[2].existencias=12;
    stock[3].existencias=20;
    stock[4].existencias=30;

    stock[0].nReorden=5;
    stock[1].nReorden=6;
    stock[2].nReorden=4;
    stock[3].nReorden=7;
    stock[4].nReorden=8;

    stock[0].st=1;
    stock[1].st=1;
    stock[2].st=1;
    stock[3].st=1;
    stock[4].st=1;

    console.log(stock[0].producto);
    
}
llenarDatos();


// var stdin = process.openStdin();
// stdin.addListener("data", function(key) {}