/*
 * 本脚本用于算法的测试
 */
#include <iostream>
#include "resource/vector.hpp"

using namespace std;
int main() {
    int a[] = {1, 2, 3, 4, 5};
    vector<int> test(a, 0, 5);
    cout << test[13] << endl;
    return 0;
}