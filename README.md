# FYP load cell code 
Author: Gordon Lay </br>
Use Sparkfun HX711 load cell amplifiers to read from two load cells and output hose tracking information. </br>
The code was developed on an Arduino Uno and uses the HX711 library https://github.com/bogde/HX711

<h2> Cloning the repository </h2>
If you are familiar with Git, simply run the following command in Bash for Windows or Terminal for Linux:

```
$ git clone https://github.com/gal65/fyp-load-cell-code.git
```
Otherwise, head to https://github.com/gal65/fyp-load-cell-code and download the repository as a .zip file. 

<h2> How to use the program </h2>

* Wire the circuit: the code has been written assuming pins A0 to A3 are used in the configuration 'data1, clock1, data2, clock2', but this can be changed if required.
* Upload and run read_double.ino
* The code will light up a one of the red LEDs if the hose is tending to the left or right. 
* The green LED will light up if the robot's course is good.
* Alternatively, open the serial monitor to view a verbose output
* The code can be altered to recalibrate the sensors (see Calibration section)

<h2> Load cell calibration </h2>

I recommend reading the HX711 library documentation before doing the following with 'calibrate.ino':
1. Call `set_scale()` with no parameter.
2. Call `tare()` with no parameter.
3. Place a known weight on the scale and call `get_units(10)`.
4. Divide the result in step 3 to your known weight. You should
   get about the parameter you need to pass to `set_scale()`.
5. Adjust the parameter in step 4 until you get an accurate reading.
