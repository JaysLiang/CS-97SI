//
// Created by liangwr on 20-4-6.
//

// memorize math knowledge
#include <iostream>
#include <cstddef>
using namespace std;


namespace Math{
    //
    //  ∑ k^2 =1/6 *n * (n+ 1)*(2*n+ 1)
    // k=1
    //
    //
    static uint32_t SumOfSquare(uint32_t i) {
        return i * (i+1) *(2*i+1) / 6;
    }
    //
    //  ∑ k^3 = ( ∑ k^2)^2 = (1/2 *n*(n+1))2
    // k=1       k=1
    //
    //
    static uint32_t SumOfCube(uint32_t i) {
        uint32_t tmp = (i* (i+1))/2;
        return tmp*tmp;
    }

    //
    static double Pow(double i, uint32_t n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return i;
        double t = Pow(i, n/2);
        return t * t * Pow(i, n%2);
    }
}


int main () {
    cout<< Math::SumOfSquare(2)<<endl;
    cout<< Math::SumOfCube(2)<<endl;
    cout<< Math::Pow(2,2)<<endl;
}


