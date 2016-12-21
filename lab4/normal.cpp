#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;
int roll(){
	return(( rand() % 6) +1);
}
void printHistogram(int counts[]){

	for (int i=4; i<= 24; i++){
		cout<< i <<":";
		for(int j=0; j< counts[i]; j++){
			cout<< "X";
		}
		cout << endl;
	}
}



int main (){

srand(time(0));
	int n;
	cout << "How many experiments would you like to conduct? ";
	cin >> n;

	int counts[25];
counts[4]=0;
counts[5]=0;
counts[6]=0;
counts[7]=0;
counts[8]=0;
counts[9]=0;
counts[10]=0;
counts[11]=0;
counts[12]=0;
counts[13]=0;
counts[14]=0;
counts[15]=0;
counts[16]=0;
counts[17]=0;
counts[18]=0;
counts[19]=0;
counts[20]=0;
counts[21]=0;
counts[22]=0;
counts[23]=0;
counts[24]=0;


	for (int i=0; i<n; i++){
		int dice[4];
		dice[0] = roll();
		dice[1] = roll();
		dice[2] = roll();
		dice[3] = roll();
		int sum=(dice[0]+dice[1]+dice[2]+dice[3]);
		counts[sum]++;
	}
	printHistogram(counts);

	return 0;
}



/*int main (){
srand(time(NULL));

int testCounts[100];

for (int i=4; i<=24; i++){
testCounts[i] = i/2; 
}
printHistogram(testCounts); 


return 0;
}
*/

