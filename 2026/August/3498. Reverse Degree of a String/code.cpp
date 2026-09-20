// https://leetcode.com/problems/reverse-degree-of-a-string/description/?envType=daily-question&envId=2026-09-20

class Solution {
public:
    int reverseDegree(string s) {
        int res =0;
        for(int i=0; i<s.size(); i++){
            int itm = 26-(s[i]-'a');
            res+=(itm*(i+1));
        }
        return res;
    }
};
