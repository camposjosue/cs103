//Josue Campos
#ifndef NETWORK_H
#define NETWORK_H
#include <string>
#include "user.h"
#include <vector>

using namespace std;

class Network {
 public:
 		Network();
 		~Network();
 		void add_user(int id, string name, int year, int zip);
 		int add_connection(int id1, int id2);
 		int remove_connection(int id1, int id2);
 		int get_id(string name);
 		int read_friends(char* fname);
 		int write_friends(char *fname);
 		int get_network_size();
 		vector<int> get_user_friends(int id);
 		vector<User> get_network();
 		vector<int> shortest_path(int from, int to);
 		vector<vector<int> > groups();
 		vector<int> suggest_friends(int who, int& score);
 		
 private:
 		vector<User> _network;
};


#endif
