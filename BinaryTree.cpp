#include<iostream>;
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* GetNewNode(int data) {
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode;
	newNode->right = NULL;
	return newNode;
}

Node* Insert(Node* root, int data) {
	if (root == NULL) {
		root = GetNewNode(data);
		return root;
	}
	else if (data <= root->data) {
		root->left = Insert(root->left, data);
	}
	else {
		root->right = Insert(root->right, data);
	}
	return root;
}

bool Search(Node* root, int data) {
	if (root == NULL) return false;
	else if (root->data == data) return true;
	else if (data <= root->data) return Search(root->left, data);
	else return Search(root->right, data);
}

int main() {
	Node* root = NULL;

	Insert(root, 164);
	Insert(root, 64);
	Insert(root, 16);
	Insert(root, 15664);
	Insert(root, 134);

	int number;
	cout << "Enter Number\n";
	cin >> number;

	bool result = Search(root, number);
	if (result == true) {
		cout << "Found\n";
	}
	else {
		cout << "Not Found\n";
	}
}

