// https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/description/?envType=daily-question&envId=2026-08-15

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans = 0, n= nums.size();
        bool allZero=true;
        for(auto it:nums){
            ans = ans^it;
            if(it!=0)   allZero=false;
        }
        if(allZero) return 0;
        if(ans==0)
            return n-1;
        else
            return n;
    }
};
