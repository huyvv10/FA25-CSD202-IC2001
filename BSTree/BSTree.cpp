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

class Node {
	public:
		TreeNode* info;
		Node* next;
		Node(TreeNode* value) {
			this->info=value;
			this->next=nullptr;
		}
};
class Queue {
	private:
		Node *head, *tail;
	public:
		Queue() {
			this->head=nullptr;
			this->tail=nullptr;
		}

		bool isEmtpy() {
			return this->head==nullptr;
		}

		void enqueue(TreeNode* x) {
			Node* newNode= new Node(x);
			if (isEmtpy())
				head=tail=newNode;
			else {
				tail->next=newNode;
				tail=newNode;
			}
		}

		TreeNode* dequeue() {
			if (isEmtpy()) {
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

		void setRoot(TreeNode* x) {
			this->root=x;
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
		void breadthFirstTraversal() {
			if (this->root==nullptr)
				return;
			queue<TreeNode*> myQ;
			myQ.push(root);
			while (!myQ.empty()) {
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
		void breadthFirstTraversal2() {
			if (this->root==nullptr)
				return;
			Queue myQ;
			TreeNode* p=this->root;
			myQ.enqueue(p);
			while (!myQ.isEmtpy()) {
				TreeNode* p = myQ.dequeue();
				visit(p);
				if (p->left!=nullptr) {
					myQ.enqueue(p->left);
				}
				if (p->right!=nullptr) {
					myQ.enqueue(p->right);
				}
			}
		}

		int countNodes(TreeNode* root) {
			if (root==nullptr) return 0;
			int count=0,l=0,r=0;
			if (root->left!=nullptr)
				l=countNodes(root->left);	//Visit Left
			count++;						//Visit root
			if (root->right!=nullptr)
				r=countNodes(root->right);	//Visit Right
			return count+l+r;
		}

		int countAllLeafNode(TreeNode* node) {
			if (node==nullptr) return 0;
			int count=0,l=0,r=0;
			if (node->left==nullptr && node->right==nullptr)
				count++;						//Visit root
			if (node->left!=nullptr)
				l=countAllLeafNode(node->left);	//Visit Left
			if (node->right!=nullptr)
				r=countAllLeafNode(node->right);	//Visit Right
			return count+l+r;
		}

		int countAllNodeHasOnlyALeftChild(TreeNode* node) {
			if (node==nullptr) return 0;
			int count=0,l=0,r=0;
			if (node->left!=nullptr && node->right==nullptr)
				count++;						//Visit root
			if (node->left!=nullptr)
				l=countAllNodeHasOnlyALeftChild(node->left);	//Visit Left
			if (node->right!=nullptr)
				r=countAllNodeHasOnlyALeftChild(node->right);	//Visit Right
			return count+l+r;
		}

		int countAllNodeHasOnlyARightChild(TreeNode* node) {
			if (node==nullptr) return 0;
			int count=0,l=0,r=0;
			if (node->left==nullptr && node->right!=nullptr)
				count++;						//Visit root
			if (node->left!=nullptr)
				l=countAllNodeHasOnlyARightChild(node->left);	//Visit Left
			if (node->right!=nullptr)
				r=countAllNodeHasOnlyARightChild(node->right);	//Visit Right
			return count+l+r;
		}


		//Find the maximum value Node of the left subtree
		TreeNode* findTheRightMostNode(TreeNode* x) {
			if (x==nullptr)
				return nullptr;
			TreeNode* p=x->left;
			while (p->right!=nullptr) {
				p=p->right;
			}
			return p;
		}

		//Copy the maximum value of the left subtree
		TreeNode* deleteByCopying(TreeNode* node, int x) {
			if (node==nullptr) return nullptr;
			if (x < node->info)
				node->left = deleteByCopying(node->left, x);
			else if (x > node->info)
				node->right = deleteByCopying(node->right, x);
			else {
				if (node->left ==nullptr)
					return node->right;
				if (node->right ==nullptr)
					return node->left;
				TreeNode* copyNode = findTheRightMostNode(node);
				node->info = copyNode->info;
				node->left = deleteByCopying(node->left, copyNode->info);
			}
			return node;
		}

		TreeNode* findTheLeftMostNode(TreeNode* x) {
			if (x==nullptr) return nullptr;
			TreeNode* p=x->right;
			while (p->left!=nullptr) {
				p=p->left;
			}
			return p;
		}
		//Copy the minimum value of the right subtree
		TreeNode* deleteByCopyingRight(TreeNode* node, int x) {
			if (node==nullptr) return nullptr;
			if (x < node->info)
				node->left = deleteByCopyingRight(node->left, x);
			else if (x > node->info)
				node->right = deleteByCopyingRight(node->right, x);
			else {
				if (node->left ==nullptr)
					return node->right;
				if (node->right ==nullptr)
					return node->left;
				TreeNode* copyNode = findTheLeftMostNode(node);
				node->info = copyNode->info;
				node->left = deleteByCopyingRight(node->left, copyNode->info);
			}
			return node;
		}

		TreeNode* deleteByMerging(TreeNode* node, int x) {
			if (node==nullptr) return nullptr;
			if (x < node->info)
				node->left = deleteByMerging(node->left, x);
			else if (x > node->info)
				node->right = deleteByMerging(node->right, x);
			else {
				if (node->left ==nullptr)
					return node->right;
				if (node->right ==nullptr)
					return node->left;
				TreeNode* mergeNode = findTheRightMostNode(node);
				mergeNode->right = node->right;
				return node->left;
			}
			return node;
		}

		//Delete all tree node that has only a left child
		TreeNode* deleteNodesHasOnlyLeftChild(TreeNode* root) {
			if (root==nullptr) return nullptr;
			if (root->left!=nullptr && root->right==nullptr)
				return root->left;
			if (root->left!=nullptr)
				root->left=deleteNodesHasOnlyLeftChild(root->left);	//Visit Left
			if (root->right!=nullptr)
				root->right=deleteNodesHasOnlyLeftChild(root->right);	//Visit LeftpreOrderTraversal(root->right);	//Visit Right
			return root;
		}

		//Delete all tree node that has only a right child
		TreeNode* deleteNodesHasOnlyRightChild(TreeNode* root) {
			if (root==nullptr) return nullptr;
			if (root->left==nullptr && root->right!=nullptr)
				return root->right;
			if (root->left!=nullptr)
				root->left=deleteNodesHasOnlyRightChild(root->left);	//Visit Left
			if (root->right!=nullptr)
				root->right=deleteNodesHasOnlyRightChild(root->right);	//Visit LeftpreOrderTraversal(root->right);	//Visit Right
			return root;
		}

		//Delete all tree node that is a leaf node - external node
		TreeNode* deleteAllLeafNodes(TreeNode* root) {
			if (root==nullptr) return nullptr;
			if (root->left==nullptr && root->right==nullptr)
				return nullptr;
			if (root->left!=nullptr)
				root->left=deleteAllLeafNodes(root->left);
			if (root->right!=nullptr)
				root->right=deleteAllLeafNodes(root->right);
			return root;
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
	cout<<"\nCount leaf node";
	cout<<myBST.countAllLeafNode(myBST.getRoot());
	cout<<"\nCount node only has left child";
	cout<<myBST.countAllNodeHasOnlyALeftChild(myBST.getRoot());
	cout<<"\nDelete node only has right child"<<endl;
	cout<<myBST.countAllNodeHasOnlyARightChild(myBST.getRoot());
	cout<<"\nDelete by Copying"<<endl;
	int x;
//	cout<<"\nInput x to delete: "; cin>>x;
//	myBST.setRoot(myBST.deleteByCopying(myBST.getRoot(), x));
	myBST.breadthFirstTraversal2();
//	cout<<"\nDelete by Merging"<<endl;
//	cout<<"\nInput x to delete: ";
//	cin>>x;
//	myBST.setRoot(myBST.deleteByMerging(myBST.getRoot(), x));
//	myBST.breadthFirstTraversal2();

//	cout<<"\nDelete by Copying right"<<endl;
//	cout<<"\nInput x to delete: ";
//	cin>>x;
//	myBST.setRoot(myBST.deleteByCopyingRight(myBST.getRoot(), x));
//	myBST.breadthFirstTraversal2();
//	cout<<"\nDelete all nodes has only a left child"<<endl;
//	myBST.setRoot(myBST.deleteNodesHasOnlyLeftChild(myBST.getRoot()));
//	myBST.breadthFirstTraversal2();
//	cout<<"\nDelete all nodes has only a right child"<<endl;
//	myBST.setRoot(myBST.deleteNodesHasOnlyRightChild(myBST.getRoot()));
//	myBST.breadthFirstTraversal2();
//	cout<<"\nDelete all leaf nodes"<<endl;
//	myBST.setRoot(myBST.deleteAllLeafNodes(myBST.getRoot()));
//	myBST.breadthFirstTraversal2();
	return 0;
}
