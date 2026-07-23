//  又学习到一个新的数据结构——unordered_map，不仅可以存储数据，还可以存储下标！
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map1;
        for (int i = 0; i < nums.size(); i++)
        {
            //  这条语句的作用就是看是否查找成功
            if (map1.find(target - nums[i]) != map1.end())
                return {map1[target - nums[i]], i};
            else
            {
                //  如果没有就把当前的nums[i]中的数添加进去！
                map1[nums[i]] = i;
            }
        }
        return {};
    }
};