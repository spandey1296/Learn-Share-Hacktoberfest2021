#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node Node;

Node* createNode()
{
    Node* new_node;
    new_node = (Node *)malloc(sizeof(Node));
    printf("Enter the data of new node : ");
    scanf("%d",&new_node->data);
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
void addNode(Node* root, Node* new_node)
{
    if(root!=NULL)
    {
        if(new_node->data < root->data)
        {
            if(root->left==NULL)
            {
                root->left = new_node;
            }
            addNode(root->left,new_node);
        }
        else if(new_node->data > root->data)
        {
            if(root->right==NULL)
            {
                root->right = new_node;
            }
            addNode(root->right,new_node);
        }
    }
}
Node* findMin(Node* root) // Finding Minimum Value in the Right Sub Tree
{
    while(root->left!=NULL)
    {
        root = root->left;
    }
    return root;
}
Node* deleteValue(Node* root,int deleteNode)
{
    Node* temp = root;
    if(temp==NULL) return temp;

    else if(deleteNode < temp->data)
    {
        temp->left = deleteValue(temp->left,deleteNode);
    }
    else if(deleteNode > temp->data)
    {
        temp->right = deleteValue(temp->right,deleteNode);
    }
    else // root->data == deleteNode
    {
        // Case 1 -> No Child
        if(temp->left==NULL && temp->right==NULL)
        {
            free(temp);
            temp = NULL;
            return root;
        }
        // Case 2 -> One Child
        else if(temp->left==NULL)
        {
            Node *var = temp;
            root = root->right;
            free(var);
            return root;
        }
        else if(temp->right==NULL)
        {
            Node *var = temp;
            root = root->left;
            free(var);
            return root;
        }
        // Case 3 -> Two Child
        else
        {
            Node *var;
            var = findMin(temp->right);
            temp->data = var->data;
            temp->right = deleteValue(temp->right,var->data);
            return root;
        }
    }
}
int max(int a,int b)
{
    return (a>b?a:b);
}
int depthOfTree(Node* root)
{
    if(root==NULL) return 0;

    int leftDepth = depthOfTree(root->left);
    int rightDepth = depthOfTree(root->right);

    /*
    if(leftDepth > rightDepth)
    {
        return leftDepth + 1;
    }
    else
    {
        return rightDepth + 1;
    }
    */
    return max(leftDepth,rightDepth) + 1;
}
void findNode(Node* root,int find)
{
    if(root==NULL) return;

    if(root->data==find)
    {
        printf("%d is present in the Tree\n",find);
    }
    else
    {
        if(root->data > find)
        {
            findNode(root->left,find);
        }
        else if(root->data < find)
        {
            findNode(root->right,find);
        }
        else if(root->data==find)
        {
            printf("%d is present in the Tree\n",find);
        }
        else
        {
            printf("%d is not present in the Tree\n",find);
        }
    }
}
int leafNodes(Node* root)
{
    int ans;
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL)
    {
        return 1;
    }
    else
    {
        int leftLeaves = leafNodes(root->left);
        int rightLeaves = leafNodes(root->right);
        ans = ans + leftLeaves + rightLeaves;
    }
    return ans;
}
void inOrderTraversal(Node* root)
{
    //printf("In Order Traversal :\n");
    if(root!=NULL)
    {
        inOrderTraversal(root->left);
        printf("%d\n",root->data);
        inOrderTraversal(root->right);
    }
    /*printf("\n");
    In Order Traversal :
    In Order Traversal :
    In Order Traversal :
    30 In Order Traversal :
    In Order Traversal :
    40 In Order Traversal :
    50 In Order Traversal :
    In Order Traversal :
    70 In Order Traversal :
    */
}
void preOrderTraversal(Node* root)
{
    if(root!=NULL)
    {
        printf("%d\n",root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}
void postOrderTraversal(Node* root)
{
    if(root!=NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d\n",root->data);
    }
}

int main()
{
    int tillTrue = 1, choice;
    int value;
    int find;
    int deleteNode;
    int ans;
    Node *root,*new_node;
    root = createNode();
    while(tillTrue)
    {
        printf("...............\n");
        printf("1. Add a node to the Tree\n");
        printf("2. Delete a node from the Tree\n");
        printf("3. Depth of the Tree\n");
        printf("4. Find a node(if present) in the Tree\n");
        printf("5. Count total leaf nodes of the Tree\n");
        printf("6. In Order Traversal of the Tree\n");
        printf("7. Pre Order Traversal of the Tree\n");
        printf("8. Post Order Traversal of the Tree\n");
        printf("9. Exit\n");
        printf("...............\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                new_node = createNode();
                addNode(root,new_node);
                break;
            case 2:
                printf("Enter the value of node to delete from the Tree : ");
                scanf("%d",&deleteNode);
                deleteValue(root,deleteNode);
                break;
            case 3:
                printf("Maximum depth of the Tree is %d\n",depthOfTree(root));
                break;
            case 4:
                printf("Enter the node which you want to find in the Tree : ");
                scanf("%d",&find);
                findNode(root,find);
                break;
            case 5:
                ans = leafNodes(root);
                printf("Total leaf nodes of the Tree are %d\n",ans);
                break;
            case 6:
                inOrderTraversal(root);
                break;
            case 7:
                preOrderTraversal(root);
                break;
            case 8:
                postOrderTraversal(root);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid Operation\n");
        }
    }
    return 0;
}
