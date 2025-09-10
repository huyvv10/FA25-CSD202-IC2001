#include <iostream>
using namespace std;
class Node{
	public:
		int info;
		Node* next;
		Node(int data){
			this->info=data;
			this->next=nullptr;
		}	
};

class SinglyLinkedList{
	private:
		Node *head, *tail;
	public:
		SinglyLinkedList(){
			head=nullptr;
			tail=nullptr;
		}
		
		bool isEmpty(){
			return head==nullptr;
		}
		//Insert a node x into the begining of the list
		void addFirst(int x){
			Node* newNode = new Node(x);
			if (isEmpty())
				head=tail=newNode;
			else{
				newNode->next=head;
				head=newNode;
			}
		}
		
		//Insert a node x into the last of the list
		void addLast(int x){
			Node* newNode = new Node(x);
			if (isEmpty())
				head=tail=newNode;
			else {
				tail->next=newNode;
				tail=newNode;
			}	
		}
		// Count number of Nodes in the list
		int countNodes(){
			int count=0;
			Node* cur=head;
			while (cur!=nullptr){
				count++;
				cur = cur->next;
			}			
			return count;
		}
		void removeFirst(){
			
		}
		void removeLast(){
			
		}
		void removeAtPos(int pos){
			
		}
//		Insert node x into the position pos
		void addAtPos(int x, int pos){
			
		}
		//Traversal the list
		void display(){
			Node* cur=head;
			while (cur!=nullptr){
				cout << cur->info << " ";
				cur = cur->next;
			}
			cout<<endl;
		}
			
};

int main(){
	SinglyLinkedList myList;
	myList.addFirst(5);
	myList.addFirst(8);
	myList.addFirst(2);
	myList.addFirst(9);
	myList.display();
	
	myList.addLast(11);	
	myList.addLast(6);	
	myList.addLast(15);	
	myList.display();
	
	cout<<"Number of nodes: " << myList.countNodes() <<endl;
	return 0;
}
