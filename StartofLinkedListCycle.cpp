
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if(head == NULL)
        {
            return head;
        }
        bool cycle = false;
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                cycle = true;
                break;
            }
        }
        if(cycle)
        {
            ListNode* slow2 = head;
            while(slow != slow2)
            {
                slow = slow->next;
                slow2 = slow2->next;
            }
            return slow;
        }
        return NULL;
    }
};
// Giải thích: Giả sử k (phần tử start - phần tử head) (size ) là phần ngoài của vòng. x là loopsize
// khi slow bắt đầu vào vòng lặp. Thì fast nằm phía sau slow (x-k) vị trí
// Sau m.x - k bước thì chúng sẽ bắt nhau vì (slow đi đc mx-k bước) fast đi đc (2mx - 2k + k)
// => Điểm gặp nhau sẽ là -k hay mx-k (hay nằm ở -k vị trí so với start of loop) 
// Chứng minh được điểm gặp nhau colline point nằm phía sau start note k ví trí. => ta tìm đc start node
