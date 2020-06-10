#include <iostream>
#include <string>


template<typename T>
class Node{
	public:
		void setNodeData(T data);
		T getNodeData();
		void setNextNode(Node<T> * n);
		Node<T>* getNextNode();
		T getDataUI();
		
	private:
		T data;
		Node* nextNode;
};

template<typename T>
void Node<T>::setNodeData(T data){
	this->data = data;
}

template<typename T>
T Node<T>::getNodeData(){
	return this->data;
}

template<typename T>
void Node<T>::setNextNode(Node<T> * n){
	this->nextNode = n;
}

template<typename T>
Node<T>* Node<T>::getNextNode(){
	return this->nextNode;
}

template<typename T>
T Node<T>::getDataUI(){
	T data;
	std::cout << "Node Data : ";
	std::cin >> data;
	return data;
}







template<typename T>
class SLL{
	public:
		SLL();
		void addNewItem();
		void printLinkedList();
		void deleteBack();
		std::string Name;
		void deletePosition();
		void deleteFront();
		void search();
		int getSize();
		Node<T>* getHead();
		
	private:
		Node<T>* head;
		int size;
};







template<typename T>
SLL<T>::SLL(){
	head = NULL;
	size = 0;
	std::cout << "Linked List Name : ";
	std::getline(std::cin, this->Name);
}


template<typename T>
void SLL<T>::addNewItem(){
	
	Node<T>* temp = new Node<T>();
	T d = temp->getDataUI();
	temp->setNodeData(d);
	
	Node<T>* counter = head;
	
	if(head == NULL){
		head = new Node<T>();
		head->setNodeData(d);
	}
	else{
		while(counter->getNextNode() != NULL){
			counter = counter->getNextNode();
		}
		counter->setNextNode(temp);
	}
	
	size++;
}

template<typename T>
void SLL<T>::printLinkedList(){
	std::cout << "Printing Linked List : " << this->Name << std::endl;
	
	if(head == NULL)std::cout << "List is Empty!\n";
	
	else{
		Node<T>* temp = head;
		
		for(int i = 0; temp != NULL; i++){
			std::cout << "Position " << i << " : " << temp->getNodeData() << std::endl;
			temp = temp->getNextNode();
		}
	}
}
	
template<typename T>
void SLL<T>::deleteBack(){
	if(head == NULL){
		std::cout << "List Empty!\n";
	}
	else if(head->getNextNode() == NULL){
		head = NULL;
	}
	else{
		Node<T>* prev;
		Node<T>* temp = head;
		while(temp->getNextNode() != NULL){
			prev = temp;
			std::cout << "Moving from data : " << temp->getNodeData() << std::endl;
			temp = temp->getNextNode();
		}
		std::cout << "Deleting Data : " << temp->getNodeData() << std::endl;
		temp = NULL;
		prev->setNextNode(NULL);
		size--;
	}
}

template<typename T>
void SLL<T>::deletePosition(){
	if(head == NULL)std::cout << "Empty List!\n";
	else{
		Node<T>*temp = head;
		for(int i = 0; temp != NULL; i++){
			std::cout << i << " : " << temp->getNodeData();
			if(i != size - 1)std::cout << " , ";
			temp = temp->getNextNode();
		}
		std::cout << std::endl;
		
		temp = head;
		int pos;
		std::cout << "Position to Delete : ";
		std::cin >> pos;
		if(pos > 0 && pos <= size){
			std::cout << "Deleting position " << pos << std::endl;
			Node<T>* temp2;
			for(int i = 0; i < pos; i++){
				temp2 = temp;
				temp = temp->getNextNode();
			}
			if(temp->getNextNode() != NULL){
				temp2->setNextNode(temp->getNextNode());
				delete temp;
			}
			else{
				delete temp;
				temp2->setNextNode(NULL);
				
			}
			size--;
		}
		else if(pos == 0){
			Node<T>* temp = head;
			if(head->getNextNode() != NULL){
				head = head->getNextNode();
				delete temp;
			}
			else{
				delete temp;
				head = NULL;
			}
			size--;
		}
		else{
			std::cout << "Invalid Position... Would you like to try again? : ";
			std::string ans;
			std::cin >> ans;
			if(ans == "Y" || ans == "y" || ans == "Yes" || ans == "yes")this->deletePosition();
		}
	}
	std::cout << "New Size : " << size << std::endl;
}

template <typename T>
void SLL<T>::deleteFront(){
	if(head == NULL)std::cout << "Empty List!" << std::endl;
	else if(head->getNextNode() == NULL){
		delete head;
		head = NULL;
	}
	else{
		Node<T>*temp = head;
		head = head->getNextNode();
		delete temp;
		size--;
	}
}

template<typename T> 
void SLL<T>::search(){
	T data;
	std::cout << "Data to search for : ";
	std::cin.ignore();
	std::getline(std::cin, data);
	int count = 0;
	Node<T>* temp = head;
	for(int i = 0; i < size; i++){
		if(temp->getNodeData() == data){
			std::cout << "Position " << i << " : " << data << std::endl;
			count++;
		}
		temp = temp->getNextNode();
	}
}

template<typename T>
Node<T>* SLL<T>::getHead(){
	return this->head;
}

template<typename T>
int SLL<T>::getSize(){
	return this->size;
}