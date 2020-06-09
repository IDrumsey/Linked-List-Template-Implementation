#include "LinkedList.h"

using namespace std;

int main(){
	
	SLL<string> L1;
	
	while(true){
		int choice;
		cout << "1. Add New Item\n";
		cout << "2. Print LL\n";
		cin >> choice;
		
		switch(choice){
			case 1:{
				L1.addNewItem();
				break;
			}
			case 2:{
				L1.printLinkedList();
				break;
			}
		}
	}
	return 0;
}