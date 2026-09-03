// https://leetcode.com/problems/construct-uniform-parity-array-ii/description/?envType=daily-question&envId=2026-09-03

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_el = *min_element(nums1.begin(), nums1.end());   
        if(min_el%2==1) return true;

        for (auto it : nums1){
            if(it%2==1) return false;
        }
        return true;
    }
};
