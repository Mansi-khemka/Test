#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(int d){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = d;
	n->left = n->right = NULL;
	return n;
} 

void smallSumTree(struct Node* root, int * sum){
	if(root==NULL) return;
	
	smallSumTree(root->left, sum);
	*sum = *sum + root->data;
	root->data = *sum;
	smallSumTree(root->right, sum);
	
}

void printTree(struct Node* root){
	if(root!=NULL){
		printTree(root->left);
		cout<<root->data<<" ";
		printTree(root->right);
	}
}

int main()
{
    /* Create following BST
            9
            / \
        6     15 */
    Node* root = newNode(9);
    root->left = newNode(6);
    root->right = newNode(15);
 
    printf(" Original BST\n");
    printTree(root);
 
    int sum = 0;
    smallSumTree(root, &sum);
 
    printf("\n BST To Binary Tree\n");
    printTree(root);
 
    return 0;
}
