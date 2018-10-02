/*
 * 本脚本用于算法的测试
 */
#include <iostream>
#include "resource/vector.hpp"
using namespace std;

int main() {
    vector<int> test;
    for(int i = 0; i < 100; i++) {
        test.push_back(i);
    }
    cout << test[10] << endl;
    return 0;
}
