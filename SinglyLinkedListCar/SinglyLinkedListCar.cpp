#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Car {
	public:
		string id;
		string name;
		int color;
		double price;
		Car() {};
		Car(string _id, string _name, int _color, double _price) {
			this->id=_id;
			this->name=_name;
			this->color=_color;
			this->price=_price;
		}
		void CarInfo() {
			cout<<left<< setw(5)<< id
			    <<left<< setw(20)<<name
			    <<left<< setw(5)<<color
			    <<right<<setw(10)<<setprecision(2) << fixed<< price<<endl;
		}
};

class Node {
	public:
		Car* info;
		Node* next;
		Node(Car* x) {
			info=x;
			next=nullptr;
		}
};

class SinglyLinkedListCar {
	public:
		Node *head, *tail;

		SinglyLinkedListCar() {
			head=tail=nullptr;
		}

		bool isEmpty() {
			return head==nullptr;
		}

		void addFirst(Car* x) {
			Node* newNode = new Node(x);
			if (x->color!=4 && x->price >= 30000) {
				if (isEmpty()) {
					head=tail=newNode;
				} else {
					newNode->next=head;
					head=newNode;
				}
			}
		}

		void addLast(Car* x) {

		}

		void sortCarListByPriceDesc() {
			Node* cur=head;
			while (cur->next != nullptr){
				Node* q=cur->next;
				while (q !=nullptr){
					if (cur->info->price < q->info->price){
						Car* t = cur->info; cur->info=q->info; q->info=t;
					}
					q=q->next;
				}
				cur=cur->next;
			}
		}

		void searchCarByID(string _id){
			
		}
		
		void searchCarByName(string _nameKeyword){
			
		}

		void getTheMostExpensiveCar(){
			
		}	
		
		void getTheCheapestcar(){
			
		}	
		
		void removeCarById(string _id){
			
		}
		
		void updateCarInfo(string id){
			
		}
		
		void displayList() {
			Node* cur=head;
			cout<<left<< setw(5)<< "ID"
			    <<left<< setw(20)<<"Name"
			    <<left<< setw(5)<<"Color"
			    <<right<<setw(10)<<"Price"<<endl;
			while (cur!=nullptr) {
				cur->info->CarInfo();
				cur=cur->next;
			}
		}

		~SinglyLinkedListCar() {
			Node* cur=head;
			while (cur!=nullptr) {
				Node* nextNode=cur->next;
				delete(cur->info);
				delete(cur);
				cur=nextNode;
			}
		}
};
void menu() ;
int main() {
	SinglyLinkedListCar myList;
	myList.addFirst(new Car("A1", "BMW", 3, 120000));
	myList.addFirst(new Car("A2", "Mazda CX9", 6, 85000.5));
	myList.addFirst(new Car("A3", "May bach", 7, 620000.8));
	myList.addFirst(new Car("A4", "Chevolet spark", 5, 12000.5));
	myList.addFirst(new Car("A5", "Phantom ghost", 4, 520000.5));
//	myList.displayList();
	int sel=0, _color;
	string _id, _name;
	double _price;
	do {
		menu();
		cin>>sel;
		getchar();		//Clear buffer
		switch (sel) {
			case 1:		
				cout<<"Input car ID: "; getline(cin,_id); 
				cout<<"Input car name: "; getline(cin,_name);
				cout<<"Input car color: "; cin>>_color;
				cout<<"Input car price: "; cin>>_price;
//				Car xx = new Car(_id, _name, _color, _price);
				myList.addFirst(new Car(_id, _name, _color, _price));	
//				myList.addFirst(&xx);	
				myList.displayList();		
				break;
			case 2:
				myList.displayList();
				break;
			case 3:
				myList.displayList();
				break;
			case 4:
				myList.sortCarListByPriceDesc();
				myList.displayList();
				break;
			case 0:
				exit(0);
				break;
			default:
				cout<<"Invalid selection"<<endl;
				break;
		}
	}while (sel!=0);

	return 0;
}
void menu() {
	cout<<"\n1. Add first a new car." <<endl;
	cout<<"2. Add last a new car." <<endl;
	cout<<"3. Display car list." <<endl;
	cout<<"4. Sort by price descending order." <<endl;
	cout<<"0. Quit." <<endl;
	cout<<"What is your selection: ";
}