//
// Created by liangwr on 20-4-6.
//

#include <iostream>
#include <vector>
using namespace std;

class POJ_1004 {
public:
    double FinancialManagement(vector<double> &vec) {
        double  sum = 0;
        for (auto s: vec) {
            sum+=s;
        }
        return sum/12.0;
    }
};

int main() {
    vector<double> vec;
    double tmp = 0.0;
    for (int i = 0 ; i<12; i++) {
        cin>>tmp;
        vec.push_back(tmp);
    }
    POJ_1004 poj;
    cout << poj.FinancialManagement(vec) << std::endl;
}
