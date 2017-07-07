
#include <IRsend.h>

/*
 IR Remote Control
 129 Left 
 130 Forward 
 131 Right 
 132 Spot 
 133 Max 
 134 Small 
 135 Medium 
 136 Large / Clean 
 137 Stop 
 138 Power 
 139 Arc Left 
 140 Arc Right 
 141 Stop  
 
 Scheduling Remote  
 142 Download 
 143 Seek Dock 
 
 Roomba Discovery Driveon Charger 
 240 Reserved 
 248 Red Buoy 
 244 Green Buoy 
 242 Force Field 
 252 Red Buoy and Green Buoy 
 250 Red Buoy and Force Field 
 246 Green Buoy and Force Field 
 254 Red Buoy, Green Buoy and Force 
 
 Roomba 500 Drive-on Charger
 160 Reserved 
 161 Force Field 
 164 Green Buoy 
 165 Green Buoy and Force Field 
 168 Red Buoy 
 169 Red Buoy and Force Field 
 172 Red Buoy and Green Buoy 
 173 Red Buoy, Green Buoy and Force Field
 
 Roomba 500 Virtual Wall
 162 Virtual Wall 
 
 Roomba 500 Virtual Wall Lighthouse ###### (FIXME: not yet supported here)
 0LLLL0BB 
 LLLL = Virtual Wall Lighthouse ID
 (assigned automatically by Roomba 
 560 and 570 robots) 
 1-10: Valid ID 
 11: Unbound 
 12-15: Reserved 
 BB = Which Beam
 00 = Fence 
 01 = Force Field 
 10 = Green Buoy 
 11 = Red Buoy
 
 */

IRsend irsend(5); //an IR led is connected to GPIO pin 4 (D2)
void setupIR() 
{
  
 pinMode(5, OUTPUT);
  digitalWrite(5, HIGH);
}


void SendRomba(int code){
  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH);
 roomba_send(code,39,3000,1100,50,3);
 roomba_send(code,38,3000,110,50,3);
 roomba_send(code,39,3000,1000,50,3);
 roomba_send(code,38,3000,1000,50,3);
 pinMode(5, OUTPUT);
  digitalWrite(5, LOW);
 delay(4000);
}

void roomba_send(int code, uint16_t freq,int pulse, int pbreak,int pdelay, int pcount) 
{
  Serial.print("Sending Roomba code ");
  Serial.print(code);
  int length = 8;
  uint16_t raw[length*2];
  unsigned int one_pulse = pulse;
  unsigned int one_break = pbreak;
  unsigned int zero_pulse = one_break;
  unsigned int zero_break = one_pulse;

  int arrayposition = 0;
  // Serial.println("");
  for (int counter = length-1; counter >= 0; --counter) {
    if(code & (1<<counter)) {  
      raw[arrayposition] = one_pulse;
      raw[arrayposition+1] = one_break;
    } 
    else {
      raw[arrayposition] = zero_pulse;
      raw[arrayposition+1] = zero_break;
    }
    arrayposition = arrayposition + 2;
  } 
  for (int i = 0; i < pcount; i++) {
    irsend.sendRaw(raw, ((uint16_t)15), freq);
    delay(pdelay);
  }
  Serial.println("");

  /*
  Serial.print("Raw timings:");
   for (int z=0; z<length*2; z++) {
   Serial.print(" ");
   Serial.print(raw[z]);
   }
   Serial.print("\n\n");
   */
}
