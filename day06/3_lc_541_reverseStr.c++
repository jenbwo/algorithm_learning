//  第一次纯手搓代码啊！！！！！  这就是把规则编码的味道吗？

/*
class Solution {
public:
    string reverseStr(string s, int k) {
        int tail = s.size() - 2 * k;
        for(int i = 0; i < s.size(); i += 2 * k){
            if(s.size() - i < 2 * k && s.size() - i >= k)
                for(int left = i, right =  i + k - 1; left < right ; left ++ , right --)
                    swap(s[left], s[right]);
            else if(s.size() - i < k){
                for(int left = i, right = s.size() - 1; left < right; left ++, right --)
                    swap(s[left], s[right]);
            }else{
                for(int left = i , right = i + k - 1; left < right; left ++ , right --){
                    swap(s[left], s[right]);
                }
            }
        }
        return s;
    }
};

*/

//  第二次听讲解后，发现if语句可以写的很简单，但是耗时巨长

class Solution
{
public:
    string reverseStr(string s, int k)
    {
        for (int i = 0; i < s.size(); i += 2 * k)
        {
            if (i + k <= s.size())
                reverse(s.begin() + i, s.begin() + i + k);
            else
                reverse(s.begin() + i, s.begin() + s.size());
        }
        return s;
    }
};