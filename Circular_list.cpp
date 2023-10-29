#include<iostream>
using namespace std;

typedef struct Node{
    int data;
    struct Node* next; 
}Node;

Node* last=nullptr;
/*
    last works like tail, last->next works like head
*/
void CL_insert_in_empty(int x){
    // //There's a value in list
    // if(last!=NULL)
    //     return last;

    Node* temp=new Node;
    temp->data=x; last=temp;
    last->next=last;//when one element, self pointing
}

void CL_push_front(int x){
    if(last==NULL){
        CL_insert_in_empty(x);
    }
    Node* temp=new Node;
    temp->data=x;
    temp->next=last->next;
    last->next=temp;
}

Node* CL_push_back(int x){
    if(last==NULL){
        CL_insert_in_empty(x);
    }
    Node* temp=new Node;
    temp->data=x;
    temp->next=last->next;
    last->next=temp;
    last=temp;//Additional line for insert end
    return last;
}

void deleteNode_second(){
    Node* temp=new Node;
    temp=last->next;
    while(temp->next!=temp){
        cout<<temp->next->data<<" ";
        temp->next=temp->next->next;
        temp=temp->next;
    }
    cout<<temp->data;
}

int main(){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        CL_push_back(i);
    }
    deleteNode_second();
}