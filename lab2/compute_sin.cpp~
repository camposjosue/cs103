#include <iostream>
#include <cmath>

using namespace std;

// Declaration (function prototype for fact)
int fact(int);

int main(int argc, char *argv[])
{
  double x; // Declare any other variables you need here
  double answer;// and/or delete the integer declared below 

  // Prompt the user
  cout << "Enter x in radians:  ";
  
  cin >> x;// get input

  answer = x -(pow(x,3)/fact(3))+(pow(x,5)/fact(5))-(pow(x,7)/fact(7));// Do some operations


  cout << "sin(x) is approximately " << answer << endl;// Print the result to the user

  
  // You're done
  return 0;
  
}


int fact(int n)
{
  int i;
  int result=1;
  for(i=1; i <= n; i++){
    result = result * i;
  }
  return result;
}

