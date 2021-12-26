class Solution {
public:
    
    //Solution Give TLE error. Although Appraoch is Good 
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int,int> map;
        
        ListNode* curr=head;
        
        while(curr!=NULL)
        {
            int value=curr->val;
            map[value]++;
        }
        vector<int> res;
        
        for(auto it: map)
        {
            if(it.second==1)
                res.push_back(it.first);
            
        }
        if(res.size()==0)return NULL;
        sort(res.begin(),res.end());
        
        ListNode* newHead=new ListNode(-1);
        ListNode* cur=newHead;
        for(auto it: res)
        {
            
                ListNode* temp=new ListNode(it);
                cur->next=temp;
                cur=temp;
                
            
            
        }
        return newHead->next;
    }
};
