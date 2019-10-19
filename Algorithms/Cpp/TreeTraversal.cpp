#include <iostream> 
#include <queue> 
using namespace std; 

struct Node 
{ 
	int data; 
	struct Node* left, *right; 
	Node(int data) 
	{ 
		this->data = data; 
		left = right = NULL; 
	} 
}; 

void printPostorder(struct Node* node) 
{ 
	if (node == NULL) 
		return; 
    
	printPostorder(node->left); 
	printPostorder(node->right); 
	cout << node->data << " "; 
} 

void printInorder(struct Node* node) 
{ 
	if (node == NULL) 
		return; 

	printInorder(node->left); 
	cout << node->data << " "; 
	printInorder(node->right); 
} 

void printPreorder(struct Node* node) 
{ 
	if (node == NULL) 
		return; 

	cout << node->data << " "; 
	printPreorder(node->left); 
	printPreorder(node->right); 
} 

void printLevelOrder(Node *root) 
{ 
	if (root == NULL) return; 
	queue<Node *> q; 
	q.push(root); 

	while (q.empty() == false) 
	{ 
		Node *node = q.front(); 
		cout << node->data << " "; 
		q.pop(); 

		if (node->left != NULL) 
			q.push(node->left); 

		if (node->right != NULL) 
			q.push(node->right); 
	} 
} 
int main() 
{ 
	struct Node *root = new Node(6); 
	root->left			 = new Node(8); 
	root->right		 = new Node(7); 
	root->left->left	 = new Node(3); 
	root->left->right = new Node(9); 

	cout << "\nPreorder traversal of binary tree is \n"; 
	printPreorder(root); 

	cout << "\nInorder traversal of binary tree is \n"; 
	printInorder(root); 

	cout << "\nPostorder traversal of binary tree is \n"; 
	printPostorder(root); 

	cout << "Level Order traversal of binary tree is \n"; 
	printLevelOrder(root); 
	return 0; 
} 
