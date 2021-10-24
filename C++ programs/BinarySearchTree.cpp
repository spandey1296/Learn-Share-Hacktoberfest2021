/*
Binary Search Tree Implementation-
1. Insert in BST(Recursive and Iterative)
2. Inorder, Preorder, Postorder Traversals
3. Delete a Node from BST
*/

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    Node(int d){
        key = d;
        left = right = NULL;
    }
};

//n = no. of nodes of BST, h = height of BST

//Recursive Insertion in Binary Search Tree
//TC=O(n), SC=O(h)
Node* insertRecursive(Node* root, int x){
    if(root == NULL){
        Node* newNode = new Node(x);
        return newNode;
    }
    else if(root->key < x){
        root->right = insertRecursive(root->right, x);
    }
    else if(root->key > x){
        root->left = insertRecursive(root->left, x);
    }
    return root;
}

//Iterative Insertion in Binary Search Tree
//TC=O(n), SC=O(1)
Node* insertIterative(Node* root, int x){
    Node* newNode = new Node(x);
    Node* parent = NULL;
    Node* curr = root;

    while(curr != NULL){
        parent = curr;
        if(curr->key < x)
            curr = curr->right;
        else if(curr->key > x)
            curr = curr->left;
        else    
            return root;
    }
    if(parent == NULL){
        return newNode;
    }
    if(parent->key > x)
        parent->left = newNode;
    else
        parent->right = newNode;
    return root;
}

//Inorder Traversal
//left root right
//TC=O(n), SC=O(h)
void inorder(Node* root){
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->key <<" ";
    inorder(root->right);
}

//Preorder Traversal
//root left right
//TC=O(n), SC=O(h)
void preorder(Node* root){
    if(root == NULL)
        return;
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

//Postorder Traversal
//left right root
//TC=O(n), SC=O(h)
void postorder(Node* root){
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->key <<" ";
}

//Deletion in Binary Search Tree
//TC=O(h), SC=O(h)
//Inorder successor is leftmost node of right subtree
Node* getInorderSuccessor(Node* curr){
    curr = curr->right;
    while(curr != NULL && curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}

Node* deleteNode(Node* root, int x){
    if(root == NULL)
        return root;
    if(root->key > x)
        root->left = deleteNode(root->left, x);
    else if(root->key < x)
        root->right = deleteNode(root->right, x);
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else{
            Node* succ = getInorderSuccessor(root);
            root->key = succ->key;
            root->right = deleteNode(root->right, succ->key);
        }
    }
    return root;
}


int main()
{
    Node* root = NULL;
    root = insertRecursive(root, 50);
    insertRecursive(root, 30);
    insertRecursive(root, 20);
    insertRecursive(root, 40);
    insertIterative(root, 70);
    insertIterative(root, 60);
    insertIterative(root, 80);

    cout << "Inorder Traversal is: ";
    inorder(root);
    cout <<"\n";

    cout << "Preorder Traversal is: ";
    preorder(root);
    cout << "\n";

    cout << "Postorder Traversal is: ";
    postorder(root);
    cout << "\n";

    cout << "Inorder Traversal of BST after deleting Node with key = 50 is: ";
    root = deleteNode(root, 50);
    inorder(root);

    return 0;

}

/*
Output:
Inorder Traversal is: 20 30 40 50 60 70 80
Preorder Traversal is: 50 30 20 40 70 60 80
Postorder Traversal is: 20 40 30 60 80 70 50
Inorder Traversal of BST after deleting Node with key = 20 is: 20 30 40 60 70 80
*/
