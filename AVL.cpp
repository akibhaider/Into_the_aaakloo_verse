#include<bits/stdc++.h>

using namespace std;

typedef struct Node
{
    int data;
    int height;
    Node *left;
    Node *right;
    Node *parent;
}Node;

Node * root = NULL;

Node * create_Node(int data, Node * parent)
{
    Node * new_Node = new Node();
    new_Node->data = data;
    new_Node->left = NULL;
    new_Node->right = NULL;
    new_Node->parent = parent;
    new_Node->height = 0;
    return new_Node;
}

Node * bst_insert(int data)
{
    if( root==NULL)
    {
        root = create_Node(data,NULL);
        return root;
    }

    Node * temp =  root, * position;

    while(temp)
    {
        position = temp;
        if(temp->data>data)
        {
            temp = temp->left;
        }
        else temp = temp->right;
    }

    if(position->data>data)
    { 
        position->left = create_Node(data,position); 
        return position->left;
    }
    else 
    {
        position->right = create_Node(data,position);
        return position->right;
    }
}

Node * search(int data)
{
    Node * temp = root;
    while(temp && temp->data != data)
    {
        if(temp->data>data)
        {
            temp = temp->left;
        }
        else temp = temp->right;
    }

    return temp;
}

int height(Node * x)
{
    if (x == NULL) return -1;
    else return x->height;
}

void update_height(Node * x)
{
    x->height = 1+ max(height(x->left),height(x->right));
}



int balance_factor(Node * x)
{
    return (height(x->left) - height(x->right));
}

void left_rotate(Node *y)
{
    Node * x = y->right;
    Node * xL = x->left;

    x->parent = y->parent;

    if(y==root)
    {
        root = x;
    }
    else
    {
        if(y==y->parent->left) 
            y->parent->left = x;
        else 
            y->parent->right = x;
    }
    
    x->left = y;
    y->parent = x;
    y->right = xL;
    if(xL != NULL)
        xL->parent = y;
    
    Node * temp = y;
    while(temp != NULL)
    {
        update_height(temp);
        temp = temp->parent;
    }
}

void right_rotate(Node * y)
{
    Node * x = y -> left;
    Node * xR = x -> right;
    x -> parent = y -> parent;
    if(y == root) root = x;
    else
    {
        if(y == y -> parent -> left)
        {
            y -> parent -> left = x;
        }
            else y -> parent -> right = x;
    }
    

    x -> right = y;
    y -> parent = x;
    y -> left = xR;

    if(xR != NULL)
    {
        xR -> parent = y;
    }

    Node * temp = y;
    while(temp)
    {
        update_height(temp);
        temp = temp -> parent;
    }
}

Node * max_Node(Node * root)
{
    Node * temp = root, * position;
    while(temp)
    {
        position = temp;
        temp = temp -> right;
    }

    return position;
}

Node * min_Node(Node * root)
{
    Node * temp = root, * position;
    while(temp)
    {
        position = temp;
        temp = temp -> left;
    }

    return position;
}

Node * successor_Node(Node * x)
{
    if(x == max_Node(root)) return NULL;
    else if(x->right != NULL)
    {
        return min_Node(x->right);
    }
    else
    {
        Node * temp = x->parent;
        while(temp->data<x->data)
        {
            temp = temp->parent;
        }
        return temp;
    }
}

void inorder(Node * root)
{
    Node * temp ;
    temp = min_Node(root);

    while(temp)
    {
        cout << temp -> data << "(" << balance_factor(temp) << ")" << " ";
        temp = successor_Node(temp);
    }
}

void balance_Node(Node * temp, int b_fact,Node * newNode)
{
    cout<<"\nImbalance at Node: "<<temp->data<<endl;
    if (b_fact > 1 && newNode->data < temp->left->data)
    {
        cout<<"LL case\n"<<"Right_rotate("<<temp->data<<")"<<endl;
        right_rotate(temp);
    }
    else if (b_fact > 1 && newNode->data > temp->left->data)
    {
        cout<<"LR case\n"<<"Left_rotate("<<temp->left->data<<")"<<",";
        left_rotate(temp->left);
        cout<<"Right_rotate("<<temp->data<<")"<<endl;
        right_rotate(temp);
    }
    else if (b_fact < -1 && newNode->data > temp->right->data)
    {
        cout<<"RR case\n"<<"Left_rotate("<<temp->data<<")"<<endl;
        left_rotate(temp);
    }
    else if (b_fact < -1 && newNode->data < temp->right->data)
    {
        cout<<"RL case\n"<<"Right_rotate("<<temp->right->data<<"),";
        right_rotate(temp->right);
        cout<<"Left_rotate("<<temp->data<<")"<<endl;
        left_rotate(temp);
    }
    cout<<"Status: ";
    inorder(root);
    cout<<endl;
}

void avl_insert(int data)
{
    Node * newNode = bst_insert(data);
    Node * temp = newNode;
    while(temp != NULL)
    {
        update_height(temp);
        temp = temp ->parent;
    }
    temp = newNode;
    inorder(root);
    int flag = 0;
    while(temp != NULL)
    {
        int b_factor = balance_factor(temp);
        if(b_factor <-1 || b_factor >1)
        {
            flag = 1;
            balance_Node(temp,b_factor,newNode);
            break;
        }
        else temp = temp->parent;
    }

    if(flag == 0) cout<<"\nBalanced"<<endl;
}



int main()
{
    while(1)
    {
        int x;
        cin>>x;
        if(x==-1) break;
        avl_insert(x);
        cout<<"Root="<<root->data<<endl<<endl;
    }
    cout << "Status: ";
    inorder(root);

}