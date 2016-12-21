//Josue Campos
#ifndef USER_H
#define USER_H
#include <string>
#include <vector>

using namespace std;

class User{
 public:
 		User(int id, string name, int year, int zip, vector<int> friends);
 		User(int id, string name, int year, int zip);
 		~User();
 		void add_friend(int id);
 		void delete_friend(int id);
 		int get_id();
 		string get_name();
 		int get_year();
 		int get_zip();
 		vector<int> get_friends();
 		int group;
		int depth;
		int predecessor;
		int score;
		int* get_score();
		const vector<int>& get_friends_const();
 private:
 		int _id;
 		string _name;
 		int _year;
 		int _zip;
 		vector<int> _friends;

};


#endif
