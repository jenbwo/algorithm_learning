//  和三数量之和的解答几乎一致，就是加了一个for循环。
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int left = j + 1, right = nums.size() - 1;
                while (right > left)
                {
                    if ((long)nums[i] + nums[j] + nums[left] + nums[right] > target)
                        right--;
                    else if (nums[i] + nums[j] < target - nums[left] - nums[right])
                        left++;
                    else
                    {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (right > left && nums[right] == nums[right - 1])
                            right--;
                        while (right > left && nums[left] == nums[left + 1])
                            left++;
                        left++;
                        right--;
                    }
                }
            }
        }
        return result;
    }
};