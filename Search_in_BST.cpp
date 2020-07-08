#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
	int data;
	struct tree *right, *left;
}node;

// Functions used in the program

node* insert(node *, int);  
node* allocate_node(int);
node* search(node* , int);

int main()
{
	node *root = NULL;
	int num,val,i;
	printf("Enter number of values: ");  // Number of values to be stored
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
	    printf("Enter value %d: ",i+1);
	    scanf("%d",&val);
	    root = insert(root,val);  // Inserting into BST
	}
	printf("\nEnter value to search: ");
	scanf("%d",&val);
	if(search(root,val) != NULL)
	    printf("Value found!");
	else
	    printf("Value not found!");
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
        printf("Repeated Value not taken!\n");  // To enter alternate value for the repeated value
    return root;
}

node* allocate_node(int val)  // Function to allocate a new node with the respective data
{
	node *temp;
	temp = (node *)malloc(sizeof(node));         
	temp->data = val;                                                              
	temp->right = temp->left = NULL;
	return temp;
}
node* search(node* root, int val)  // Searching whether the entered value is found or not
{
	if(root == NULL || root->data == val)  // NULL = value not found else value found
	    return root;
	else if(root->data > val)                              
	    return search(root->left , val);
	else
	    return search(root->right , val);
}
