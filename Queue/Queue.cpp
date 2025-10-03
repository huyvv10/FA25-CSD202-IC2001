#include <iostream>
using namespace std;
class Node{
	public:
		int info;
		Node* next;
		Node(int value){
			this->info=value;
			this->next=nullptr;
		}
};
class Queue{
	private:
		Node *head, *tail;
	public:
		Queue(){
			this->head=nullptr;
			this->tail=nullptr;
		}
		
		bool isEmtpy(){
			return this->head==nullptr;
		}
		
		void enqueue(int x){
			Node* newNode= new Node(x);
			if (isEmtpy())
				head=tail=newNode;
			else{
				tail->next=newNode;
				tail=newNode;
			}	
		}
		
		int dequeue(){
			if (isEmtpy()){
				cout<<"Queue is empty."<<endl;
				return -999;
			}	
			int x = this->head->info;
			if (this->head->next==nullptr)
				head=tail=nullptr;
			else
				head=head->next;
			return x;	
		}
		
		int first(){
			if (isEmtpy()){
				cout<<"Queue is empty."<<endl;
				return -999;
			}
			return this->head->info;
		} 
		
		int sizeQ(){
			int count=0;
			Node* cur=this->head;
			while (cur!=nullptr){
				count++;
				cur=cur->next;
			}
			return count;
		}
};

int main(){
	Queue myQ;
	myQ.enqueue(5);
	myQ.enqueue(9);
	myQ.enqueue(7);
	myQ.enqueue(6);
	myQ.enqueue(8);
	cout<<"The first element of queue: "<< myQ.first()<<endl;
	cout<<"Dequeue: "<< myQ.dequeue()<<endl;
	cout<<"The first element of queue: "<< myQ.first()<<endl;
	cout<<"Size of queue: "<< myQ.sizeQ()<<endl;
	return 0;
}
