//Josue Campos

#include "network.h"
#include "user.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;


int main(int argc, char *argv[])
{
	int option;

	Network social_network;
	social_network.read_friends(argv[1]);
	
	
	while(1){
		cout<<endl;
		cout<<"Option #1: Add User (Name, Year, Zip)"<<endl;
		cout<<"Option #2: Add Friend Connection (Name 1, Name 2)"<<endl;
		cout<<"Option #3: Remove Friend Connection (Name 1, Name 2)"<<endl;
		cout<<"Option #4: Print Users"<<endl;
		cout<<"Option #5: List Friends"<<endl;
		cout<<"Option #6: Write to File"<<endl;
		cout<<"Option #7: Exit the Pogram"<<endl;
		
		cin>>option;
		
		if(option==1){
			string name1;
			string name1a;
			string name1b;			
			cin>>name1a>>name1b;
			name1= name1a +" "+name1b;
			
			int year;
			cin>>year;
			
			int zip;
			cin>>zip;
			
			int newid=social_network.get_network_size();
			
			social_network.add_user(newid, name1, year, zip);
			
		}
		else if(option==2){
			string name1;
			string name1a;
			string name1b;
			string name2;
			string name2a;
			string name2b;
			
			cin>>name1a>>name1b;
			cin>>name2a>>name2b;
			name1= name1a +" "+name1b;
			name2= name2a +" "+name2b;
			
			//cout<<name1<<endl;
			//cout<<name2<<endl;
			
			int id1= social_network.get_id(name1);	
			int id2= social_network.get_id(name2);
			
			if(social_network.get_id(name1)==-1 )
				cout << "Could not find " << name1;
			if(social_network.get_id(name1)==-1 )
				cout << "Could not fine " << name2;		
			//cout<<id1<<endl;
			//cout<<id2<<endl;
			
			social_network.add_connection(id1,id2);
			
		}
		else if(option==3){
			string name1;
			string name1a;
			string name1b;
			string name2;
			string name2a;
			string name2b;
			
			cin>>name1a>>name1b;
			cin>>name2a>>name2b;
			name1= name1a +" "+name1b;
			name2= name2a +" "+name2b;
			
			int id1= social_network.get_id(name1);	
			int id2= social_network.get_id(name2);
			
			social_network.remove_connection(id1,id2);
			if(social_network.remove_connection(id1,id2) == -1)
				cout<< "Could not remove friend!";
		
		}
		else if(option==4){
			vector<User> temp=social_network.get_network();	
			cout<<endl;
			cout<<setw(5)<<left<<"ID";
			cout<<setw(25)<<left<<"Name";
			cout<<setw(10)<<left<<"Year";
			cout<<setw(10)<<left<<"Zip"<<endl;
			for(int i=0; i<50; i++){
			cout<<"=";
			} cout<<endl;
			for(unsigned int i=0; i<temp.size(); i++){
				cout<<setw(5)<<left<<temp[i].get_id();
				cout<<setw(25)<<left<<temp[i].get_name();
				cout<<setw(10)<<temp[i].get_year();
				cout<<setw(10)<<temp[i].get_zip()<<endl;
				
			}
		}
		else if(option==5){
			string name1;
			string name1a;
			string name1b;			
			cin>>name1a>>name1b;
			name1= name1a +" "+name1b;
			
			int newid=social_network.get_id(name1);
			if(newid == -1){
				cout<< "User does not exist!";
				break;
			
			}
			vector<unsigned int> temp1=social_network.get_user_friends(newid);
			//cout<<"temp1 size"<<temp1.size()<<endl;
			vector<User> temp2=social_network.get_network();
			
			cout<<endl;
			cout<<setw(5)<<left<<"ID";
			cout<<setw(25)<<left<<"Name";
			cout<<setw(10)<<left<<"Year";
			cout<<setw(10)<<left<<"Zip"<<endl;
			for(int i=0; i<50; i++){
			cout<<"=";
			} cout<<endl;
			
			for(unsigned int i=0; i<temp1.size(); i++){
				for(unsigned int j=0; j<temp2.size(); j++){
					if(temp2[j].get_id()==(int)temp1[i]){
						cout<<setw(5)<<temp2[j].get_id();
						cout<<setw(25)<<temp2[j].get_name();
						cout<<setw(10)<<temp2[j].get_year();
						cout<<setw(10)<<temp2[j].get_zip()<<endl;
					}
				}
			}
		
		}
		else if(option==6){
			char fname [100];
			cin>> fname;
			
			social_network.write_friends(fname);
		}
		else if(option==7){
			return -1;
		}
	}
}
