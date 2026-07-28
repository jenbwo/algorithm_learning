class Solution:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        #   普通字典 map_num = {}
        # 1. 读取：检查 key=5 存在吗？不存在！ -> 直接抛出 KeyError (程序停止)
        # 2. 加法：根本不会执行到这里
        # 3. 赋值：根本不会执行到这里

        #   使用defaultdict(int)
        # 1. 读取：检查 key=5 存在吗？不存在！ -> 调用 int() 得到 0，插入 {5: 0}，返回 0
        # 2. 加法：0 + 1 = 1
        # 3. 赋值：执行 map_num[5] = 1，字典变成 {5: 1}
        map_num = defaultdict(int)
        for i in nums1:
            for j in nums2:
                map_num[i + j] += 1
        count = 0 
        for i in nums3:
            for j in nums4:
                if (- i - j) in map_num:
                    count += map_num[- i - j]
        return count