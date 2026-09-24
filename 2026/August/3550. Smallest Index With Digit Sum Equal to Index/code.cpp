// https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/description/?envType=daily-question&envId=2026-09-24

class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i<nums.size(); i++){
            int x = nums[i];
            int sum = 0;
            for (int t = nums[i]; t > 0; t /= 10) sum += t % 10;
            if(sum==i) return i;
        }
        return -1;
    }
};
