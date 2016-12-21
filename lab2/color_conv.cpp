#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  double red;
  double green;
  double blue;
  cout << "R Component";
  cin >> red;
  cout << "G Component";
  cin >> green;
  cout << "B Component";
  cin >> blue;

 double cyan;
 double magenta;
 double yellow;
 double black;

  double redmax = (red/255.0);
  double greenmax = (green/255.0);
  double bluemax = (blue/255.0);


double white1 = max(redmax,greenmax);
double white2 = max(white1, bluemax);

  cyan = (white2-redmax)/white2;
  magenta = (white2-greenmax)/white2;
  yellow = (white2-bluemax)/white2;
  black = 1-white2;

  cout << "C=" << cyan << " M=" << magenta << " Y=" << yellow << " K=" << black << endl;


  return 0;
}
