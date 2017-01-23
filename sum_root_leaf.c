/* Sum of root to leaf equal to input value 
For eg, input 19, the nodes from root 1,5,6,7 add upto 19
1
2 5
4 3 NL 6
NL NL 8 7 */
#include <stdio.h>

typedef struct node_ {
    int data;
    struct node_ *left, *right;
} node;

void preorder (node *root, int *sum, int value)
{
    if (!root)
        return;

    *sum += root->data;
    if ((!root->left && !root->right) && (*sum == value)) 
        printf("Found leaf %d \n", root->data);

    preorder(root->left, sum, value);
    preorder(root->right, sum, value);
  
    *sum -= root->data;
}

int main()
{
    int sum = 0;
    node n8 = {8, NULL, NULL}, n7 = {7, NULL, NULL}, n6 = {6, &n8, &n7}, n5 = {5, NULL, &n6};
    node n4 = {4, NULL, NULL}, n3 = {3, NULL, NULL}, n2 = {2, &n4, &n3}, n1 = {1, &n2, &n5};

    preorder(&n1, &sum, 19);
    return 0;
}        
