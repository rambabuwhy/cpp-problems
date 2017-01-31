bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    
    if(head==NULL)
    {
        return false;
    }
    Node * current= head;
    Node *p1=current;
    Node *p2= current->next->next;
    while(p2 && p2->next)
    {
        
        if(p1 == p2){
            return true;
        }
        p1=p1->next;
        p2= p2->next->next;
    }
    
    return false;
}