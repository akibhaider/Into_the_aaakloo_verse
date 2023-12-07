/* Check for precedence, The one with least precedence will be the root the that subtree */
/* 
Precedence list (from low to high): 
(+,-):=[L->R] 
(/,*):=[L->R]
(^):=[R->L]
*/

#include<bits/stdc++.h>

using namespace std;

class node{
    public:
        char value;
        node *left, *right, *next=nullptr;
        node(char c){
            this->value=c;
            right=left=nullptr;
        }
        node(){
            left=right=nullptr;
        }
        friend class 
}


