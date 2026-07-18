//  第一次解，没有使用双指针，两个for循环，第一个for循环标记相等的
//  第二个for循环进行覆盖
/*
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                nums[i] = -1;
                continue;
            } else {
                k++;
            }
        }
        for(int i = 0, j = 0; i < nums.size() && j < nums.size(); i++){
            if(nums[i] != -1){
                nums[j] = nums[i];
                j++;
            }
        }
        return k;
    }
};

*/

//  第二次解法，使用双指针
//  犯了一次糊涂，以为前n个必须要是k，题目没有读对导致一直想着两个for循环，一个先把k求出来，另外一个再把前k个倒回来！所以说示例输出要看清楚了！
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};