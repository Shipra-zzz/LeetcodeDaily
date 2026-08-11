// https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/description/?envType=daily-question&envId=2026-08-11

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        set<int> st;
        for(int i:nums){
            st.insert(i);
        }
        int x=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]+1)
                break;
            x++;
        }
        int sum=0;
        for(int i=0;i<=x;i++)
            sum+=nums[i];
        
        while(true){
            if(st.find(sum)!=st.end())
                sum++;
            else 
                break;
        }
        return sum;
    }
};
