class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int res[26] = {0};
        for (int i = 0; i < s.size(); i++)
            res[s[i] - 'a']++;
        for (int j = 0; j < t.size(); j++)
            res[t[j] - 'a']--;
        for (int k = 0; k < 26; k++)
            if (res[k])
                return false;
        return true;
    }
};