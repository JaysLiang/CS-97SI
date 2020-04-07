//
// Created by liangwr on 20-4-7.
//

#include <cstddef>
#include <iostream>
using namespace std;

namespace DataStructure{
    class Queue {
    public:
        Queue(int cap = 64) {
            array = new int[cap];
            this->cap = cap;
            head = 0;
            size = 0;
        }
        ~Queue() {
            if (array) {
                delete array;
                array = nullptr;
            }
        }
        bool Enqueue(int data) {
            if (!array || size == cap) {
                return false;
            }
            array[(head+size)%cap] = data;
            size++;
            return true;
        }
        bool Dequeue(int &data) {
            if (!array || !size ) {
                return false;
            }
            data=array[head];
            head = (head+1)%cap;
            size--;
            return true;
        }
    private:
        uint32_t  cap;
        uint32_t  head;
        uint32_t  size;
        int* array;
    };
}

int main() {
    DataStructure::Queue queue(4);
    for (int i = 0; i <4; i++) {
        if (!queue.Enqueue(i)) {
            cout<<"engque false"<<endl;
        }
    }

    if (queue.Enqueue(5)) {
        cout<< "expect false"<<endl;
    }

    for (int i = 0; i <4; i++) {
        int data = 0;
        if (!queue.Dequeue(data)) {
            cout<<"engque false"<<endl;
        }
        cout <<"dequeue: "<< data <<endl;
    }
    int data = 0;
    if (queue.Dequeue(data)) {
        cout<< "expect false"<<endl;
    }

    for (int i =0 ; i< 100; i++ ) {
        if (!queue.Enqueue(i)) {
            cout<<"engque false"<<endl;

        }
        int data = 0;
        if (!queue.Dequeue(data)) {
            cout<<"engque false"<<endl;
        }
        cout <<"dequeue: "<< data <<endl;
    }
}
