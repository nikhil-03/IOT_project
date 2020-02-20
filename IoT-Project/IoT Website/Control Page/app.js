

var firebaseConfig = {
    apiKey: "AIzaSyA7WLCe04kTGDCYZkR4NImu2szb_L8cq58",
    authDomain: "swapnil-61130.firebaseapp.com",
    databaseURL: "https://swapnil-61130.firebaseio.com",
    projectId: "swapnil-61130",
    storageBucket: "swapnil-61130.appspot.com",
    messagingSenderId: "307828759678",
    appId: "1:307828759678:web:10d729f79a989ea8"
  };
  // Initialize Firebase
firebase.initializeApp(firebaseConfig);
var database = firebase.database();



var reftemp = firebase.database().ref('Temperature');
fintemp = "";
reftemp.on("value", function(snapshot) {
   // console.log(snapshot.val());
   const swap = snapshot.val();
   fintemp = swap;
   var age = document.querySelector(".temperature");
   age.textContent = (fintemp);
   if (tempon == "ON") {
    if (tempstatus == "above") {
      if (fintemp >= tempinp) {
        var relayRef = database.ref();
        var result = relayRef.child("Relay").set("ON");
      }
      else{
        var relayRef = database.ref();
        var result = relayRef.child("Relay").set("OFF");      }
    }
    else if (tempstatus == "below") {
      if (fintemp <= tempinp) {
        var relayRef = database.ref();
        var result = relayRef.child("Relay").set("ON");
      }
      else{
        var relayRef = database.ref();
        var result = relayRef.child("Relay").set("OFF");      }
    }
    }
   //  firebase.initializeApp(firebaseConfig);
   //  var database = firebase.database();

    if (motionon == "ON") {
      if (motionstatus == "motion") {
      if(finmotion == "ON"){
       // var result = relayRef.child("Relay").set("ON");
       relay_on();
      }
      else{
        // var result = relayRef.child("Relay").set("OFF"); 
      relay_off(); 
      }
    }
    else if (motionstatus == "nomotion") {
      if(finmotion == "OFF"){
        relay_on();
        // var result = relayRef.child("Relay").set("ON");
      }
      else{
        relay_off();
        // var result = relayRef.child("Relay").set("OFF");  
      }
    }
   }
});

// }, function (error) {
//    console.log("Error: " + error.code);
// });








var refmotion = firebase.database().ref('Motion');
finmotion = "";
refmotion.on("value", function(snapshot) {
   // console.log(snapshot.val());
   const swap = snapshot.val();
   finmotion = swap;
   var age = document.querySelector(".motion");
   age.textContent = finmotion;

   // if (motionon == "ON") {
   //  if (motionstatus == "motion") {
   //    if(finmotion == "ON"){
   //      var result = relayRef.child("Relay").set("ON");
   //    }
   //    else{
   //      var result = relayRef.child("Relay").set("OFF");  
   //    }
   //  }
   //  else if (motionstatus == "nomotion") {
   //    if(finmotion == "OFF"){
   //      var result = relayRef.child("Relay").set("ON");
   //    }
   //    else{
   //      var result = relayRef.child("Relay").set("OFF");  
   //    }
   //  }
   // }

}, function (error) {
   console.log("Error: " + error.code);
});

function relay_on(){
  var result = relayRef.child("Relay").set("ON");
}

function relay_off(){
  var result = relayRef.child("Relay").set("OFF");
}










var reffirclap = firebase.database().ref('First Clap');
finfclap = "";
reffirclap.on("value", function(snapshot) {
   // console.log(snapshot.val());
   const swap = snapshot.val();
   finfclap = swap;
   var age = document.querySelector(".fclap");
   age.textContent = finfclap;
   if (clapon == "ON") {
    if (clapstatus == "single") {
      if (finfclap == "ON") {
        relay_on();
      }
      else{
        relay_off();
      }
    }
   }

}, function (error) {
   console.log("Error: " + error.code);
});








var refsecclap = firebase.database().ref('Second Clap');
finsclap = "";
refsecclap.on("value", function(snapshot) {
   // console.log(snapshot.val());
   const swap = snapshot.val();
   finsclap = swap;
   var age = document.querySelector(".sclap");
   age.textContent = finsclap;
   if (clapon == "ON") {
    if (clapstatus == "double") {
      if (finsclap == "ON") {
        relay_on();
      }
      else{
        relay_off();
      }
    }
   }

}, function (error) {
   console.log("Error: " + error.code);
});













































var refrelay = firebase.database().ref('Relay');
finrelay = "";
refrelay.on("value", function(snapshot) {
   // console.log(snapshot.val());
   const swap = snapshot.val();
   finrelay = swap;
   var age = document.querySelector("#relaytext");
   age.textContent = finrelay;
   if (finrelay == "ON") {
    document.getElementById('customSwitches').checked = true;
   }
   else if (finrelay == "OFF") {
    document.getElementById('customSwitches').checked = false;
   }





}, function (error) {
   console.log("Error: " + error.code);
});









































var relayRef = database.ref();
var result = relayRef.child("Relay").set("OFF");
const radioElement = document.getElementById('customSwitches');
radioElement.addEventListener('change', function (event) {
  if(radioElement.checked === true){
    var result = relayRef.child("Relay").set("ON");
  } else {
    var result = relayRef.child("Relay").set("OFF");
  }
// setTimeout(relay_on,1000);
});






function zeroo() { 
                document.getElementById( 
                  "zero").style.visibility = "visible"; 
                document.getElementById( 
                  "one").style.visibility = "hidden"; 
                document.getElementById( 
                  "two").style.visibility = "hidden"; 
                document.getElementById( 
                  "three").style.visibility = "hidden"; 
            } 

function onee() { 
                document.getElementById( 
                  "zero").style.visibility = "hidden"; 
                document.getElementById( 
                  "one").style.visibility = "visible"; 
                document.getElementById( 
                  "two").style.visibility = "hidden"; 
                document.getElementById( 
                  "three").style.visibility = "hidden"; 
            } 

function twoo() { 
                document.getElementById( 
                  "zero").style.visibility = "hidden"; 
                document.getElementById( 
                  "one").style.visibility = "hidden"; 
                document.getElementById( 
                  "two").style.visibility = "visible"; 
                document.getElementById( 
                  "three").style.visibility = "hidden"; 
            } 

function threee() { 
                document.getElementById( 
                  "zero").style.visibility = "hidden"; 
                document.getElementById( 
                  "one").style.visibility = "hidden"; 
                document.getElementById( 
                  "two").style.visibility = "hidden"; 
                document.getElementById( 
                  "three").style.visibility = "visible"; 
} 





var tempon="OFF";
var motionon="OFF";
var clapon="OFF";
var timeon="OFF";

var tempinp="";
var tempstatus="";
function tempsave(){
  tempon = "ON";
   motionon = "OFF";
  clapon = "OFF";
  timeon="OFF";
  tempinp = document.getElementById("inlineFormInputNameTemp").value;
  // alert(tempinp);
  var e = document.getElementById("inlineFormCustomSelectTemp");
  tempstatus = e.options[e.selectedIndex].value;
}


var motioninp="";
var motionstatus="";
function motionsave(){
  tempon = "OFF";
  motionon = "ON";
  clapon = "OFF";
  timeon="OFF";
  var e = document.getElementById("inlineFormCustomSelectMotion");
  motionstatus = e.options[e.selectedIndex].value;
  // alert(motionstatus);
}

var clapinp="";
var clapstatus="";
function clapsave(){
  tempon = "OFF";
  motionon = "OFF";
  clapon = "ON";
  timeon="OFF";
  var e = document.getElementById("inlineFormCustomSelectClap");
  clapstatus = e.options[e.selectedIndex].value;
  // alert(clapstatus);
}

var timeinp="";
function timesave(){
  tempon = "OFF";
  motionon = "OFF";
  clapon = "OFF";
  timeon="ON";
  timeinp = document.getElementById("inlineFormInputNameTime").value;
  // alert(timeinp);
  setTimeout(relay_on,parseInt(timeinp,10)*1000);
  
}


