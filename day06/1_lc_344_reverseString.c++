class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        char temp;
        int left = 0, right = s.size() - 1;
        for (int i = 0; i < s.size() / 2; i++)
        {
            temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            right--;
            left++;
        }
    }
};