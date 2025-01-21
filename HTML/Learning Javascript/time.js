var today = new Date();
var day = today.getDay();
var dayList = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];
var hour = today.getHours();
var min = today.getMinutes();
var sec = today.getSeconds();
var period = hour >= 12 ? "PM" : "AM";

hour = hour % 12;
hour = hour ? hour : 12;
min = min < 10 ? '0' + min : min;
sec = sec < 10 ? '0' + sec : sec;

var time = dayList[day] + ", " + hour + ":" + min + ":" + sec + " " + period;
document.getElementById("time").innerText = time;