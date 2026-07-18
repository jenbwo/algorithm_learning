from typing import List

def function(nums: List[int], target: int) -> int:
    left = 0
    right = len(nums) - 1
    while(left <= right):
        mid = int(left + (right - left) / 2)
        if(nums[mid] < target):
            left = mid + 1
        elif(nums[mid] > target):
            right = mid - 1
        elif(nums[mid] == target):
            return mid
        
    return -1

if __name__ == "__main__":
    nums = [0, 1, 2, 3]
    target = 3
    print(function(nums, target))

