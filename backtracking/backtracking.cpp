#include "backtracking.h"
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>

using std::vector;
using std::string;
using std::to_string;
using std::stoi;
using std::stack;
using std::queue;
using std::unordered_map;

vector<int> path;
vector<vector<int>> res;
void Combination(int n, int k, int begin_index)
{
    // 结束条件
    if (path.size() == k)
    {
        res.emplace_back(path);
        return ;
    }

    // 递归遍历
    for (int i = begin_index; i < n; ++i)
    {
        path.emplace_back(i);
        Combination(n, k, i+1);
        path.pop_back();
    }
}
