#include <iostream>
#include <vector>
#include <climits>
using namespace std;
//  先用暴力解法尝试一下，两个for循环,有一个测试用例通不过，超时了，看来必须要用双指针了！

/*
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //  先定义个大的子串size
        int min_size = INT32_MAX;
        //  定义sum求和，local_size 求局部最小子串
        int sum = 0, local_size = 0;
        for(int i = 0; i < nums.size(); i++){
            sum = 0;
            for(int j = i; j < nums.size() ; j++){
                sum += nums[j];
                if(sum >= target){
                    local_size = j - i + 1;
                    min_size = min_size < local_size? min_size : local_size;
                    break;
                }
            }
        }
        return min_size == INT32_MAX ? 0 : min_size;
    }
};

*/

//  使用滑动窗口，固定一个大小
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        //  先定义个大的子串size
        int min_size = INT_MAX; // INT32_MAX → INT_MAX，<climits> 中定义
        //  sum用于求和总结
        int sum = 0;
        //  j是滑动窗口的左边位置
        int j = 0;
        //  i是滑动窗口的右边位置
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            //  当sum比target大的时候，进入子串调整环节
            while (sum >= target)
            {
                int current_len = i - j + 1;
                min_size = min_size > current_len ? current_len : min_size;
                sum -= nums[j];
                j++;
            }
        }
        return min_size == INT_MAX ? 0 : min_size;
    }
};

//  本地测试入口
int main()
{
    Solution s;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    int result = s.minSubArrayLen(target, nums);
    cout << "target = " << target << ", result = " << result << endl;
    // 预期输出: 2（子数组 [4,3] 的和为 7）
    return 0;
}