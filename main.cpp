#include "LinkedList.h"

using namespace std;

int main(){
	
	SLL<string> L1;
	
	while(true){
		int choice;
		cout << "1. Add New Item\n";
		cout << "2. Delete Back\n";
		cout << "3. Delete Position\n";
		cout << "4. Delete Front\n";
		cout << "5. Search Data\n";
		cout << "6. Print LL\n";
		cin >> choice;
		
		switch(choice){
			case 1:{
				L1.addNewItem();
				break;
			}
			case 2:{
				L1.deleteBack();
				break;
			}
			case 3:{
				L1.deletePosition();
				break;
			}
			case 4:{
				L1.deleteFront();
				break;
			}
			case 5:{
				L1.search();
				break;
			}
			case 6:{
				L1.printLinkedList();
				break;
			}
		}
	}
	return 0;
}