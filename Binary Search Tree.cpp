#include<iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};

node* getNewNode(int data)
{
    node* newNode = new node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

node* insert(node* root, int data)
{
    if(root == NULL)
    {
        root = getNewNode(data);
    }
    else if(data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

bool search(node* root, int data)
{
    if(root == NULL) return false;
    else if(root->data == data) return true;
    else if(data <= root->data) return search(root->left, data);
    else return search(root->right, data);
}

node* FindMin(node* root)
{
    node* currentNode = root;
    node* temp = currentNode;
    while(true)
    {
        if(currentNode == NULL){
            break;
        }

        else{
            temp = currentNode;
            currentNode = currentNode->left;
        }
    }

    return temp;

}

node* deleteNode(node* root, int data)
{
    if(root == NULL) return root;
    else if(data < root->data) root->left = deleteNode(root->left, data);
    else if(data > root->data) root->right = deleteNode(root->right, data);
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root =  NULL;
        }
        else if(root->left == NULL)
        {
            node* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL)
        {
            node* temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            node* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

void traverse(node* root)
{
    if(root == NULL) return;
    traverse(root->left);
    cout << root->data << endl;
    traverse(root->right);
}

int main (void)
{
    node* root = NULL;
    root = insert(root, 15);
    root = insert(root, 20);
    root = insert(root, 7);
    root = insert(root, 11);
    traverse(root);
    while(1)
    {
        int command, data;
        cin >> command >> data;
        if(command == 1) root = insert(root, data);
        else deleteNode(root, data);
        traverse(root);
    }
    return 0;
}
