class MyCircularQueue {
private:
    int f, r, sz, mxS;
    int* q;
public:
    MyCircularQueue(int k):f(-1), r(-1), sz(0), mxS(k){
          q=new int[k];
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }else{
            if(f==-1){
                f=r=0;
            }else{
                r = (r+1)%mxS;
            }
            q[r]=value;
            sz++;
            return true;
        }
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }else{
            if(f==r){
                f=r=-1;
            }else{
                f=(f+1)%mxS;
            }
            sz--;
            return true;
        }
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }else{
            return q[f];
        }
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }else{
            return q[r];
        }
    }
    
    bool isEmpty() {
        if(f==-1){
            return true;
        }else{
            return false;
        }
    }
    
    bool isFull() {
        if(f==0 && r==mxS-1){
            return true;
        }else if(f==r+1){
            return true;
        }else{
            return false;
        }
    }
    
    int size(){
      return sz;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
