// wscramble.cpp
// Word Scramble guessing game
// Illustrates string library functions, character arrays,
//  arrays of pointers, etc.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstring>

using namespace std;

// Prototype
void permute(char items[], int len);

// Define an array of strings (since a string is just a char array)
//  and since string are just char *'s, we really want an array of char *'s



int main(int argc, char *argv[])
{

 
  srand(time(0));
  char guess[80];
 	
 	ifstream ifile (argv[1]); 
 	
 	if (argc<2){
 		cout<<"not enoough arguments"<<endl;;
 		return 0;
 	}
 	if (ifile.fail()){
 		cout << "you suck! command line argument failed"<<endl;
 		return 0;
 	}
 	
 	int numWords;
 	if (!(ifile>>numWords)){
 		cout<<"No work..."<<endl;
 		ifile.close();
 		return 0;
 	}
 	
	char** wordbank = new char*[numWords];
	char buffer[41];
	for(int i=0; i < numWords; i++){
		ifile>>buffer;
		int len = strlen(buffer);
		wordbank[i] = new char[len + 1];
		strcpy(wordbank[i], buffer); 
	}

	ifile.close();
 	
  bool wordGuessed = false;
  int numTurns = 10;

  // Pick a random word from the wordbank
  int target = rand() % numWords;
  int targetLen = strlen(wordbank[target]);

  // More initialization code
  char* word = new char[targetLen+1];
  strcpy(word, wordbank[target]);
  permute(word, targetLen);
  
  // An individual game continues until a word
  //  is guessed correctly or 10 turns have elapsed
  while ( !wordGuessed && numTurns > 0 ){
    cout << "\nCurrent word:  " << word << endl;
    cin >> guess;
    wordGuessed = (strncmp(guess, wordbank[target], targetLen+1) == 0);
    numTurns--;
  }
  if(wordGuessed){
    cout << "You win!" << endl;
  }
  else {
    cout << "Too many turns...You lose!" << endl;
  }
  
  for(int i=0; i< numWords; i++){
  	delete [] wordbank[i];
  }
  
  delete [] word;
  delete [] wordbank;
  return 0;
}

// Scramble the letters
void permute(char items[], int len)
{
  for(int i=len-1; i > 0; --i){
    int r =  rand() % i;
    int temp = items[i];
    items[i] = items[r];
    items[r] = temp;
  }

}

