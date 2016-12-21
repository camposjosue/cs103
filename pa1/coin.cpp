#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
double fairness;

cout <<"fairness: ";
cin>> fairness;
srand(time(0));
	int random=rand() % 100+1;
if (random<= (fairness*100)){
cout << "heads ";
}
else{
cout << "tails ";
}

}
