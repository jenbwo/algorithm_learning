//  刚开始是怎么想的？用手写找出规律，看是否存在某种规律，发现不行，不如直接用数组覆盖

/*
    i:控制着每一行的增加，从上至下
    j:控制着每一列的增加，从左至右
    loop：控制循环的次数，也就是要转多少圈
    start_i:每一圈行的起始位置
    start_j:每一圈列的起始位置
    offset：偏移量，上一圈和下一圈要偏移一个位置
    mid：如果n是奇数，那么就会有正中间一个空位
*/
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        //  while用于控制循环次数，也就是有几圈
        int i;
        int j;
        int loop = n / 2;
        int start_i = 0;
        int start_j = 0;
        int offset = 1;
        int count = 1;
        int mid = n / 2;
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        while (loop--)
        {
            i = start_i;
            j = start_j;
            //  从左往右，左闭右开的区间
            for (j = start_j; j < n - offset; j++)
                matrix[start_j][j] = count++;
            //  从上往下
            for (i = start_i; i < n - offset; i++)
                matrix[i][j] = count++;
            //  从右往左
            for (j; j > start_j; j--)
                matrix[i][j] = count++;
            //  从下往上
            for (i; i > start_i; i--)
                matrix[i][j] = count++;
            start_i++;
            start_j++;
            offset++;
        }
        //  判断是否是奇数
        if (n % 2 == 1)
            matrix[mid][mid] = count;
        return matrix;
    }
};