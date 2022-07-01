class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head, *prev, *temp;
        while (fast && fast->next){
            slow = slow->next, fast = fast->next->next;
        }
        // đưa con trỏ slow về vị trí chính giữa linked list.
        
        //bắt đầu việc đảo nửa sau linked list.
        prev = slow,
        slow = slow->next,
        prev->next = NULL;
        
        while (slow){
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        // hoàn thành việc reverse nửa sau của linked list
        
        fast = head, slow = prev;
        // gán fast là đầu nửa trái, slow là đầu nửa phải.
        // kiểm tra giá trị từng con trỏ xem giống nhau k.
        
        while (slow)
            if (fast->val != slow->val) 
                return false;
            else fast = fast->next, slow = slow->next;
        
        return true;
    }
};