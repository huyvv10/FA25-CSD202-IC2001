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
			//Is the list empty
			if (isEmpty())
			{
				cout<<"The list is empty";
				return;
			}
			//The list has only a node.
			if (head->next==nullptr){
				head=tail=nullptr;
				cout<<"The list is empty now";
				return;
			}	
			//Has many node
			head=head->next;	//Move head to the next node				
		}
		//Remove the last node in the list
		void removeLast(){
			//Is the list empty
			if (isEmpty())
			{
				cout<<"The list is empty";
				return;
			}
			//The list has only a node.
			if (head->next==nullptr){
				head=tail=nullptr;
				cout<<"The list is empty now";
				return;
			}
			//The list has many nodes
			Node* cur=head;
			while (cur->next!=tail)	{//cur->next->next != nullptr	
				cur=cur->next;
			}
			cur->next = nullptr;
			tail=cur;					
		}
		
		void removeAtPos(int pos){
			int size=countNodes();
			if (pos<0 || pos>=size) {
				cout<<pos<<" is out of range.\n";
				return;
			}		
			if (pos==0) {
				removeFirst(); return;	
			}
			if (pos==size-1){
				removeLast(); return;
			}
			int i=0;
			Node* cur=head;
			while (i+1!=pos){
				cur=cur->next;
				i++;
			}
			cur->next = cur->next->next;
		}
		
//		Insert node x into the position pos
		void addAtPos(int x, int pos){
			int size=countNodes();
			if (pos<0 || pos >size){
				cout<<pos<<" is out of range.\n";
				return;
			}
			if (pos==0) {
				addFirst(x); return;
			}
			if (pos==size){
				addLast(x); return;
			}
			int i=0; 
			Node* cur=head;
			while (i+1 != pos){
				cur=cur->next;
				i++;
			}
			Node* newNode = new Node(x);
			newNode->next = cur->next;
			cur->next = newNode;
		}
		
		int getValueAtFirst(){
			if (isEmpty()){
				cout<<"The list is empty.\n";
				return -999;
			}
			return head->info;
		}
		
		int getValueAtLast(){
			if (isEmpty()){
				cout<<"The list is empty.\n";
				return -999;
			}
			return tail->info;
		}
		
		int getValueAtPos(int pos){
			if (isEmpty()){
				cout<<"The list is empty.\n";
				return -999;
			}
			int size=countNodes();
			if (pos<0 || pos>=size){
				return -999;
			}
			Node* cur=head;
			int i=0;
			while (i != pos){
				cur=cur->next;
				i++;
			}
			return cur->info;			
		}	
		
		void editNodeAtFirst(int x){
			if (isEmpty()) return;
			head->info=x;
		}
		
		void editNodeAtLast(int x){
			if (isEmpty()) return;
			tail->info=x;		
		}
		
		void editNodeAtPos(int x, int pos){
			
		}
		//Sort the list in ascending order
		void sortListAsc(){
			
		}
		//Sort the list in descending order
		void sortListDesc(){
			
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
//	cout<<"\nRemove first:\n";
//	myList.removeFirst();
//	myList.display() ;
//	cout<<"\nRemove last:\n";
//	myList.removeLast();
//	myList.display() ;	
//	cout<<"\nRemove at pos:\n";
//	int pos;
//	cout<<"Input position to remove node: "; cin>>pos;
//	myList.removeAtPos(pos);
//	myList.display() ;	
//	cout<<"\nAdd node at pos:\n";
//	int pos, x;
//	cout<<"Input x = "; cin>>x;
//	cout<<"Input position to add pos = "; cin>>pos;
//	myList.addAtPos(x,pos);
//	myList.display() ;	
	cout<<"The value at first is: "<<myList.getValueAtFirst()	<<endl;
	cout<<"\nGet value at pos:\n";
	int pos;
	cout<<"Input position to get value: "; cin>>pos;	
	int rs = myList.getValueAtPos(pos);
	if (rs!=-999)
		cout<<"Value at " <<pos<< " is: "<<rs<<endl;
	else
		cout<<pos<<" is out of range." <<endl;
	return 0;
}
