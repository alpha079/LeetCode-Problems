class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        
        while(l1!=NULL && l2!=NULL)
        {
            if(l1->val <= l2->val){
            tail->next = l1;
            tail = l1;
            l1 = l1->next;
          }
        else{
            
            tail->next = l2;
            tail = l2;
            l2 = l2->next;
            
           } 
            
        }
     
        if(l1!=NULL){
            tail->next = l1;
        }
        if(l2!=NULL){
            tail->next = l2;
        }
        
        return dummy->next;
    }
    
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==1){return lists[0];}
        if(lists.size()==0){return NULL;}
        
        
       ListNode* newlist =  mergeTwoLists(lists[0],lists[1]);
        
    
       for(int i=2;i<lists.size();i++){
           newlist = mergeTwoLists(newlist,lists[i]);
       } 
        
        return newlist;
    }
};