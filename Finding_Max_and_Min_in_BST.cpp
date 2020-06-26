#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
	int data;
	struct tree *right, *left;
}node;

// Functions used in the program

node* insert(node*, int);  
node* allocate_node(int);
int maximum(node*);
int minimum(node*);

int main()
{
	node *root = NULL;
	int num,val,i;
	printf("Enter number of values: ");  // Number of values to be stored
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
	    printf("Enter value to be inserted: ");
	    scanf("%d",&val);
	    root = insert(root,val);  // Inserting into BST
	}
	printf("Maximum Value = %d\n",maximum(root));
	printf("Minimum Value = %d\n",minimum(root));
	return 0;
} 

node* insert(node* root, int val) // Function to insert a value into the tree
{
	if(root == NULL) // Inserting in the correct position
        return allocate_node(val);
    else if(root->data > val)  // Going through Left side of the tree
        root->left = insert(root->left, val);
    else if(root->data < val)  // Going through right side of the tree
        root->right = insert(root->right, val);
    else  
        printf("\nRepeated Value");
}

node* allocate_node(int val)  // Function to allocate a new node with the respective data
{
	node *temp;
	temp = (node *)malloc(sizeof(node));
	temp->data = val;
	temp->right = temp->left = NULL;
	return temp;
}
int maximum(node *root)  // Finding Maximum value of the tree
{
	while(root->right != NULL)
	    root = root->right;
    return root->data;
}

int minimum(node *root)  // Finding Minimum value of the tree
{
	while(root->left != NULL)
	    root = root->left;
    return root->data;
}
