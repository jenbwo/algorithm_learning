from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        res = []
        
        # 剪枝：最小元素大于0，不可能有三元组和为0
        if n < 3 or nums[0] > 0:
            return res
        
        for i in range(n - 2):
            # 去重：跳过重复的 i
            if i > 0 and nums[i] == nums[i-1]:
                continue
            
            # 剪枝1：当前最小的三个数和 >0，后面的 i 更大，和只会更大，直接退出
            if nums[i] + nums[i+1] + nums[i+2] > 0:
                break
            
            # 剪枝2：当前 i 与最大的两个数相加仍 <0，说明 i 太小，继续下一个 i
            if nums[i] + nums[-1] + nums[-2] < 0:
                continue
            
            left, right = i + 1, n - 1
            while left < right:
                total = nums[i] + nums[left] + nums[right]
                if total > 0:
                    right -= 1
                elif total < 0:
                    left += 1
                else:
                    res.append([nums[i], nums[left], nums[right]])
                    # 跳过重复的 left 和 right
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1
                    left += 1
                    right -= 1
        return res