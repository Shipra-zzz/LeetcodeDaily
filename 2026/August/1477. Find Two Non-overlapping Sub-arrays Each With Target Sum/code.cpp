// https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/description/?envType=daily-question&envId=2026-09-17

constexpr int N=1e5, INF=1e9;
int lens[N];
class Solution {
public:
    static int minSumOfLengths(vector<int>& arr, int target) {
        const int n=arr.size();
        int prv=INF, ans=INF, sum=0;
        for(int l=0, r=0; r<n; r++){
            sum+=arr[r];
            for(; sum>target; l++)
                sum-=arr[l];
            lens[r]=prv;
            if (sum==target){
                int len=r-l+1;
                if (l>0) 
                    ans=min(ans, len+lens[l-1]);
                lens[r]=min(lens[r], len);
            }
            prv=lens[r];
        }
        return ans>=INF?-1:ans;

    }
};
