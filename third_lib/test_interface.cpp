//
// Created by 燕文豪 on 2022/7/27.
//
#include "test_interface.h"
// 去除左侧空格
void TrimLeftTrailingSpaces(string &input)
{
    for (auto it = input.begin(); it != input.end(); ++it)
    {
        if (!isspace(*it))
        {
            input.erase(input.begin(), it);
            return ;
        }
    }
}

void TrimRightTrailingSpaces(string &input)
{
    for (unsigned int i = input.size()-1; i >= 0; --i)
    {
        if (isspace(input[i])) input.pop_back();
        else return ;
    }
}
