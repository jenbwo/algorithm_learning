//  学习一个新的结构，C++中的unordered_set。该结构特性很多，元素是无序且不存在重复的！
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        //  这一步操作，是把nums1数组放到set1集合里面，这样set1里面就自动去重了。
        unordered_set<int> set1(nums1.begin(), nums1.end());
        vector<int> res;
        //  迭代器遍历循环
        for (int num : nums2)
        {
            if (set1.find(num) != set1.end())
            {
                res.push_back(num);
                set1.erase(num);
            }
        }
        return res;
    }
};