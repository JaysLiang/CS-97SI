//
// Created by liangwr on 20-4-7.
//

#include <iostream>
#include <cstddef>
using namespace std;
namespace DataStructure{

    class Stack {
    public:
        Stack(int cap = 64) {
            array = new int[cap];
            this->cap = cap;
            size = 0;
        }
        bool Push(int x) {
            if (size >= cap || !array) {
                return false;
            }

            array[size++]=x;
            return true;
        }
        bool Pop() {
            if (size == 0 || !array) {
                return false;
            }
            size--;
            return true;
        }
        bool Top(int &x) {
            if (size == 0) {
                return false;
            }
            x = array[size-1];
            return true;
        }
        ~Stack() {
            if (array) {
                delete array;
                array = nullptr;
            }
        }
    private:
        uint32_t cap;
        uint32_t size;
        int* array;
    };

}

int main() {
    DataStructure::Stack stack;
    if (!stack.Push(10)) {
        cout<<"push error"<<endl;
    }
    int x = 0;
    if (!stack.Top(x)) {
        cout<< "top error"<<endl;
    }
    if (!stack.Pop()) {
        cout << "pop error" << endl;
    }
    cout<< x <<endl;
}


