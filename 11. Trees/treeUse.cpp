#include <iostream>
#include <queue>
#include <stack>
#include <climits> 
#include "treeClass.h"
using namespace std;

/************************************************************
 
    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;
    
        TreeNode(T data) {
            this->data = data;
        }
    
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/
TreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	queue<TreeNode<int>*> pendingNodes;
	
	pendingNodes.push(root);
	while (pendingNodes.size() != 0) {
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter num of children of " << front->data << endl;
		int numChild;
		cin >> numChild;
		for (int i = 0; i < numChild; i++) {
			int childData;
			cout << "Enter " << i << "th child of " << front->data << endl;
			cin >> childData;
			TreeNode<int>* child = new TreeNode<int>(childData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}

TreeNode<int>* takeInput() {
	int rootData;
	cout << "Enter data" << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	
	int n;
	cout << "Enter num of children of " << rootData << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		TreeNode<int>* child = takeInput();
		root->children.push_back(child);
	}
	return root;
}

void printTree(TreeNode<int>* root) {
	if (root == NULL) {
		return;
	}

	cout << root->data << ":";
	for (int i = 0; i < root->children.size(); i++) {
		cout << root->children[i]->data << ",";
	}
	cout << endl;
	for (int i = 0; i < root->children.size() ; i++) {
		printTree(root->children[i]);
	}
}

void printAtLevelK(TreeNode<int>* root, int k) {
	if (root == NULL) {
		return;
	}

	if (k == 0) {
		cout << root->data << endl;
		return;
	}

	for (int i = 0; i < root->children.size(); i++) {
		printAtLevelK(root->children[i], k - 1);
	}
}

int numNodes(TreeNode<int>* root) {
	if (root == NULL) {
		return 0;
	}
	int ans = 1;
	for (int i = 0; i < root->children.size(); i++) {
		ans += numNodes(root->children[i]);
	}
	return ans;
}

void preorder(TreeNode<int>* root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << " ";
	for (int i = 0; i < root->children.size(); i++) {
		preorder(root->children[i]);
	}
}

void deleteTree(TreeNode<int>* root) {
	for (int i = 0; i < root->children.size(); i++) {
		deleteTree(root->children[i]);
	}
	delete root;
}



bool isPresent(TreeNode<int>* root, int x);
TreeNode<int>* maxChildSum(TreeNode<int>* root);
TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int n);



// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0

int main() {
	TreeNode<int>* root = takeInputLevelWise();
    printTree(root);
	// TreeNode<int>* res = maxChildSum(root);
}












// Given a generic tree and an integer x, check if x is present in the
// given tree or not. Return true if x is present, return false otherwise.
bool isPresent(TreeNode<int>* root, int x) {
    if(root->data == x)
        return true;
    for(int i = 0; i<root->children.size(); i++) {
        bool ans = isPresent(root->children[i], x);
        if(ans == true)
            return ans;
        }
    return false;
}

//****************************************************************************

// Given a generic tree, find and return the node for which sum of 
// its data and data of all its child nodes is maximum. In the sum, 
// data of the node and data of its immediate child nodes has to be taken.
TreeNode<int>* maxChildSum(TreeNode<int>* root) {
    stack<TreeNode<int>*> s;
    queue<TreeNode<int>*> q;
    q.push(root);
    int large = 0;

    while(!q.empty()) {
        int maxSum = q.front()->data;
        for(int i = 0; i < root->children.size(); i++) {
            q.push(root->children[i]);
            maxSum += root->children[i]->data;
        }
        if(maxSum > large) {
            s.push(q.front());
            large = maxSum;
        }
        q.pop();
        root = q.front();
    }
    return s.top();
}

//****************************************************************************

// Given a generic tree and an integer n. Find and return the node with next 
// larger element in the tree i.e. find a node with value just greater than n.
// Note: Return NULL if no node is present with the value greater than n.

TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int n) {
    if(root == NULL)
        return root;
    TreeNode<int>* nextLarger = NULL;
    if(root->data > n) {
        nextLarger = root;
    }
    for(int i = 0; i < root->children.size(); i++) {
        TreeNode<int>* temp = getNextLargerElement(root->children[i], n);
        if(nextLarger == NULL || nextLarger->data > temp->data) {
            nextLarger = temp;
        }
    }
    return nextLarger;
}




























