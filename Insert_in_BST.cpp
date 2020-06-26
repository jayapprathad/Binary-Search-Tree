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
void preorder(node *);
void inorder(node *);
void postorder(node *);

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
	printf("\nPreOrder Traversal: ");
	preorder(root);
	printf("\nInOrder Traversal: ");
	inorder(root);
	printf("\nPostOrder Traversal: ");
	postorder(root);
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

void preorder(node *root)  // Function to display the tree in preorder traversal
{
	if(root != NULL)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(node *root)  // Function to display the tree in inorder traversal
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

void postorder(node *root)  // Function to display the tree in postorder traversal
{
	if(root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}
