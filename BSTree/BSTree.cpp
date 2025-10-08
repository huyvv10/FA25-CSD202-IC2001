#include <iostream>
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
		
		void breadthFirstTraversal(){
			
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
	myBST.addATreeNode(18);
	myBST.preOrderTraversal(myBST.getRoot());
	cout<<endl;
	myBST.inOrderTraversal(myBST.getRoot());
	cout<<endl;
	myBST.postOrderTraversal(myBST.getRoot());
	cout<<"\nNumber of nodes: "<<myBST.countNodes(myBST.getRoot())<<endl;
	return 0;
}
