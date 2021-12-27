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
    vector<int> nextLargerNodes(ListNode* head) {
        if(head==NULL)
            return {};
        vector<int> res;
        
        ListNode* curr=head;
        while(curr)
        {
            res.push_back(curr->val);
            curr=curr->next;
        }
        stack<int> s;
        s.push(0); //pushed index of 0th element
        
        for(int i=1;i<res.size();i++)
        {
            
            while(!s.empty() and res[i]>res[s.top()])
            {
                res[s.top()]=res[i];
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty())
        {
           res[s.top()]=0;
                s.pop();
        }
        return res;
        
    }
};