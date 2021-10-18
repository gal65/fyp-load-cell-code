# FYP load cell code 

Use Sparkfun HX711 load cell amplifiers to read from two load cells and output hose tracking information.   
The code was developed on an Arduino Uno and uses the HX711 library https://github.com/bogde/HX711

## Downloading the repository 
Head to https://github.com/gal65/fyp-load-cell-code and download the repository as a .zip file. Alternatively you can fork the repository. 

## Load cell calibration
I recommend reading the HX711 library documentation before running calibrate.ino, as the `calibrate.ino` is identical.When running <em>calibrate.ino</em> make sure to have the serial monitor open and follow the instructions. The value you get from this should be passed as an argument into `set_scale()` in `read_double.ino`. 

## How to use the program

* Wire the circuit: the code has been written assuming pins A0 to A3 are used in the configuration 'data1, clock1, data2, clock2', but this can be changed if required.
* Upload and run `read_double.ino`
* The code will light up a one of the red LEDs if the hose is tending to the left or right. 
* The green LED will light up if the robot's course is good.
* Alternatively, open the serial monitor to view a verbose output.
