class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        map_nums = {}  # 键：数值，值：下标
        for i, num in enumerate(nums):  # i 是索引，num 是值
            complement = target - num
            if complement in map_nums:   # 检查补数是否已经在字典中
                return [map_nums[complement], i]
            map_nums[num] = i           # 没找到，存入当前值及其下标
        return []  