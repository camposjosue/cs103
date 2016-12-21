#include "bmplib3.h"

class Turtle{
	public:
		Turtle(double r0, double c0, double d0);
		~Turtle();
		void move(double dist);
		void turn(double degree);
		void setColor(color c); // change line color that this Turtle draws from now on
		void off(); // make this Turtle stop drawing lines
		void on(); // make this Turtle resume drawing lines
	private:
		double row;
		double col;
		double degree;
		color fill;
		bool onoff;



};
