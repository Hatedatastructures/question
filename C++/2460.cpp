#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
// 题目：对数组执行操作
// https://leetcode.cn/problems/apply-operations-to-an-array/

class Solution
{
public:
    vector<int> applyOperations(vector<int> &nums)
    {
        if (nums.empty())
        {
            return nums;
        }
        for (int traverse_size = 0; traverse_size < (int)nums.size(); traverse_size++)
        {
            if (traverse_size + 1 > (int)nums.size() - 1)
            {
                break;
            }
            if (nums[traverse_size] == nums[traverse_size + 1])
            {
                nums[traverse_size] = nums[traverse_size] * 2;
                nums[traverse_size + 1] = 0;
            }
        }
        for (int tweaks_size = 0; tweaks_size < (int)nums.size(); tweaks_size++)
        {
            if (nums[tweaks_size] == 0)
            {
                for (int get_size = tweaks_size; get_size < (int)nums.size(); get_size++)
                {
                    if (nums[get_size] != 0)
                    {
                        std::swap(nums[tweaks_size], nums[get_size]);
                        break;
                    }
                }
            }
        }
        return nums;
    }
};
int main()
{

    vector<int> test = {847, 847, 0, 0, 0, 399, 416, 416, 879, 879, 206, 206, 206, 272};
    Solution sl;
    vector<int> ret = sl.applyOperations(test);
    for (auto &e : ret)
    {
        std::cout << e << " ";
    }

    return 0;
}