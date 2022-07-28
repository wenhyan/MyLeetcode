//
// Created by 燕文豪 on 2022/7/26.
//

#ifndef LEETCODE_TEST_INTERFACE_H
#define LEETCODE_TEST_INTERFACE_H

#include <string>
#include <vector>

using std::string;
using std::vector;

// 去掉左边的空格
void TrimLeftTrailingSpaces(string &input);
void TrimRightTrailingSpaces(string &input);
vector<int> StringToIntegerVector(string &input);

#endif //LEETCODE_TEST_INTERFACE_H
