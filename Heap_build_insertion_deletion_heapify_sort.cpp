/*
Complete BT -> No missing element from left to right
Full BT -> l levels have pow(2, (l+1))-1 nodes
N nodes -> log(N) height
indexing: (0 to size-1)=> children: 2*i+1, 2*i+2; parent: (i-1)/2 
heapify -> Fixing one node; O(logN)
build_max/min_heap -> O(N)
insertion -> O(logN) [insert at back->heapify]
Deletion from root -> O(logN) [swap root and last node->remove last node->heapify]
heap_sort -> O(logN)
*/

#include<iostream>
#include<deque>

using namespace std;

void max_heapify(deque<int>& heap, int i){
    int l=2*i+1, r=l+1, boro=i;//boro holding index
    if(heap[l]>heap[boro] && l<heap.size())
        boro=l;
    if(heap[r]>heap[boro] && r<heap.size()) 
        boro=r;
    if(boro!=i){
        heap[boro]^=heap[i]^=heap[boro]^=heap[i];
        max_heapify(heap, boro);
    } 
    else 
        return ;
}

void build_heap(deque<int>& heap){
    for(int i=(heap.size()-1)/2; i>=0; i--){
        max_heapify(heap, i);
    }
}
//Insertion by value
void heap_insertion(deque<int>& heap, int n){
    heap.push_back(n);
    int k=heap.size()-1;
    while(heap[k]>heap[(k-1)/2] && k>0){
        heap[k]^=heap[(k-1)/2]^=heap[k]^=heap[(k-1)/2];
        k=(k-1)/2;
    }
}
//Deletion from root
void heap_deletion(deque<int>& heap){
    cout<<heap[0]<<" ";
    heap.pop_front();
    heap.push_front(heap.back());
    heap.pop_back();
    max_heapify(heap, 0);
}

void heap_sort(deque<int> hp){
    int k=hp.size();
    for(int i=0; i<k; i++){
        heap_deletion(hp);
    }
}

signed main(){
    int in;
    deque<int> heap;
    while(cin>>in){
        if(in==-1)
            break;
        else{
            heap.push_back(in);
        }
    }
    build_heap(heap);
    heap_insertion(heap, 9);
    cout<<"Max Heap: ";
    for(int i=0; i<heap.size(); i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl<<"Sorted: ";
    heap_sort(heap);
    return 0;
}