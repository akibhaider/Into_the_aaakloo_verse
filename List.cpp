#include<list>
#include<iostream>

using namespace std;
/*
operation:
    list.assign(value, ... , );
    ***insert(): Inserting at position, valiue with occurence or multiple occurences
    front(): 
    back();
    push_front():
    push_back():
    pop_front():
    pop_back():
    insert():
    size():
    // Traversing all value; begin() and end() iterator
*/

void showList(list<int> l){
    for(auto c:l){
        cout<<c<<" ";
    }
    cout<<endl;
}

int main(){
    // Use of insert in a list
    list<int> l;
    l.push_front(3);
    l.push_back(5);
    auto it = l.begin();
    advance(it, 1); // it points to 5
    l.insert(it, 2);
    it--;
    l.insert(it, 2, 1);
    showList(l);
    return 0;
}
/*
output: 3 1 1 2 5
*/