// Here is the starting point for your application code.
// All stuff below is just to show you how it works. You can delete all of it.

// Use new ES6 modules syntax for everything.
import os from 'os'; // native node.js module
import { remote } from 'electron'; // native electron module
import jetpack from 'fs-jetpack'; // module loaded from npm
import env from './env';
var SerialPort = require("serialport");
window.jQuery = window.$ = require('jquery');
var Chart = require('chart.js')
import {    date, 
            time, 
            consoleLog, 
            listMediaDevices, 
            consoleError, 
            listSerialDevices, 
            connectRoutine, 
            consoleSuccess} from './custom_modules/utility';

console.log('Loaded environment variables:', env);

var app = remote.app;
var appDir = jetpack.cwd(app.getAppPath());

console.log('The author of this app is:', appDir.read('package.json', 'json').author);


document.addEventListener('DOMContentLoaded', function () {
    document.getElementById('platform-info').innerHTML = os.platform();

    //setting initial time/date
    document.getElementById('date').innerHTML = date();
    document.getElementById('time').innerHTML = time();

    //listing available serial ports
    listSerialDevices();

    //listing available camera devices
    listMediaDevices();

    var attitude = $.flightIndicator('#attitude', 'attitude', {roll:50, pitch:-20, size:325, showBox : true});
    var heading = $.flightIndicator('#heading', 'heading', {heading:150, showBox:true, size:325});
    var altimeter = $.flightIndicator('#altimeter', 'altimeter', {size:325, showBox : true});

    var ctx = document.getElementById("myChart");
    var data = {
    labels: [],
    datasets: [
        {
            label: "My First dataset",
            fill: false,
            lineTension: 0,
            backgroundColor: "rgba(75,192,192,0.4)",
            borderColor: "rgba(75,192,192,1)",
            borderCapStyle: 'butt',
            borderDash: [0],
            borderDashOffset: 0.0,
            borderJoinStyle: 'miter',
            pointBorderColor: "rgba(75,192,192,1)",
            pointBackgroundColor: "#fff",
            pointBorderWidth: 1,
            pointHoverRadius: 5,
            pointHoverBackgroundColor: "rgba(75,192,192,1)",
            pointHoverBorderColor: "rgba(220,220,220,1)",
            pointHoverBorderWidth: 2,
            pointRadius: 1,
            pointHitRadius: 10,
            data: [0],
            spanGaps: false,
         }
        ]
    };

    var latestLabel = 1;
    var increment = 0;
    var myLineChart = new Chart(ctx, {
    type: 'line',
    data: data,
    options: {animationSteps: 0}
});

  setInterval(function(){
                        myLineChart.data.labels.push(latestLabel);
                        myLineChart.data.datasets[0].data.push(30*Math.sin(increment/10));

                        if(latestLabel > 100){
                            myLineChart.data.labels.splice(0,1);
                            myLineChart.data.datasets[0].data.splice(0,1);
                        }

                        console.log(latestLabel);
                        latestLabel++;

                        myLineChart.update();
                        increment++;
                    }, 50);

    document.getElementById("connect-btn").addEventListener('click', function (e) {
        
            if(document.getElementsByClassName('lessright')[0] == null){
                //connect to the selected devices
                connectRoutine();
                // Update at 20Hz
                var increment = 0;
                setInterval(function() {
                    // Attitude update
                    attitude.setRoll(30*Math.sin(increment/10));
                    attitude.setPitch(50*Math.sin(increment/20));
                    
                    // Heading update
                    heading.setHeading(increment);

                    // Altimeter update
                    altimeter.setAltitude(10*increment);
                    altimeter.setPressure(1000+3*Math.sin(increment/50));
                    increment++;
                }, 50);
            }
            else {
                //gonna be lazy and reload the page for a disconnect
                location.reload();
            }

        }); 
    });