/*
 * 本脚本用于算法的测试
 */
#define STL_TEST 0

#include <iostream>

#ifndef STL_TEST
#include <vector>
#else
#include "resource/vector.hpp"
#endif

int main() {
    #ifndef STL_TEST
    std::vector<int> test = {1, 2, 3, 4, 5};
    std::cout << test[3] << std::endl;
    #else
    vector<int> test;
    for(int i = 1; i < 6; i++)
        test.push_back(i);
    std::cout << test[3] << std::endl;
    #endif
    return 0;
}