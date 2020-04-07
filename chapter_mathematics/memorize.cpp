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
    namespace NumberTheory {
        int gcd(int a, int b) {
            while(b) {
                int r = a%b;
                a=b, b=r;
            }
            return a;
        }
        int reverseModBrute(int a, int n) {
            //brute
            for (int i = 1; i < n; i++){
                if (a * i % n == 1) {
                    return i;
                }
            }
            return -1;
        }
    }
}


int main () {
    cout<< Math::SumOfSquare(2)<<endl;
    cout<< Math::SumOfCube(2)<<endl;
    cout<< Math::Pow(2,2)<<endl;
    cout<< Math::NumberTheory::gcd(5,3)<<endl;
    cout<< Math::NumberTheory::gcd(6,3)<<endl;
    cout<< Math::NumberTheory::reverseModeBrute(14,3)<<endl;
}


