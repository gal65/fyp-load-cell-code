#include "HX711.h"

// Use channel A from two different amplifiers

// HX711 circuit wiring
const int LOADCELL_L_DOUT_PIN = A0;
const int LOADCELL_L_SCK_PIN = A1;
const int LOADCELL_R_DOUT_PIN = A2;
const int LOADCELL_R_SCK_PIN = A3;

float force_L = 0;
float force_R = 0;

#define THRESHOLD 50 // Force difference threshold, in Newtons

HX711 load_cell_L;
HX711 load_cell_R;

void setup() {
  Serial.begin(9600);
  Serial.println("Calibrating...");
  
  load_cell_L.begin(LOADCELL_L_DOUT_PIN, LOADCELL_L_SCK_PIN); // initialise left load cell
  load_cell_L.set_gain(128);        // use channel A
  load_cell_L.set_scale(2069.f);    // this value is obtained by calibrating the scale with known weights; see the README for details
  load_cell_L.tare();               // reset the scale to 0
  
  load_cell_R.begin(LOADCELL_R_DOUT_PIN, LOADCELL_R_SCK_PIN); // repeat for right load cell
  load_cell_R.set_gain(128);       
  load_cell_R.set_scale(2069.f);    
  load_cell_R.tare();               

  Serial.println("Calibrated.");
  Serial.println("-----------------------------------------");
  Serial.println("Start:");
}

void loop() {
  // Get readings from each load cell (in Newtons)
  force_L = -(load_cell_L.get_units()/41*9.81*0.9);
  force_R = -(load_cell_R.get_units()/41*9.81*0.9); 

  // Compare force readings
  if (abs(force_L - force_R) > THRESHOLD) {
    if (force_L < force_R) {
      // Output to control
      Serial.println("Hose tending RIGHT");
    } else if (force_L > force_R) {
      // Output to control
      Serial.println("Hose tending LEFT");
    }
  } else {
    // Output to control
    Serial.println("Correct course"); 
  }

  // Put the ADCs in sleep mode to save power
  load_cell_L.power_down(); 
  load_cell_R.power_down();  
  delay(1000);
  load_cell_L.power_up();
  load_cell_R.power_up();
}
