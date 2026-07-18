## 第一版 没有使用双指针,代码比较清晰易懂
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        k , j = 0 , 0
        for i in range(len(nums)):
            if(nums[i] == val):
                nums[i] = -1
                continue
            k += 1
        for i in range(len(nums)):
            if(nums[i] != -1):
                nums[j] = nums[i]
                j += 1
        return k

### 第二版 使用双指针,代码更简洁
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        k , j = 0 , 0
        for i in range(len(nums)):
            if(nums[i] != val):
                nums[j] = nums[i]
                j += 1
                k += 1
        return k