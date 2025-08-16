// recursion and range checking
#include <iostream>
#include <climits>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// utility function to check BST
bool BST(Node* root, long long minVal, long long maxVal) {
    if(root == NULL) return true;

    if(root -> data <= minVal || root-> data >= maxVal)  return false;

    return BST(root -> left, minVal, root->data) &&
        BST(root->right, root-> data, maxVal);
}

bool isBst(Node* root){
    return BST(root, LLONG_MIN, LLONG_MAX);
}

int main(){
    Node* root = new Node(10);
    root -> left = new Node(5);
     root->right = new Node(20);
    root->left->left = new Node(2);
    root->left->right = new Node(8);

    if (isBST(root))
        cout << "The tree is a BST" << endl;
    else
        cout << "The tree is NOT a BST" << endl;

    return 0;
}

// ⚡ Alternate method: Do an inorder traversal of the tree. If the sequence is strictly increasing, the tree is a BST.