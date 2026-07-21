class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        start_i = 0
        start_j = 0
        i, j = 0, 0
        loop = n // 2
        mid = n // 2
        offset = 1
        res = [[0] * n for _ in range(n)]
        count = 1
        while loop > 0:
            i = start_i
            j = start_j
            for j in range(start_j, n - offset):
                res[i][j] = count 
                count += 1
            j += 1
            for i in range(start_i, n - offset):
                res[i][j] = count 
                count += 1
            i += 1
            for j in range(j, start_j, -1):
                res[i][j] = count 
                count += 1
            j -= 1
            for i in range(i, start_i, -1):
                res[i][j] = count 
                count += 1
            i -= 1
            start_i += 1
            start_j += 1
            offset += 1
            loop -= 1
        if n % 2 == 1 :
            res[mid][mid] = count
        return res