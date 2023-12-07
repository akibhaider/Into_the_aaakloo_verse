#include<iostream>
#include<queue>
#include<stack>

#define spc " "
#define nl '\n'

using namespace std;

typedef struct Node{
    int data, height;
    struct Node* left, *right, *parent; 
}Node;

Node* root=nullptr;
int Diameter=1;

Node* createNode(int x){
    Node* newnode = new Node;
    newnode->data = x;
    newnode->height = 0;
    newnode->left = newnode->right = newnode->parent = nullptr;
}

// Arg: key to search for
// O(H), O(1)
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

// Arg: root
// O(N), O(H)
void PreorderTraversal(Node* temp){
    if(temp==nullptr){
        return;
    }
    cout<<temp->data<<spc;    
    PreorderTraversal(temp->left);
    PreorderTraversal(temp->right);
}

// Arg: root
// O(N), O(height of recursion stack)
void PostorderTraversal(Node* temp){
    if(temp==nullptr){
        return;
    }
    PostorderTraversal(temp->left);
    PostorderTraversal(temp->right);
    cout<<temp->data<<spc;    
}

// Arg: root
// O(N), O(height of recursion stack)
void InorderTraversal(Node* temp){
    if(temp==nullptr){
        return;
    }
    InorderTraversal(temp->left);
    cout<<(temp->data)<<spc;
    InorderTraversal(temp->right);
}

// Arg: root
// O(N), O(N/2)
void LevelorderTraversal(Node* root){
    queue<Node*>Q;
    Node* temp;
    Q.push(root);
    while(!Q.empty()){
        int i=1;
        int nodeInlevel = Q.size();
        while(nodeInlevel--){
            cout<<"Level "<<i<<": ";
            temp=Q.front();
            if(temp==root){
                cout<<temp->data<<"(null)"<<spc;    
            }else{
                cout<<temp->data<<"("<<temp->parent->data<<")"<<spc;         
            }
            if(temp->left)
                Q.push(temp->left);
            if(temp->right)
                Q.push(temp->right);
            Q.pop();
            i++;
        } 
        cout<<nl;     
    }
}

// Arg: key of two node
// ret: Max key of a node in the path
// O(H), O(1)
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
    // max will be always in the right subtree from LCA; So traverse LCA to y
    while(temp->data != y){
        if(y<temp->data)temp=temp->left;
        else if(y>temp->data)temp=temp->right;
        mx=max(mx, temp->data);
    }
    return mx;
}

// Arg: key of two node
// ret: Min key of a node in the path
// O(H), O(1)
int MinInPath(int x, int y){
    Node* temp = root;
    int mn=x;
    while(temp){
        if(temp->data<mn)mn=temp->data;

        if(temp->data < x){
            temp=temp->right;
        }else if(temp->data > y){
            temp=temp->left;
        }else 
            break;
    }
    // min will always be in the left subtree from LCA; traverse LCA to x
    while(temp->data != x){
        if(x<temp->data)temp=temp->left;
        else if(x>temp->data)temp=temp->right;
        mn=min(mn, temp->data);
    }
    return mn;
}
// Arg: Node to be inserted
// O(H), O(1)
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

// Arg: query node
// ret: Successor node
// O(H), O(1)
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
            if(p==root){
                return nullptr;
            }
        }
        return p;
    }
}

// Arg: query node
// ret: Predecessor node
// O(H), O(1)
Node* Predecessor(Node* n){
    if(n->left){
        n=n->left;
        while(n->right){
            n=n->right;
        }
        return n;
    }else{
        Node* p=n;
        while(p->data>=n->data){
            p=p->parent;
            if(p==root){
                return nullptr;
            }
        }
        return p;
    }
}

// Arg: Node to be deleted
// O(H), O(1)
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
}

// arg: Recursive fn starting with root
// No ret-type; Update Diamter
// O(H), O(H)
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

// Arg: Key of two node
// Ret: LCA node 
// O(H), O(1)
Node* LowestCommonAncestorBST(int x, int y){
    Node* temp=root;
    while(x>temp->data || temp->data>y){
        if(temp->data<x){
            temp=temp->right;
        }else if(temp->data>y){
            temp=temp->left;
        }
    }
    return temp;
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