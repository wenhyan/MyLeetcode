#include <iostream>
#include "third_lib/test_interface.h"
#include "binary_tree/binary_tree.h"
#include "backtracking/backtracking.h"

using std::cout;
using std::endl;

extern vector<int> path;
extern vector<vector<int>> res;
int main() {
    int n = 4;
    int k = 2;
    Combination(n, k, 1);
    for (auto &item : res)
    {
        for (auto &it : item)
            cout << it << " ";
        
        cout << endl;
    }
    return 0;
}
