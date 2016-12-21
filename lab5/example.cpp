#include <iostream>
#include <cmath>
#include <cstdlib>
#include "bmplib.h"

using namespace std;

int main()
{
   unsigned char srcImage[SIZE][SIZE];
   unsigned char dstImage[SIZE][SIZE];
   readGSBMP("elephant.bmp", srcImage);
   for(int i=0; i<SIZE; ++i)
   {
      for(int j=0; j<SIZE; ++j)
      {
         if (i<SIZE/2) dstImage[i][j] = srcImage[i*2][j];
         else dstImage[i][j] = 0;
         //dstImage[i][j] = srcImage[255 -i][j];
	//image[i][j]= i;
      }
   }
showGSBMP(dstImage);
return 0;
}
