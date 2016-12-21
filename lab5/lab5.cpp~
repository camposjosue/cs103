#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

unsigned char image[SIZE][SIZE];

// Prototypes
void draw_rectangle(int top, int left, int height, int width);
void draw_ellipse(int cy, int cx, int height, int width);


int main()
{ 

int top;
int left;
int height;
int width;
int cx;
int cy;
  // initialize the image to all white pixels
 for(int i=0; i < SIZE; i++){
    for(int j=0; j < SIZE; j++){
      image[i][j] = 255;
    }
  }
//draw_rectangle(10, 10, 20, 20);
  // Main program loop here

  int command;
  

  while(command != 2){

  cout << "Type '0' to draw a rectangle" << endl;
  cout << "Type '1' to draw an ellipse" << endl;
  cout << "Type '2' to quit" <<endl;
  cin >> command;

    if (command == 0) {
      cout<< "Enter Top, Left, Height, Width seperated by a space" << endl;
      cin>> top >> left >> height >> width;
      draw_rectangle(top, left, height, width);
    }
    if (command == 1){
      cout<< "Enter CY, CX, Height, Width seperated by a space" << endl;
      cin>> cy >> cx >> height >> width;
      draw_ellipse( cy, cx, height, width);
    }

  // Write the resulting image to the .bmp file
  writeGSBMP("output.bmp", image);
  }

writeGSBMP("output.bmp", image);
  return 0;
}

void draw_rectangle(int top, int left, int height, int width)
{
  for(int i=top; i <=top + height; i++){
    for(int j=left; j <= left + width; j++){
      if(i==top || i==top+height){
        if( (i>=0 && j >=0) && (i <= 255 && j <= 255) ){
      	image[i][j]=0;
        }
      }
      if((j==left && i!=top && i!=top+height)||(j==left+width && i!=top && i!=top+height)){
        if( (i>= 0 && j >=0) && (i <= 255 && j <= 255) ){
          image[i][j]=0;
        }
      }
    }
  //showGSBMP(image);
}
}
void draw_ellipse(int cy, int cx, int height, int width)
{
  double a = height/2;
  double b = width/2;

  for(double theta = 0; theta <= 2*M_PI; theta+=.01){

    double x = (a*cos(theta))+cx;
    double y = (b*sin(theta))+cy;
    
//cout<< x << " " << y << endl;
    if( (x>= 0 && y >=0) && (x <= 255 && y <= 255) ){
    image[int(x)][int(y)]=0;
    }
  }
  //showGSBMP(image);
}
