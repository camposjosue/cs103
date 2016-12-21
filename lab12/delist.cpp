#include "delist.h"
#include <stddef.h>
  
  
  
  /// Constructs an empty Double-Ended List
  DEList::DEList(){
  first = NULL;
  last = NULL;
  list_size=0;
  }
 
  /// Destructor to clean-up memory of current list
  DEList::~DEList(){
  DEItem* temp = first;
  	for(int i = 0; i< list_size; i++){
  		temp = first -> next;
  		delete first;
  		first = temp;
  	}
  }
  
  /// returns a Boolean 'true' if the list is empty
  bool DEList:: empty(){
 	 	if (list_size== 0)
  		return true;
  	else
  		return false;
  }
  
  /// returns number of items in the list
  int DEList::size(){
  	return list_size;
  }
  
  /// returns front item or -1 if empty list
  int DEList::front(){
  	if (list_size== 0)
  		return -1;
  	else
  		return first -> val;
  }
  
  /// returns back item or -1 if empty list
  int DEList::back(){
  	if (list_size== 0)
  		return -1;
  	else
  		return last -> val;
  }
  
  /// Adds a new integer to the front of the list
  void DEList::push_front(int new_val){
  	DEItem* front = new DEItem;
  	if (list_size== 0){
  		front -> val = new_val;
  		front -> prev = NULL;
  		first = front;
  		last = front;
  		list_size++;
  	}
  	else{
  		front -> val = new_val;
  		front -> prev = NULL;
  		front -> next = first;
  		first -> prev = front;
  		first = front;
  		list_size++;
  	}
  }
  
  /// Adds a new integer to the back of the list
  void DEList::push_back(int new_val){
  	DEItem* end = new DEItem;
  	if (list_size == 0){
  		end -> val = new_val;
  		end -> next = NULL;
  		last = end;
  		first = end;
  		list_size++;
  	}
  	else{
  		end -> val = new_val;
  		end -> next = NULL;
  	 	end -> prev = last;
  	 	last -> next = end;
  	 	last = end;
  		list_size++;
  	}
  
  }
  
  /// Removes the front item of the list (if it exists)
  void DEList::pop_front(){
  	if(list_size == 1){
  		delete first;
  		list_size--;
  		first = NULL;
  		last = NULL;
  	}
  	else if (list_size > 1){
  		first = first -> next;
  		delete first -> prev;
  		first -> prev =NULL;
  		list_size--;
  		
  	}
  }
  
  /// Removes the back item of the list (if it exists)
  void DEList::pop_back(){
  	if(list_size == 1){
  		delete first;
  		list_size--;
  		first = NULL;
  		last = NULL;
  	}
  	else if (list_size > 1){
  		last = last -> prev;
  		delete last -> next;
  		last -> next =NULL;
  		list_size--;
  	}
  }

