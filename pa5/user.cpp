//Josue Campos

#include "user.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;


User::User(int id, string name, int year, int zip, vector<int> friends){
	_id=id;
	_name=name;
	_year=year;
	_zip=zip;
	_friends=friends;
};

User::User(int id, string name, int year, int zip){
	_id=id;
	_name=name;
	_year=year;
	_zip=zip;
};

User::~User(){};

void User::add_friend(int id){
	_friends.push_back(id);
}; 


void User::delete_friend(int id){
	for(unsigned int i=0; i <_friends.size(); i++){
		if((int)_friends[i]==id){
			_friends.erase(_friends.begin()+i);
			return;
		}
	}
	cout<< "Friend Connection Does not exist"<< endl;
};
 		
int User::get_id(){
	return _id;
};

string User::get_name(){
	return _name;
};

int User::get_year(){
	return _year;
};

int User::get_zip(){
	return _zip;
};

vector<int> User::get_friends(){
	return _friends;
};

const vector<int>& User::get_friends_const(){
	return _friends;
};

int* User::get_score(){
	return &score;
};
