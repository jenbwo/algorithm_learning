/*  个人反思：这个代码是自己第一次写的，根据执行逻辑，在nums = [-1], target = 2
    的测试案例中失败了，主要原因我想了想就是右边界在初始化没有减一，导致nums
    的index超过最大的0而报错。
*/

//  自己手搓，这是经典的二分搜索，但是是左右边界都是闭区间，故边界判断条件考虑没那么完善。
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1, mid = 0;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            if (nums[mid] == target)
            {
                return mid;
            }
        }
        return -1;
    }
};

/*

ds给的代码确实更好，考虑了溢出问题！

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 处理空数组的边界情况
        if (nums.empty()) {
            return -1;
        }

        int left = 0;
        int right = (int)nums.size() - 1;  // 显式转为 int，避免无符号回绕

        while (left <= right) {
            // 防止 (left + right) 溢出
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;                // 找到目标，返回索引
            } else if (nums[mid] < target) {
                left = mid + 1;            // 目标在右半区间
            } else { // nums[mid] > target
                right = mid - 1;           // 目标在左半区间
            }
        }
        return -1;                         // 未找到
    }
};

*/

// 如果是左闭右开的条件

/*
    while(left < right)
    需要更改这个，因为，left == right 无意义
    另外就是 right = nums.size()，因为是定义左闭右开。
*/
