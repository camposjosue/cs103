#include <iostream>
using namespace std;

int main(){

int num;
cout << "Enter a natural number: ";

cin>> num;

int twoFactCounter=0;
int threeFactCounter=0;
;
while((num % 2 == 0) || (num % 3 ==0))
{
if (num % 2 == 0)
 {
 twoFactCounter++;
 num /= 2;
 }
else if (num % 3 == 0)
 {
 threeFactCounter++;
 num /= 3;  
 }

}


if(threeFactCounter == 0 && twoFactCounter == 0)
{
cout << "No!"<< endl;
}
else if (num!=1)
{
cout << "No!"<< endl;
}
else 
{

cout<< "Yes"<< endl;
cout<< "Twos=" << twoFactCounter << ", Threes=" << threeFactCounter << endl;
}
return 0;
}

