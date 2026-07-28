class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        cnt = [0] * 26
        for ch in s:
            cnt[ord(ch) - 97] += 1   
        for ch in t:
            cnt[ord(ch) - 97] -= 1
        return all(c == 0 for c in cnt)   