// https://leetcode.com/problems/smallest-stable-index-i/description/?envType=daily-question&envId=2026-09-04

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxi(n), mini(n);
        maxi[0]=nums[0];
        mini[n-1]=nums[n-1];  
        for(int i = 1; i<n; i++){
            if(nums[i]>maxi[i-1]){
                maxi[i]=nums[i];
            }
            else{
                maxi[i]=maxi[i-1];
            }
            if(nums[n-i-1]<mini[n-i])   mini[n-i-1]=nums[n-i-1];
            else mini[n-i-1]=mini[n-i];
        }

        for(int i=0; i<n; i++){
            if(maxi[i]-mini[i] <=k) return i; 
        }
    
        return -1;
    }
};
