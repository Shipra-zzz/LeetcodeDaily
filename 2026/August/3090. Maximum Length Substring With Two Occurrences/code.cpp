// https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/description/?envType=daily-question&envId=2026-08-14

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i =0, j=0, n=s.size();
        unordered_map<int,int> mp;
        int ans =0;

        while(j<n){
            mp[s[j]]++;
            while(mp[s[j]]>2 && i<n){
                mp[s[i]]--;
                i++;     
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
