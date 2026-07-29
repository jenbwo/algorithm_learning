class Solution:
    def reverseWords(self, s: str) -> str:
        # 1. 字符串转列表，便于原地修改
        arr = list(s)
        n = len(arr)

        # === 第一步：去除多余空格（快慢指针） ===
        slow = 0
        fast = 0
        while fast < n:
            # 跳过所有空格
            while fast < n and arr[fast] == ' ':
                fast += 1
            # 如果还有单词，且不是第一个单词，则补一个空格
            if fast < n and slow != 0:
                arr[slow] = ' '
                slow += 1
            # 复制整个单词（直到遇到空格或结尾）
            while fast < n and arr[fast] != ' ':
                arr[slow] = arr[fast]
                slow += 1
                fast += 1
        # 截断到有效长度
        arr = arr[:slow]

        # === 第二步：整体反转（双指针交换） ===
        left, right = 0, len(arr) - 1
        while left < right:
            arr[left], arr[right] = arr[right], arr[left]
            left += 1
            right -= 1

        # === 第三步：反转每个单词（双指针定位边界） ===
        start = 0
        for i in range(len(arr) + 1):
            # 遇到空格或末尾，反转 [start, i-1]
            if i == len(arr) or arr[i] == ' ':
                l, r = start, i - 1
                while l < r:
                    arr[l], arr[r] = arr[r], arr[l]
                    l += 1
                    r -= 1
                start = i + 1

        return ''.join(arr)