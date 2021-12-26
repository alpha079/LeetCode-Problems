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
        if(!head)return NULL;
        Node* curr=head;
        
        unordered_map<Node*,Node*> map;
        
        while(curr!=NULL)
        {
            Node* newNode=new Node(curr->val);
            map[curr]=newNode;
            curr=curr->next;
        }
        curr=head;
        Node* clone=NULL;
        while(curr!=NULL)
        {
            clone=map[curr];
            clone->next=map[curr->next];
            clone->random=map[curr->random];
            curr=curr->next;
        }
        return map[head];
    }
};