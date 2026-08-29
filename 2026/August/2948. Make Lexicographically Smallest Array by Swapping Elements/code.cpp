// https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/description/?envType=daily-question&envId=2026-08-29

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> vec = nums;
        sort(vec.begin(), vec.end());

        int groupNum = 0;
        unordered_map <int, int> numToGroup;
        numToGroup[vec[0]]=0;

        unordered_map<int, list<int>> groupToList;
        groupToList[0].push_back(vec[0]);

        for(int i =1; i<n; i++){
            if(vec[i]-vec[i-1]>limit){
                groupNum+=1;
            }
            numToGroup[vec[i]]=groupNum;
            groupToList[groupNum].push_back(vec[i]);
        }

        vector<int> ans(n);

        for(int i =0; i<n; i++){
            int num = nums[i];
            int group = numToGroup[num];
            ans[i]=*(groupToList[group].begin());
            groupToList[group].pop_front();
        }

        return ans;
    }
};
