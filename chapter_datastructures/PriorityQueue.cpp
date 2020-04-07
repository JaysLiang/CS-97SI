//
// Created by liangwr on 20-4-7.
//
#include <cstddef>
#include <iostream>
using namespace std;

namespace DataStructure{
    typedef struct Node{
        int priority;
        int val;
    }Node;
    class Heap {
    public:
        Heap(int cap) {
//            this->cap = cap & 0xffffffff;
            this->cap = cap;
            node_array = new Node[this->cap];
            this->size = 0;
        }
        ~Heap() {
            if (node_array) {
                delete(node_array);
                node_array = nullptr;
            }
        }
        uint32_t Size() {
            return size;
        }

        uint32_t Cap() {
            return cap;
        }
        bool insert(int val, int priority) {
            if (!node_array || size>=cap) {
                return false;
            }
            int pos = size ;
            while( pos !=0 && priority > node_array[(pos-1)/2].priority) {
                node_array[pos].priority =node_array[(pos-1)/2].priority;
                node_array[pos].val =node_array[(pos-1)/2].val;
                pos = (pos-1)/2;
            }
            node_array[pos].priority = priority;
            node_array[pos].val = val;
            size++;
            return true;
        }
        bool RemoveTop() {
            if (!node_array || size == 0) {
                return false;
            }
            int pos = 0;
            while((pos*2+2)<size ) {
                int tmp = pos*2 +1;
                if (node_array[pos*2+1].priority < node_array[pos*2+2].priority) {
                    tmp = pos*2 +2;
                }
                node_array[pos].priority = node_array[tmp].priority;
                node_array[pos].val = node_array[tmp].val;
                pos = tmp;
            }
            if (pos*2+2 == size) {
                node_array[pos].priority = node_array[pos*2+1].priority;
                node_array[pos].val = node_array[pos*2+1].val;
            }
            size--;
            return true;
        }
        bool GetTop(int& val, int& priority) {
            if (!node_array || size == 0) {
                return false;
            }
            val = node_array[0].val;
            priority = node_array[0].priority;
            return true;
        }
        void Debug() {
            cout<< "tree:"<<endl;
            for (int i = 0; i< size ;i++){
                cout<<node_array[i].priority <<node_array[i].val;
            }
            cout<<endl;
        }
    private:
        Node *node_array;
        uint32_t size;
        uint32_t cap;
    };

    class PriorityQueue {
    public:
        PriorityQueue(int size){
            heap = new Heap(size);
        }
        ~PriorityQueue(){
            if (heap) {
                delete(heap);
                heap = nullptr;
            }
        }

        bool Insert(int x, int priority) {
            return heap->insert(x,priority);
        }
        bool RemoveTop() {
            return heap->RemoveTop();
        }

        bool Top(int& x, int& priority) {
            return heap->GetTop(x, priority);
        }

        void Debug() {
            heap->Debug();
        }

    private:
        uint32_t size() {
            if (heap)
                return heap->Size();
            return 0;
        }
        Heap *heap;
    };

}

int main() {
    DataStructure::PriorityQueue PQ(7);
    for(int i = 1; i < 8 ;i ++ ){
        if (!PQ.Insert(i, i)) {
            cout<<"insert failed: "<<i <<endl;
        }
        PQ.Debug();
    }
    for(int i = 1; i < 8 ;i ++ ){
        int data = 0;
        int priority = 0;
        if (!PQ.Top(data, priority)) {
            cout<<"Top failed: "<<i <<endl;
        }

        cout<<priority<<" " <<data<<endl;
        PQ.Debug();
        if (!PQ.RemoveTop()) {
            cout<<"RemoveTop failed: "<<i <<endl;
        }

    }
}