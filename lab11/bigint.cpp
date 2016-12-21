#include "bigint.h"
#include <vector>
#include <string>
#include <iostream>
#include <cmath>

BigInt::BigInt(string s){ 
	for(int i=s.size()-1; i>=0; i--)
	{
		char c = s[i];
		int digit = c - '0';
		vec.push_back(digit);
	}

};     // convert string to BigInt
		
void BigInt::println(){
	for(int i=vec.size()-1; i>=0; i--)
	{
		cout<< vec[i];
	}
	cout<<endl;
};     // print this BigInt and a newline

void BigInt::add(BigInt b){
	int diff = abs(vec.size() - b.vec.size());
	for (int i = 0; i<diff; i++)
	{
		if (vec.size() < b.vec.size())
			vec.push_back(0);
		else if (vec.size() > b.vec.size())
			b.vec.push_back(0);
	}	
	int carry= 0;
	for (unsigned int i = 0; i<vec.size(); i++)
	{
		int temp=vec[i]+b.vec[i]+carry;
		carry = temp / 10;
		vec[i]= temp %10;
		
	}
	
	if(carry>0)
	{
		vec.push_back(carry);
	}
		
};     // add another bigint to this one
