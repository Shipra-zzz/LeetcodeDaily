// https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/description/?envType=daily-question&envId=2026-08-22

class Solution {
public:
    bool checkDivisibility(int n) {
        int sum =0, prod=1, tmp=n;
        while(tmp){
            int digit = tmp%10;
            sum+=digit;
            prod*=digit;
            tmp/=10;
        }

        return n%(sum+prod)==0;
    }
};
