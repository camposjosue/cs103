//Josue Campos
#include "user.h"
#include "network.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

Network::Network(){};

Network::~Network(){};

int Network::read_friends(char* fname){
	int num_users;
	string name1;
	string name2;
	int id;
	int year;
	int zip;
	vector<unsigned int>friends;
	int n;
	ifstream ifile(fname); 
	if (ifile.fail()){
 		cout << "could not read file"<<endl;
 		return -1;
 	} 

 	if(ifile.good()){
 		ifile>>num_users;
 		for(int i=0; i<num_users; i++){
 			ifile>> id;
 			ifile>> name1;
 			ifile>> name2;
 			string name = name1 +" "+name2;
 			ifile>> year;
 			ifile>> zip;
 			for(int i=0; i<1; i++){
 				ifile.get();
 			}
 			User temp(id, name, year, zip, friends);
 			while(ifile.peek() != EOF && ifile.peek()!='\n'){
 				ifile>>n;
 				temp.add_friend(n);
 			}	
 			_network.push_back(temp);
 		}
 	}
 	return 0;
};
int Network::write_friends(char *fname){
	ofstream output (fname); 
	output<<_network.size()<<endl;
	for(unsigned int i=0; i<_network.size(); i++){
		output<<_network[i].get_id()<<endl;
		output<<'\t'<<_network[i].get_name()<<endl;
		output<<'\t'<<_network[i].get_year()<<endl;
		output<<'\t'<<_network[i].get_zip()<<endl;
		output<<'\t';
		
		int size = _network[i].get_friends().size();
		for(int j = 0; j<size; j++){
			output<<_network[i].get_friends()[j];
			if(j != size-1)
				output << " ";
		}
		output<<endl;
	}
	output.close();
	return 0;
};

void Network::add_user(int id, string name, int year, int zip){
	User person= User(id, name, year, zip);
	//cout<<_network.size()<<endl;
	_network.push_back(person);
	//cout<<_network.size()<<endl;
};

int Network::add_connection(int id1, int id2){
	bool id_1;
	bool id_2;
	unsigned int loop = _network.size();
	for(unsigned int i=0; i<loop; i++){
	//cout << "looping through all users" << endl;
		if(_network[i].get_id()==id1){
			_network[i].add_friend(id2);
			id_1=true;
			//cout<<"found id1"<<endl;
		}
		if(_network[i].get_id()==id2){
			_network[i].add_friend(id1);
			id_2=true;
			//cout<<"found id2"<<endl;
		}
	}
	if(id_1 == true && id_2 == true)
		return 0;
	else
		return -1;
};

int Network::remove_connection(int id1, int id2){
	//cout << "removing connecton between " << id1 << " and " << id2<< endl;
unsigned int loop = _network.size();
	for(unsigned int i=0; i<loop; i++){
	//cout << "looping through all users" << endl;
		if(_network[i].get_id()==id1){
			_network[i].add_friend(id2);
			//cout<<"found id1"<<endl;
		}
		if(_network[i].get_id()==id2){
			_network[i].add_friend(id1);
			//cout<<"found id2"<<endl;
		}
	}
	return 0;
};

int Network::get_id(string name1){
	for(int i=0; i<(int)_network.size(); i++){
		string name2 = _network[i].get_name();
		if(name1 == name2){
			return _network[i].get_id();
		}
	}
	return -1;
};

int Network::get_network_size(){
	return _network.size();
};

vector< unsigned int> Network::get_user_friends(int id){
	for(int i=0; i< (int)_network.size(); i++){
		if(_network[i].get_id()==id){
			return _network[i].get_friends();
		}
	}
	vector<unsigned int> temp;
	temp.push_back(0);
	return temp;
};

vector<User> Network::get_network(){
	return _network;
};




