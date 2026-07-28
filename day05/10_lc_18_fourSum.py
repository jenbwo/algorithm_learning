class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        res = []
        
        # 特判：少于 4 个数无法组成四元组
        if n < 4:
            return res
        
        # 第一层循环（第一个数）
        for i in range(n - 3):
            # 去重：跳过重复的 i
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            
            # 剪枝1：当前最小的四个数和 > target，后面更大的 i 只会更大，直接 break
            if nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target:
                break
            
            # 剪枝2：当前 i 与最大的三个数相加仍 < target，说明 i 太小，继续下一个 i
            if nums[i] + nums[n-1] + nums[n-2] + nums[n-3] < target:
                continue
            
            # 第二层循环（第二个数），完全等价于 3Sum 的外层循环
            for j in range(i + 1, n - 2):
                # 去重：跳过重复的 j
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                
                # 剪枝1（内层）：当前最小的四个数（固定 i,j）> target，break
                if nums[i] + nums[j] + nums[j+1] + nums[j+2] > target:
                    break
                
                # 剪枝2（内层）：当前 j 与 i 及最大的两个数相加仍 < target，continue
                if nums[i] + nums[j] + nums[n-1] + nums[n-2] < target:
                    continue
                
                # 双指针（完全复用 3Sum 的内核）
                left, right = j + 1, n - 1
                while left < right:
                    total = nums[i] + nums[j] + nums[left] + nums[right]
                    
                    if total < target:
                        left += 1
                    elif total > target:
                        right -= 1
                    else:
                        res.append([nums[i], nums[j], nums[left], nums[right]])
                        
                        # 去重左指针
                        while left < right and nums[left] == nums[left + 1]:
                            left += 1
                        # 去重右指针
                        while left < right and nums[right] == nums[right - 1]:
                            right -= 1
                        
                        left += 1
                        right -= 1
        
        return res