/*
 * 本脚本用于算法的测试
 */
#include <iostream>
#include "resource/list.hpp"
using namespace std;

int main() {
    hx::list<int> test;
    test.push_front(3);
    test.push_front(5);
    test.push_back(1);
    test.push_back(1);
    test.disp();
    cout << test.find(1) << endl;
    cout << test.find(10) << endl;
    return 0;
}
