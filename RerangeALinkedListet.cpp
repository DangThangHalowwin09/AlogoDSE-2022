class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head) return;
        
        // Tìm điểm middle của linked list
        ListNode *fast = head, *mid = head, *prev = NULL;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            mid = mid->next;
        }
        // thì nâng mid lên 1 nấc nữa. (Nếu tổng số phần từ chẵn) 
        if (fast->next) mid = mid->next;
        
        // Đảo list chứa một nửa thứ 2
        while (mid) {
            fast = mid->next;
            mid->next = prev;
            prev = mid;
            mid = fast;
        }
        mid = prev; // gắn mid thành phần tử cuối linked list.
        
        // merge cả 2 lại với nhau
        while (head && mid) {
            fast = head->next;
            prev = mid->next;
            head->next = mid;
            mid->next = fast;
            head = fast;
            mid = prev;
        }
        // TH cơ sở
        if (head && head->next) head->next->next = NULL;
    }
};