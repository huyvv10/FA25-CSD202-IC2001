#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
	public:
		int info;
		TreeNode *left, *right;
		TreeNode(int value) {
			this->info=value;
			this->left=nullptr;
			this->right=nullptr;
		}
};

class Node{
	public:
		TreeNode* info;
		Node* next;
		Node(TreeNode* value){
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
		
		void enqueue(TreeNode* x){
			Node* newNode= new Node(x);
			if (isEmtpy())
				head=tail=newNode;
			else{
				tail->next=newNode;
				tail=newNode;
			}	
		}
		
		TreeNode* dequeue(){
			if (isEmtpy()){
				cout<<"Queue is empty."<<endl;
				return nullptr;
			}	
			TreeNode* x = this->head->info;
			if (this->head->next==nullptr)
				head=tail=nullptr;
			else
				head=head->next;
			return x;	
		}
};
class BSTree {
	private:
		TreeNode* root;
	public:
		BSTree() {
			root=nullptr;
		}

		TreeNode* getRoot() {
			return this->root;
		}

		bool isEmpty() {
			return this->root==nullptr;
		}

		void addATreeNode(int x) {
			TreeNode* newNode= new TreeNode(x);
			if (isEmpty()) {
				this->root=newNode;
				return;
			}
			TreeNode* p=this->root;
			while (p!=nullptr) {
				if (p->info==newNode->info) {
					cout<<x<<" already existed."<<endl;
					return;
				}
				if (newNode->info < p->info) {
					if (p->left==nullptr) {
						p->left=newNode;
						return;
					} else
						p=p->left;
				} else {
					if (p->right==nullptr) {
						p->right=newNode;
						return;
					} else
						p=p->right;
				}
			}
		}

		void visit(TreeNode* root) {
			if (root==nullptr) return;
			cout<<root->info<<" ";
		}

		//GLR
		void preOrderTraversal(TreeNode* root) {
			if (root==nullptr) return;
			visit(root);						//Visit root
			if (root->left!=nullptr)
				preOrderTraversal(root->left);	//Visit Left
			if (root->right!=nullptr)
				preOrderTraversal(root->right);	//Visit Right
		}

		//LGR
		void inOrderTraversal(TreeNode* root) {
			if (root==nullptr) return;
			if (root->left!=nullptr)
				inOrderTraversal(root->left);	//Visit Left
			visit(root);						//Visit root
			if (root->right!=nullptr)
				inOrderTraversal(root->right);	//Visit Right
		}

		//LRG
		void postOrderTraversal(TreeNode* root) {
			if (root==nullptr) return;
			if (root->left!=nullptr)
				postOrderTraversal(root->left);	//Visit Left
			if (root->right!=nullptr)
				postOrderTraversal(root->right);	//Visit Right
			visit(root);						//Visit root
		}
		
		//Using collection embeded queue of C++
		void breadthFirstTraversal(){
			if (this->root==nullptr)
				return;
			queue<TreeNode*> myQ;
			myQ.push(root);
			while (!myQ.empty()){
				TreeNode* p=myQ.front(); //Read data at the beginning of Queue
				myQ.pop();				//Remove data at the beginning of Queue
				visit(p);
				if (p->left!=nullptr)
					myQ.push(p->left);
				if (p->right!=nullptr)
					myQ.push(p->right);
			}				
		}
		
		//Using customize queue
		void breadthFirstTraversal2(){
			if (this->root==nullptr)
				return;
			Queue myQ;			
			TreeNode* p=this->root;
			myQ.enqueue(p);
			while (!myQ.isEmtpy()){
				TreeNode* p = myQ.dequeue();
				visit(p);
				if (p->left!=nullptr){
					myQ.enqueue(p->left);
				}					
				if (p->right!=nullptr){
					myQ.enqueue(p->right);
				}					
			}
		}
	
		int countNodes(TreeNode* root){
			if (root==nullptr) return 0;
			int count=0,l=0,r=0;
			if (root->left!=nullptr)
				l=countNodes(root->left);	//Visit Left
			count++;						//Visit root
			if (root->right!=nullptr)
				r=countNodes(root->right);	//Visit Right	
			return count+l+r;			
		}		
};

int main() {
	BSTree myBST;
	myBST.addATreeNode(9);
	myBST.addATreeNode(7);
	myBST.addATreeNode(15);
	myBST.addATreeNode(4);
	myBST.addATreeNode(13);
	myBST.addATreeNode(21);
	myBST.addATreeNode(12);
	myBST.addATreeNode(10);
	myBST.addATreeNode(14);
	myBST.addATreeNode(11);
	myBST.addATreeNode(2);
	myBST.addATreeNode(5);
	myBST.addATreeNode(3);
	myBST.addATreeNode(8);
	myBST.preOrderTraversal(myBST.getRoot());
	cout<<endl;
	myBST.inOrderTraversal(myBST.getRoot());
	cout<<endl;
	myBST.postOrderTraversal(myBST.getRoot());
	cout<<"\nNumber of nodes: "<<myBST.countNodes(myBST.getRoot())<<endl;
	cout<<"\nBFS"<<endl;
	myBST.breadthFirstTraversal();	
	cout<<endl;
	myBST.breadthFirstTraversal2();	
	return 0;
}
