// https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/?envType=daily-question&envId=2026-08-12

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i=0, j=0, n=nums.size();
        unordered_map<int,int> mp;
        int ans = 0;

        while(j<n){
            mp[nums[j]]++;
            while(mp[nums[j]]>k && i<n){
                mp[nums[i]]--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};
