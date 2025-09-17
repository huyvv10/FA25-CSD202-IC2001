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
			int size=countNodes();
			if (pos<0 || pos>=size) {
				cout<<"Invalid position.\n"; return;
			}
			if (pos==0) {
				editNodeAtFirst(x); return;	
			}
			if (pos==size-1){
				editNodeAtLast(x); return;
			}
			Node* cur=head->next;
			int i=1;
			while (cur->next !=nullptr){
				if (i==pos){
					cur->info=x; return;
				}
				i+=1;
				cur=cur->next;
			}
		}
		//Sort the list in ascending order
		//Bubble sort
		void sortListAsc(){
			if (isEmpty()) return;
			Node* cur=head;
			while (cur->next != nullptr){
				Node* q = cur->next;
				while (q != nullptr){
					if (cur->info > q->info){	//Edit > < to change Asc/Desc
						int t = cur->info; cur->info= q->info; q->info=t;
					}
					q=q->next;
				}
				cur=cur->next;
			}
		}
		//Sort the list in descending order
		//Bubble sort
		void sortListDesc(){
			if (isEmpty()) return;
			Node* cur=head;
			while (cur->next != nullptr){
				Node* q = cur->next;
				while (q != nullptr){
					if (cur->info < q->info){	//Edit > < to change Asc/Desc
						int t = cur->info; cur->info= q->info; q->info=t;
					}
					q=q->next;
				}
				cur=cur->next;
			}			
		}	
		
		int getMax(){
			int max=head->info;
			Node* cur=head;
			while (cur != nullptr){
				if (cur->info > max) max = cur->info;
				cur=cur->next;
			}
			return max;
		}
			
		int getMin(){
			int min=head->info;
			Node* cur=head;
			while (cur != nullptr){
				if (cur->info < min) min = cur->info;
				cur=cur->next;
			}
			return min;
		}	
		
		int getFirstPosOfNode(int x){
			int pos=-1, i=0;
			Node* cur=head;
			while (cur != nullptr){
				if (cur->info == x){
					pos=i; break;
				}
				i+=1;
				cur=cur->next;
			}
			return pos;
		}
		//Return the postion k-th of x. Return -1 in case find not found.
		int getPosTheKOfNode(int x, int k){
			int pos=-1, i=0, count=0;
			Node* cur=head;
			while(cur!=nullptr){
				if (cur->info==x){
					count++;
					if (count==k){
						pos=i; break;
					}
				}
				i++;
				cur=cur->next;
			}
			return pos;
		}		
		//Sort from pos1 to pos2 in the list 
		void sortAsc(int pos1, int pos2){			
			int i=0, j=0;
			if (isEmpty()) return;
			if (pos1>pos2){int t=pos1; pos1=pos2;pos2=t;}
			Node* cur=head;
			while (cur!=nullptr && i!=pos1){
				cur=cur->next;
				i++;
			}
			while (cur->next != nullptr && i!=pos2-1){
				Node* q = cur->next;
				j=i+1;
				while (q != nullptr && j!=pos2){
					if (cur->info > q->info){	//Edit > < to change Asc/Desc
						int t = cur->info; cur->info= q->info; q->info=t;
					}
					q=q->next; j++;
				}
				cur=cur->next; i++;
			}			
		}
		
		int getValuePrev(int pos){
			return 0;
		}
		int getValueAfter(int pos){
			return 0;
		}	
		
		void editNodePrev(int x, int pos){
			
		}	
		void editNodeAfter(int x, int pos){
			
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
	myList.addFirst(15);
	myList.display();
	
	myList.addLast(11);	
	myList.addLast(6);	
	myList.addLast(2);	
	myList.addLast(15);	
	myList.addLast(5);	
	myList.addLast(15);	
	myList.addLast(8);	
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
//	cout<<"The value at first is: "<<myList.getValueAtFirst()	<<endl;
//	cout<<"\nGet value at pos:\n";
//	int pos;
//	cout<<"Input position to remove node: "; cin>>pos;	
//	int rs = myList.getValueAtPos(pos);
//	if (rs!=-999)
//		cout<<"Value at " <<pos<< " is: "<<rs<<endl;
//	else
//		cout<<pos<<" is out of range." <<endl;
//	cout<<"\nGet value at pos:\n";
//	int pos, x;
//	cout<<"Input value x = "; cin>>x;
//	cout<<"Input position to edit: pos = "; cin>>pos;	
//	myList.editNodeAtPos(x, pos);
//	myList.display();
//	cout<<"\nSorted list"<<endl;
//	myList.sortListAsc();
//	myList.sortListDesc();
//	myList.display();
//	cout<<"---Get max/min ---"<<endl;
//	cout<<"The max = "<<myList.getMax()
//		<<", min = "<<myList.getMin()<<endl;

//	cout<<"---Get the position first found x ---"<<endl;
//	int x;
//	cout<<"Input value to search: x = "; cin>>x;	
//	cout<<"The position first found "<< x
//		<<" is "<<myList.getFirstPosOfNode(x);
//	cout<<"---Get the position the-k of x ---"<<endl;		
//	int x,k;
//	cout<<"Input value to search: x = "; cin>>x;
//	cout<<"Input the-k: k = "; cin>>k;
//	int pos = myList.getPosTheKOfNode(x,k);
//	if (pos!=-1)
//		cout<<"The position "<<k<<"-th of "<<x<<" is: "<<pos <<endl;
//	else
//		cout<<"Find not found the-"<<k<<" of "<<x<<endl;
	int pos1=myList.getPosTheKOfNode(myList.getMin(),2);
	int pos2=myList.getPosTheKOfNode(myList.getMax(),3);
	myList.sortAsc(pos1,pos2);
	myList.display();
			
}
