// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/?envType=daily-question&envId=2026-09-28

class Solution {
public:
    int maxDepth(string s) {
        int cur=0, maxi=0;
        for(auto it : s){
            if(it == '('){
                cur++;
                maxi = max(maxi, cur);
            }
            if(it == ')'){
                cur--;
            }
        }
        return maxi;
    }
};
