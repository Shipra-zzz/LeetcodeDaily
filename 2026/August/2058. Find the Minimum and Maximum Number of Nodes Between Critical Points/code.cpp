// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/?envType=daily-question&envId=2026-08-31

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        ListNode* cur = head->next;
        ListNode* prev = head;
        ListNode* next = cur->next;
        int pos =1;
        int fcritical =-1;
        int lcritical=-1;
        int pcritical=-1;

        int min_dist = INT_MAX;
        int max_dist = INT_MIN;

        while(next){
            if((cur->val>prev->val && cur->val>next->val) || (cur->val<prev->val && cur->val <next->val)){
                if(fcritical==-1)   fcritical=pos;
                else 
                {
                    min_dist = min(min_dist, pos - pcritical);
                }
                pcritical = pos;
                lcritical = pos;
            }
            pos++;
            prev = cur; 
            cur=next; 
            next = next->next;
        }
        if(fcritical==lcritical)    return {-1,-1};
        else    return {min_dist, lcritical-fcritical};
    }
};
