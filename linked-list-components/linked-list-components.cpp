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
    int numComponents(ListNode* head, vector<int>& nums) {
        
        unordered_set<int> set(nums.begin(),nums.end());
        int ans=0;
       
        while(head!=NULL)
        {
             int flag=0;
            while(head!=NULL && set.find(head->val)!=set.end())
            {
                flag=1;
                head=head->next;
            }
            if(flag==0)
                head=head->next;
            ans+=flag;
        }
        return ans;
        
    }
};