//
// Created by liangwr on 20-4-6.
//

#include <iostream>


class POJ_1000 {
public:
    int Solution(int a, int b) {
        return a+b;
    }
};
int main() {
    POJ_1000 poj;
    int a,b;
    std::cin >> a;
    std::cin >> b;
    auto ret = poj.Solution(a, b);
    std::cout<<"result is "<< ret <<std::endl;
    return 0;
}