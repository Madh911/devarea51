#include <limits.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right;
}; 
// A utility function to create a new node
struct Node* newNode(int data)
{
    struct Node* node
        = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
// Returns maximum value in a given Binary Tree
int findMax(struct Node* root)
{
    // Base case
    int res,lres,rres;
    if (root == NULL)
	return INT_MIN;
    // Return maximum of 3 values:
    // 1) Root's data 2) Max in Left Subtree
    // 3) Max in right subtree
    res = root->data;
    lres = findMax(root->left);
    rres = findMax(root->right);
    if (lres > res)
	res = lres;
    if (rres > res)
	res = rres;
    return res;
}
// Returns minimum value in a given Binary Tree
int findMin(struct Node* root)
{
    // Base case
    int res,lres,rres;
    if (root == NULL)
      return INT_MAX;
    // Return minimum of 3 values:
    // 1) Root's data 2) Max in Left Subtree
    // 3) Max in right subtree
    res = root->data;
    lres = findMin(root->left);
    rres = findMin(root->right);
    if (lres < res)
      res = lres;
    if (rres < res)
      res = rres;
    return res;
}
 
// Driver code
int main(void)
{
    struct Node* NewRoot = NULL;
    struct Node* root = newNode(2);
    clrscr();
    root->left = newNode(77);
    root->right = newNode(25);
    root->left->right = newNode(66);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(11);
    root->right->right = newNode(99);
    root->right->right->left = newNode(4);
    // Function call
    printf("Maximum element is %d \n", findMax(root));
    printf("Manimum element is %d \n", findMin(root));
    getch();
    return 0;
}
