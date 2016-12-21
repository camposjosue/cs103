//Josue Campos
#ifndef USER_H
#define USER_H
#include <string>
#include <vector>

using namespace std;

class User{
 public:
 		User(int id, string name, int year, int zip, vector<unsigned int> friends);
 		User(int id, string name, int year, int zip);
 		~User();
 		void add_friend(int id);
 		void delete_friend(int id);
 		int get_id();
 		string get_name();
 		int get_year();
 		int get_zip();
 		vector<unsigned int> get_friends();
	
 private:
 		int _id;
 		string _name;
 		int _year;
 		int _zip;
 		vector<unsigned int> _friends;

};


#endif
