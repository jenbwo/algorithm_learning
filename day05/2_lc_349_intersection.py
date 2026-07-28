class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        #   首先要去重
        res = []
        unique_nums1 = set(nums1)
        unique_nums2 = set(nums2)
        for i in unique_nums2:
            if i in unique_nums1:
                res.append(i)
        return res