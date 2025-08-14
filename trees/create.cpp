#include <bits/stdc++.h> 
using namespace std;

struct Node{
    int val;
    Node *left, *right;

    Node(int key){
        val = key;
        left = nullptr;
        right = nullptr;
    }
};

int main(){
    Node * firstnode = new Node(1);
    // method 1
    Node * secondnode = new Node(2);
    firstnode -> left = secondnode;

    // method 2
    firstnode ->right = new Node(3);

    Node* thirdNode = new Node(4);
    Node* fourthNode = new Node(5);

    secondnode -> left = thirdNode;
    secondnode -> right = fourthNode;
}