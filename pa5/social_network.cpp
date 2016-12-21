//Josue Campos

#include "network.h"
#include "user.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>

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
		cout<<"Option #5: List Friends (Name)"<<endl;
		cout<<"Option #6: Write to File"<<endl;
		cout<<"Option #7: Shortest Path (Name 1, Name 2)"<<endl;
		cout<<"Option #8: Disjoint Sets" <<endl;
		cout<<"Option #9: Friend Suggestions (Name)"<<endl;
		cout<<"Option #10: Exit the Pogram"<<endl;
		
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
			vector<int> temp1=social_network.get_user_friends(newid);
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
			
			if(social_network.get_id(name1)==-1 )
				cout << "Could not find " << name1;
			if(social_network.get_id(name1)==-1 )
				cout << "Could not fine " << name2;	
				
			vector<int> bfsq=social_network.shortest_path(id2,id1);
			
			vector<User> temp = social_network.get_network();
			
			cout<< name1;
			for(unsigned int i=0; i<bfsq.size(); i++){
				for(unsigned int j=0; j<temp.size(); j++){
					if(bfsq[i]==temp[j].get_id())
						cout<<" -> "<<temp[j].get_name();
				}
			
			}
			cout<<endl;
			
			
		
		}
		else if(option==8){	
			vector<vector<int> > temp = social_network.groups();
			//vector<User> social = social_network.get_network();
			//cout<< temp.size()<< endl;
			//for(unsigned int i=0; i < temp.size(); i++){
				//cout<< "Set "<<i << " => ";
				//for(unsigned int j=0; j<temp[i].size(); j++){
					//for(unsigned int k=0; k<social.size(); k++){
						//if(temp[i][j]== social[k].get_id()){
							//cout<< social[k].get_name()<< ", ";
					//}
					//}
				//}
				//cout<<endl;
			//}
		}
		else if(option==9){
			string name1;
			string name1a;
			string name1b;			
			cin>>name1a>>name1b;
			name1= name1a +" "+name1b;
			int num=0;
			
			int newid=social_network.get_id(name1);
			vector<User> temp = social_network.get_network();
			
			vector<int> sugg = social_network.suggest_friends(newid, *temp[newid].get_score());
			cout << "The suggested friend(s) is/are: " << endl;
			for(unsigned int i=0; i<sugg.size(); i++){
				for(unsigned int j=0; j<temp.size(); j++){
					if(temp[j].get_id()==sugg[i]){
						cout<<'\t'<<setw(30)<<left<<temp[j].get_name();	
						
						vector<int> who_friends = temp[newid].get_friends();
	
						for(unsigned int k=0; k<who_friends.size(); k++){
							vector<int> sugg_friends = temp[sugg[k]].get_friends();
							for(unsigned int l=0; l<sugg_friends.size(); l++){
								if(who_friends[k]==sugg_friends[l]){
									num++;
								}
							}
						}
						cout<<setw(10)<<left<<"Score: "<< num<<endl;
						num=0;
					}
				}	
			}
		}
		else if(option==10){
			return -1;
		}
	}
}
