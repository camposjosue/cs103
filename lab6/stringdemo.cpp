#include <iostream>
#include <cstring>
 
 using namespace std;

 int main()
{
 char mystring[80] = "ComputerScience";
 char yourstring[80];
 char* astring = 0;

 //yourstring = mystring; 
 //strncpy(astring, mystring, 80);

 astring = mystring; // make a copy?
 strncpy(yourstring, mystring, 80); // make a copy?
 cout << astring << endl;
 cout << yourstring << endl;

 mystring[0] = '*'; // which one actually made a copy?
 cout << astring << endl;
 cout << yourstring << endl;

 return 0;
}
