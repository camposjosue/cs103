#include "turtle.h"
#include <cmath>

Turtle::Turtle(double r0, double c0, double d0){
	row=r0;
	col=c0;
	degree=d0;
	fill=white;
	onoff=true;
};
		
Turtle::~Turtle(){
};

void Turtle::move(double dist){
	double rend=dist*cos(degree*(M_PI/180))+row;
	double cend=dist*sin(degree*(M_PI/180))+col;
	if(onoff)
	{
		std_draw_line(fill, row, col, rend, cend);
	}
	row=rend;
	col=cend;
};

void Turtle::turn(double d0){
	degree+=d0;
};

void Turtle::setColor(color c){
	fill=c;
};

void Turtle::off(){
	onoff=false;
};

void Turtle::on(){
	onoff=true;
};

