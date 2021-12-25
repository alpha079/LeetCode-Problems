class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* t = head;
        vector<ListNode*> res;
        
        //calculate number of node in list
        while(t!=NULL)
        {
            n++;
            t = t->next;
        }
        
        int nodesInEachPart = n/k , extraNodes = n%k;
        t = head;
        
        while(t!=NULL)
        {
            //include extra node in the earlier lists 
            //+1 because difference can only be 1
            int size = (extraNodes--)>0 ? nodesInEachPart+1 : nodesInEachPart;
            res.push_back(t);
            
            while(size > 1)
            {
                size--;
                t = t->next;
            }
            if(t==NULL) break;
            ListNode* temp = t->next;
            t->next=NULL;
            t = temp;
        }
        
        while(res.size()<k)
        {
            res.push_back(NULL);
        }
        
        return res;
    }
};