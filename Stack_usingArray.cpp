#include<iostream>
#define nl '\n'

using namespace std;

class Stack_usingArray{
    private:
        int tp, st[1000], maxSize;
    public:
        Stack_usingArray(int sz){
            tp=0;
            maxSize=sz;
        }
        void push(int v){
            st[tp]=v;
            tp++;
            if(tp>maxSize){
                tp=maxSize;
                cout<<"Overflow"<<nl;
            }else{
                display();
            }
        }
        void pop(){
            tp--;
            if(tp<0){
                tp=0;
                cout<<"Underflow"<<nl;
            }else{
                display();
            }
        }
        void isEmpty(){
            (!tp)? cout<<"True"<<nl:cout<<"False"<<nl;
        }
        void isFull(){
            (tp==maxSize)? cout<<"True"<<nl:cout<<"False"<<nl;
        }
        int size(){
            return tp;
        }
        int top(){
            return st[tp-1];
        }
        void display(){
            for(int i=0; i<tp; i++){
                cout<<st[i]<<" ";
            }
            cout<<nl;
        }
};

int main(){
    int cmd, val;
    cin>>val;
    Stack_usingArray s(val);
    while(1){
        cin>>cmd;
        if(cmd==-1){
            break;
        }else if(cmd==1){
            cin>>val;
            s.push(val);
        }else if(cmd==2){
            s.pop();
        }else if(cmd==3){
            s.isEmpty();
        }else if(cmd==4){
            s.isFull();
        }else if(cmd==5){
            cout<<s.size()<<nl;
        }else if(cmd==6){
            cout<<s.top()<<nl;
        }
    }
}
/*
5
3
2
1 10
1 20
5
1 30
6
2
1 40
1 50
4
1 60
4
5
1 60
5
2 
6
-1
*/