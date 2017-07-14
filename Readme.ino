/*
MQTT Roomba Control for iRobot 621 (should also work for other)

Credits for Roomba basic to https://gist.github.com/probonopd/5181021
For some strange reason only the current implementation works.

Temperature currenlty with BMP180.

First implementation was with Telegram bot library. All bot releated was moved to Nodered.



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





*/
