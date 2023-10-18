#include<iostream>
#include<queue>

#define spc " "
#define nl '\n'

using namespace std;

typedef struct Node{
    int data, height;
    struct Node* left, *right, *parent; 
}Node;

Node* root=nullptr;
int Diameter=1;
//first comment

Node* createNode(int x){
    Node* newnode = new Node;
    newnode->data = x;
    newnode->height = 0;
    newnode->left = newnode->right = newnode->parent = nullptr;
}

Node* NodeSearchByValue(int x){
    Node* temp = root;
    while(temp!=nullptr){
        if(x<temp->data){
            temp=temp->left;
        }else if(x>temp->data){
            temp=temp->right;
        }else{
            return temp;
        }
    }
    return nullptr;
}

void PreorderTraversal(Node* temp){
    if(temp==nullptr){
        return;
    }
    cout<<temp->data<<spc;    
    PreorderTraversal(temp->left);
    PreorderTraversal(temp->right);
}

void PostorderTraversal(Node* temp){
    if(temp==nullptr){
        return;
    }
    PostorderTraversal(temp->left);
    PostorderTraversal(temp->right);
    cout<<temp->data<<spc;    
}

void InorderTraversal(Node* temp){
    if(temp==nullptr){
        return;
    }
    InorderTraversal(temp->left);
    cout<<(temp->data)<<spc;
    InorderTraversal(temp->right);
}

void LevelorderTraversal(Node* root){
    queue<Node*>Q;
    Node* temp;
    Q.push(root);
    while(!Q.empty()){
        temp=Q.front();
        cout<<temp->data<<":"<<temp->height<<spc;
        if(temp->left)
            Q.push(temp->left);
        if(temp->right)
            Q.push(temp->right);
        Q.pop();
    }
}

// Min in path, Max in path
int MaxInPath(int x, int y){
    Node* temp = root;
    int mx=y;
    while(temp){
        if(temp->data>mx)mx=temp->data;

        if(temp->data < x){
            temp=temp->right;
        }else if(temp->data > y){
            temp=temp->left;
        }else 
            break;
    }
    while(temp->data != y){
        if(y<temp->data)temp=temp->left;
        else if(y>temp->data)temp=temp->right;
        mx=max(mx, temp->data);
    }
    return mx;
}

void InsertBST(int x){
    Node* n = createNode(x);
    if(root==nullptr){
        root=n;
    }else{
        Node* t=root, *temp;
        while(t!=nullptr){
            temp=t; // temp is parent node whose children will be newnode 
            // Any condition for input data, apply changes here
            if(x<t->data){
                t=t->left;
            }else if(x>t->data){
                t=t->right;
            }
        }
        if(x<temp->data){
            temp->left=n;
            n->parent=temp;
        }else if(x>temp->data){
            temp->right=n;
            n->parent=temp;
        }
        while(1){
            int lh, rh;
            if(temp->left == nullptr)lh = -1;
            else lh=temp->left->height;
            
            if(temp->right == nullptr)rh = -1;
            else rh=temp->right->height;

            temp->height = 1 + max(lh, rh);
            if(temp==root)
                break;
            else
                temp = temp->parent;
        }
    }
}

// Corner case: Most Right node from the root has no successor
Node* Successor(Node* n){
    if(n->right){
        n=n->right;
        while(n->left){
            n=n->left;
        }
        return n;
    }else{
        Node* p = n;
        while(p->data<=n->data){
            p=p->parent;
        }
        return p;
    }
}

void deleteNodeBST(int x){
    Node* n = NodeSearchByValue(x);
    if(n){
        if(n->left == nullptr && n->right == nullptr){
            if(n==n->parent->left){
                n->parent->left=nullptr;
            }else if(n==n->parent->right){
                n->parent->right=nullptr;
            }
        }else if(n->left == nullptr){
            if(n==n->parent->left){
                n->parent->left=n->right;
                n->right->parent=n->parent;
                free(n);
            }else if(n==n->parent->right){
                n->parent->right=n->right;
                n->right->parent=n->parent;
                free(n);
            }
        }else if(n->right == nullptr){
            if(n==n->parent->left){
                n->parent->left=n->left;
                n->left->parent=n->parent;
                free(n);
            }else if(n==n->parent->right){
                n->parent->right=n->left;
                n->left->parent=n->parent;
                free(n);
            }
        }else{
            Node* temp = Successor(n);
            swap(n->data, temp->data);
            if(temp->left==nullptr){
                if(temp==temp->parent->left){
                    temp->parent->left=temp->right;
                    if(temp->right)
                        temp->right->parent=temp->parent;
                    free(temp);
                }else if(temp==temp->parent->right){
                    temp->parent->right=temp->right;
                    if(temp->right)
                        temp->right->parent=temp->parent;
                    free(temp);
                }
            }else if(temp->right==nullptr){
                if(temp==temp->parent->left){
                    temp->parent->left=temp->left;
                    if(temp->left)
                        temp->left->parent=temp->parent;
                    free(temp);
                }else if(n==n->parent->right){
                    temp->parent->right=temp->left;
                    if(temp->left)
                        temp->left->parent=temp->parent;
                    free(temp);
                }
            }
        }
    }
    // LevelorderTraversal(root);
}

void DiameterBST(Node* temp){
    if(temp==nullptr){
        return;
    }
    if(temp->left && temp->right){
        int lh=temp->left->height, rh=temp->right->height;
        Diameter=max(Diameter, lh+rh+3);
    }
    DiameterBST(temp->left);
    DiameterBST(temp->right);
}

int LowestCommonAncestorBST(int x, int y){
    Node* temp=root;
    while(x>temp->data || temp->data>y){
        if(temp->data<x){
            temp=temp->right;
        }else if(temp->data>y){
            temp=temp->left;
        }
    }
    return temp->data;
}

int main(){
    int n, x, y, q;
    while(cin>>n){
        if(n==-1){
            break;
        }
        InsertBST(n);
    }
    // PostorderTraversal(root);
    // DiameterBST(root);
    // cout<<Diameter;
    // cout<<"(initial)"<<nl;
    // cin>>q;
    // while(q--){
    //     cin>>x>>y;
    //     middleNodeFindBST(x, y);
    // }
    // cin>>q;
    // while(q--){
    //     cin>>x;
    //     deleteNodeBST(x);
    //     cout<<nl;
    // }
    cin>>q;
    while(q--){
        cin>>x>>y;
        cout<<LowestCommonAncestorBST(min(x, y), max(x, y));
        cout<<nl;
    }

    return 0;
}