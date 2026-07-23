class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); //  1.先把数组进行排序
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                return result; //  2.如果第一个元素就大于0，那三数之后肯定不会等于0
            if (i > 0 && nums[i] == nums[i - 1])
                continue; //  3.把i去重先
            int left = i + 1, right = nums.size() - 1;
            while (right > left)
            { //  4.大了减掉最右边的
                if (nums[i] + nums[left] + nums[right] > 0)
                    right--; //  5.小了左边继续往后靠
                else if (nums[i] + nums[left] + nums[right] < 0)
                    left++;
                else
                {
                    //  6.得到结果先收集
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    //  7.去重right
                    while (right > left && nums[right] == nums[right - 1])
                        right--;
                    //  8.去重left
                    while (right > left && nums[left] == nums[left + 1])
                        left++;
                    //  9.继续查找下一个结果
                    left++;
                    right--;
                }
            }
        }
        return result;
    }
};