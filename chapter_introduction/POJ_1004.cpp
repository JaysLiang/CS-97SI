//
// Created by liangwr on 20-4-6.
//

#include <iostream>
using namespace std;

int main() {
    double tmp = 0.0;
    double sum=0.0;
    for (int i = 0 ; i<12; i++) {
        cin>>tmp;
        sum+=tmp;
    }
    cout <<"$"<<sum/12.0 << std::endl;
}
