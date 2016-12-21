#include "bmplib3.h"
#include "turtle.h"

int main() {
   Turtle shelly((SIZE/2)-80, (SIZE/2)+25, 0); 
   shelly.setColor(green);
   shelly.move(100);
   shelly.turn(90);
   shelly.move(100);
   shelly.turn(90); // direction is now 0+90+120 = 210
   shelly.move(100);
   shelly.turn(45);
   shelly.move(70);
   shelly.turn(90);
   shelly.move(70); 
   std_show();
   shelly.setColor(white);
	 shelly.off();
	 shelly.move(50);
	 shelly.turn(45);
	 shelly.on();
   shelly.move(100);
   shelly.turn(90);
   shelly.move(100);
   shelly.turn(90); // direction is now 0+90+120 = 210
   shelly.move(100);
   shelly.turn(45);
   shelly.move(70);
   shelly.turn(90);
   shelly.move(70); 
   std_show();
   shelly.setColor(red);
   shelly.off();
	 shelly.move(50);
	 shelly.turn(45);
	 shelly.on();
   shelly.move(100);
   shelly.turn(90);
   shelly.move(100);
   shelly.turn(90); // direction is now 0+90+120 = 210
   shelly.move(100);
   shelly.turn(45);
   shelly.move(70);
   shelly.turn(90);
   shelly.move(70); 
   std_show();
   shelly.setColor(white);
   shelly.off(); 
   shelly.turn(-90);
   shelly.move(50);
   shelly.turn(135);
   shelly.on();
   shelly.move(100);
   shelly.turn(90);
   shelly.move(100);
   shelly.turn(90); // direction is now 0+90+120 = 210 
   shelly.move(100);
   shelly.turn(45);
   shelly.move(70);
   shelly.turn(90);
   shelly.move(70); 
   std_show();
   shelly.setColor(green);
   shelly.off();
   shelly.turn(-90);
   shelly.move(50);
   shelly.turn(135);
   shelly.on();
   shelly.move(100);
   shelly.turn(90);
   shelly.move(100);
   shelly.turn(90); // direction is now 0+90+120 = 210
   shelly.move(100);
   shelly.turn(45);
   shelly.move(70);
   shelly.turn(90);
   shelly.move(70); 
   std_show();
   return 0;
}
