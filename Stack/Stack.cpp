#include <iostream>
using namespace std;
class Node {
	public:
		int info;
		Node* next;
		Node(int data) {
			this->info=data;
			this->next=nullptr;
		}
};

class Stack {
	private:
		Node *head, *tail;
	public:
		Stack() {
			this->head=this->tail=nullptr;
		}

		bool isEmpty() {
			return this->head==nullptr;
		}

		//Add an element into stack
		void push(int x) {
			Node* newNode = new Node(x);
			if (isEmpty())
				this->head=this->tail=newNode;
			else {
				newNode->next=this->head;
				this->head=newNode;
			}
		}

		//Get an element at top of stack then remove it.
		//GetValueAtFirst + RemoveFirst
		int pop() {
			if (isEmpty()) {
				cout<<"Stack is empty."<<endl;
				return -999;
			}
			int x = this->head->info;
			if (head->next==nullptr)	//Check wherether stack has only a node
				head=tail=nullptr;
			else
				head=head->next;		//Stack has more than a node
			return x;
		}

		//Get an element at top of stack without remove it.
		int top() {
			if (isEmpty()) {
				cout<<"Stack is empty."<<endl;
				return -999;
			}
			return this->head->info;
		}

		//Count number of elements within stack.
//		size()
};
void Dec2Bin(int n){
	Stack st;
	while (n!=0){
		int b=n%2;
		st.push(b);
		n=n/2;
	}
	string rs="";
	while (!st.isEmpty())
		cout<<st.pop();
}

void reverseString(const string& str){
	Stack myS;
	for (char c:str)
		myS.push(c);
	string rs="";
	while (!myS.isEmpty()){
		rs += myS.pop();
	}
	cout<<rs<<endl;
}

int main() {
	Stack myS;
	myS.push(5);
	myS.push(9);
	myS.push(3);
	myS.push(6);
	myS.push(8);
	cout<<"Top value: "<<myS.top()<<endl;	
	cout<<"Pop value: "<<myS.pop()<<endl;	
	cout<<"Top value: "<<myS.top()<<endl;
	int n;
	cout<<"Input n: "; cin>>n;
	Dec2Bin(n)	;
	cout<<endl;
	getchar();
	cout<<"Input a string to reverse: ";
	string str;
	getline(cin, str);
	reverseString(str);
	
	return 0;
}
