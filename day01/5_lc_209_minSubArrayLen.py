class Solution(object):
    def minSubArrayLen(self, target, nums):
        """
        :type target: int
        :type nums: List[int]
        :rtype: int
        """

        # 用python来思考一下最快的滑动窗口算法
        '''
        :left       初始化一个左边界
        :sum_sub    用于求子串的和
        :right      控制右边界
        :res        求最终结果
        :sub_len    窗口内子串最小长度
        '''
        max_value = sys.maxsize
        left = 0
        sum_sub = 0
        res = max_value
        sub_len = 0
        for right in range(len(nums)):
            sum_sub += nums[right]
            while(sum_sub >= target):
                sub_len = right - left + 1
                res = min(res, sub_len)
                sum_sub -= nums[left]
                left += 1
        if(max_value == res):
            return 0
        else:
            return res


        