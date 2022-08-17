#include <iostream>
#include <vector>
#include <unordered_map>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;

// - 两数之和 
// - 暴力解法
vector<int> TwoSum(vector<int> &nums, int target)
{
    vector<int> res(2, -1);
    unsigned int len = nums.size();
    for (int i = 0; i < len; ++i)
    {
        for (int j = i+1; j < len; ++j)
        {
            if (nums[i] + nums[j] == target)
            {
                res[0] = i;
                res[1] = j;
            }
        }
    }
    return res;
}

vector<int> TwoSum(vector<int> &nums, int target, bool flag)
{
    vector<int> res(2, -1);
    unsigned int len = nums.size();
    unordered_map<int, int> value_to_index;
    for (int i = 0; i < len; ++i)
    {
        int finder = target - nums[i];
        if (value_to_index.count(finder))
        {
            res[0] = i;
            res[1] = value_to_index[finder];
            // 减少不必要的计算
            return res;
        } else
        {
            value_to_index[nums[i]] = i;
        }
    }
    return res;
}