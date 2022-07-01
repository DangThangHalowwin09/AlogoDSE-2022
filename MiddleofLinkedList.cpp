ListNode* middleNode(ListNode* head) {

    ListNode* slow=head;
    ListNode* fast=head;
    
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;               //increment slow by 1
        fast=(fast->next)->next;     //increment fast by 2
    }
    
    return slow; 
}

// Khi thoát khỏi điều kiện vòng while thì cũng chính là lúc slow chạm vào middle of LinkedList