#  这切片有这么好用吗?
class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        res = list(s)  # 字符串不可变，转成列表便于修改
        for i in range(0, len(s), 2 * k):  # 步长为 2k
            # 反转从 i 到 i+k 的部分（如果不足 k 则到末尾）
            res[i:i+k] = reversed(res[i:i+k])
        return ''.join(res)
