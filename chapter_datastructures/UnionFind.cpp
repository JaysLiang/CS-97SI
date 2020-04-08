//
// Created by luck on 2020/4/8.
//

#include <iostream>
#include <cstddef>
using namespace std;
namespace DataStructure{
    class UnionSet {
    public:
        UnionSet(int cap){
            data = new int[cap];
            this->cap = cap;
            for (int i = 0; i< cap ;i ++) {
                data[i] = i;
            }
        }

        ~UnionSet() {
            if (data){
                delete(data);
                data = nullptr;
            }
        }
        int find_with_reroot(int x) {
            if (x == data[x]) {
                return x;
            }
            int root  = find(x);
            data[x] = root;
            return root;
        }
        int find(int x) {
            while(x != data[x]) {
                x = data[x];
            }
            return x;
        }
        void Union(int x, int y) {
            data[find(x)] = find(y);
        }

    private:
        //assume data are stored in data array
        int *data;
        uint32_t size;
        uint32_t cap;
    };

}

int main() {
    DataStructure::UnionSet unionSet(10);
    cout<< unionSet.find(3) <<endl;
    unionSet.Union(3,1);
    cout<< unionSet.find(3) <<endl;
    unionSet.Union(1,5);
    cout<< unionSet.find(1) <<endl;
    cout<< unionSet.find(3) <<endl;
}