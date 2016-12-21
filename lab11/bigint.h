#include <string>
#include <vector>
using namespace std;

class BigInt {
   public:
      BigInt(string s);   // convert string to BigInt
      void println();     // print this BigInt and a newline
      void add(BigInt b); // add another BigInt to this one
   private:
   		vector<int> vec;
   		
      // whatever you need
};
