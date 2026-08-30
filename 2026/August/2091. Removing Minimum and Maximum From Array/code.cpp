// https://leetcode.com/problems/removing-minimum-and-maximum-from-array/description/?envType=daily-question&envId=2026-08-30

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if(nums.size()==1)  return 1;

        int n =nums.size();
        int mini=0, maxi=0;

        for(int i =1; i<n;i++){
            int cur = nums[i];
            if(cur>nums[maxi])   maxi=i;
            if(cur<nums[mini])   mini=i;
        }

        int ll = max(mini,maxi) +1;

        int rr = n-min(maxi,mini);

        int lr;
        if(mini>maxi) 
            lr= n-mini + maxi+1;
        else 
            lr = n-maxi+mini+1;
        
        return min(ll, min(rr,lr));
    }
};
