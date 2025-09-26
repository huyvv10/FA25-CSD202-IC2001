#include <iostream>
using namespace std;
class Node{
	public:		
		int info;
		Node* prev, *next;
		Node(int _info){
			this->info=_info;
			this->prev=nullptr;
			this->next=nullptr;
		}	
};

class DoubleLinkedList{
	private:
		Node* head, *tail;
	public:
		DoubleLinkedList(){
			head=tail=nullptr;		
		}
		
		bool isEmpty(){
			return head==nullptr;
		} 
		
		void addFirst(int x){
			Node* newNode=new Node(x);
			if (isEmpty()){
				head=tail=newNode;
			} else {
				newNode->next=head;
				head->prev=newNode;
				head=newNode;
			}
		}
		
		void addLast(int x){
			Node* newNode=new Node(x);
			if (isEmpty()){
				head=tail=newNode;
			} else {
				newNode->prev=tail;
				tail->next=newNode;
				tail=newNode;
			}
		}
		
		int countNodes(){
			int count=0;
			Node* cur=head;
			while (cur!=nullptr){
				count++;
				cur=cur->next;
			}
			return count;
		}
		
		void addAtPos(int x, int pos){
			int n=countNodes();
			if (pos<0 || pos>n){
				cout<<pos<<" is out of range"<<endl;
				return;
			}
			if (pos==0){
				addFirst(x); return;
			}
			if (pos==n){
				addLast(x); return;
			}
			int i=0;
			Node* cur=head;
			while(i<pos){		//Move i and cur to pos postion.
				i++;
				cur=cur->next;
			}
			Node* newNode=new Node(x);
			newNode->next=cur;
			newNode->prev=cur->prev;
			cur->prev->next=newNode;
			cur->prev=newNode;
		}
		
		void removeFirst(){
			if (isEmpty()) return;
			if (head->next==nullptr){
				head=tail=nullptr;	
				return;
			}
			head->next->prev=nullptr;
			head=head->next;
		}
		
		void removeLast(){
			if (isEmpty()) return;
			if (head->next==nullptr){
				head=tail=nullptr;	
				return;
			}	
			tail->prev->next=nullptr;
			tail=tail->prev;		
		}
		
		void removeAtPos(int pos){
			int n=countNodes();
			if (pos<0 || pos>=n) {
				cout<<pos<<" is out of range."<<endl; return;
			}
			if (pos==0){
				removeFirst(); return;
			}
			if (pos==n-1){
				removeLast(); return;
			}
			int i=0;
			Node* cur=head;
			while (i<pos){		//Move i and cur to pos
				i++; cur=cur->next;
			}
			cur->prev->next=cur->next;
			cur->next->prev=cur->prev;
		}
		
		//Bubble sort
		void sortAsc(){
			Node* cur=head;
			while (cur->next!=nullptr){
				Node* q=cur->next;
				while (q!=nullptr){
					if (cur->info>q->info){		//Switch Asc to Desc by changing > to <
						int t = cur->info; cur->info=q->info; q->info=t;
					}
					q=q->next;
				}
				cur=cur->next;	
			}
		}
		
		void sortDesc(){
			Node* cur=head;
			while (cur->next!=nullptr){
				Node* q=cur->next;
				while (q!=nullptr){
					if (cur->info<q->info){		//Switch Asc to Desc by changing > to <
						int t = cur->info; cur->info=q->info; q->info=t;	//swap
					}
					q=q->next;
				}
				cur=cur->next;	
			}			
		}
		
		void editValueAtPos(int x, int pos){
			
		}
		
		void display(){
			Node* cur=head;
			while (cur!=nullptr){
				cout<<cur->info<<" ";
				cur=cur->next;
			}
		}
};

int main(){
	DoubleLinkedList myList;
	myList.addFirst(6);
	myList.addFirst(8);
	myList.addFirst(1);
	myList.addFirst(9);
	myList.addFirst(4);
	myList.display();
	cout<<endl;
	myList.addLast(5);
	myList.addLast(7);
	myList.addLast(3);
	myList.display(); 
	cout<<"\nNumber of nodes: "<< myList.countNodes()<<endl;
//	cout<<"Add at pos"<<endl;
//	int x, pos; 
//	cout<<"Input x = "; cin>>x;
//	cout<<"Input position to add: "; cin>>pos;
//	myList.addAtPos(x, pos);
//	myList.display();
//	myList.removeFirst();
//	myList.removeLast();
//	myList.display();
//	cout<<"Remove at pos"<<endl;
//	int pos; 
//	cout<<"Input position to remove: "; cin>>pos;
//	myList.removeAtPos(pos);	
//	myList.display();
	cout<<"Sort list Asc"<<endl;
	myList.sortAsc();
	myList.display();	
	return 0;
}
