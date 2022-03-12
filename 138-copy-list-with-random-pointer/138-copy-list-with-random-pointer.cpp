/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //Space optimise Version
        
        Node *curr=head;
        
        while(curr!=NULL)
        {
            Node* temp=curr->next;
            Node* dummy=new Node(curr->val);
            curr->next=dummy;
            dummy->next=temp;
            curr=temp;
        }
        
        //Now copy the Random Pointers of Original Node
        curr=head;
        
        while(curr!=NULL)
        {
            if(curr->random)
            {
                curr->next->random=curr->random->next;
            }
            curr=curr->next->next;
        }
        
        //Now Detach the next Pointers with the Deep copy Node
        Node* copyHead= new Node(0);
        Node* itr=copyHead;
        curr=head;
        
        while(curr!=NULL)
        {
            itr->next=curr->next;
           curr->next=curr->next->next;
            curr=curr->next;
            itr=itr->next;
            
            
        }
        return copyHead->next;
        
    }
};