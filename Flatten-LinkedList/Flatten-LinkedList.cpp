Node* MergeSorted(Node* a, Node* b)
{
     if(a==NULL)
        return b;
     else if(b==NULL)
        return a;

    Node* result=NULL;

    if(a->val<=b->val)
    {
        result=a;
        result->down=MergeSorted(a->down,b);
    }
    else
    {
        result=b;
        result->down=MergeSorted(a,b->down);
    }
    return result;

}

Node* Flatten(Node* head)
{
    if(head==NULL || head->next==NULL)
        return head;

    Node* sorted=MergeSorted(head,Flatten(head->next));

    head->next=NULL;
    return sorted;
}
