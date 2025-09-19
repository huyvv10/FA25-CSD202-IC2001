#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Car{
	public:
		string id;
		string name;
		int color;
		double price;
		Car(){};
		Car(string _id, string _name, int _color, double _price){
			this->id=_id;
			this->name=_name;
			this->color=_color;
			this->price=_price;			
		}	
		void CarInfo(){
			cout<<left<< setw(5)<< id 
				<<left<< setw(25)<<name
				<<left<< setw(5)<<color
				<<right<<setw(10)<<price<<endl;
		}	
};

class Node{
	public:
		Car* info;
		Node* next;
		Node(Car* x){
			info=x;
			next=nullptr;
		}		
};

class SinglyLinkedListCar{
	public:
		Node *head, *tail;
		
		SinglyLinkedListCar(){
			head=tail=nullptr;
		}
		
		bool isEmpty(){
			return head==nullptr;
		}
		
		void addFirst(Car* x){
			Node* newNode = new Node(x);
			if (isEmpty()){
				head=tail=newNode;
			} else {
				newNode->next=head;
				head=newNode;
			}
		}
		
		void displayList(){
			Node* cur=head;
			cout<<left<< setw(5)<< "ID" 
				<<left<< setw(25)<<"Name"
				<<left<< setw(5)<<"Color"
				<<right<<setw(10)<<"Price"<<endl;
			while (cur!=nullptr){
				cur->info->CarInfo();
				cur=cur->next;
			}
		}
};

int main(){
	SinglyLinkedListCar myList;
	myList.addFirst(new Car("A1", "BMW", 3, 120000));
	myList.addFirst(new Car("A2", "Mazda CX9", 6, 85000.5));
	myList.addFirst(new Car("A3", "May bach", 7, 620000.8));
	myList.displayList();
	return 0;
}
