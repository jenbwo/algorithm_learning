//  看来这个map很好用，首先将数据一分为二，然后再进行统计!
class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int, int> map_nums;
        for (int num1 : nums1)
            for (int num2 : nums2)
                map_nums[num1 + num2]++;
        int count = 0;
        for (int num3 : nums3)
            for (int num4 : nums4)
                if (map_nums.find(0 - (num3 + num4)) != map_nums.end())
                    count += map_nums[0 - (num3 + num4)];
        return count;
    }
};