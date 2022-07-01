class Solution {
public:
    bool isHappy(int n) {
        int slow = num(n);
        int fast = num(num(n));
        while(slow!=fast){
            slow = num(slow);
            fast = num(num(fast));
        }
        return (slow==1);
    }
    
    int num(int n){
        int res = 0;
        while(n){
            res += pow(n%10, 2);
            n/=10;
        }
        return res;
    }
};

// slow sẽ chỉ đến giá trị của từng bình phưỡng những chữ số n.
// tương tự với thằng fast.
// Xét vòng lặp khi mà slow và fast mà gặp nhau thì chúng không bao giờ về đc 1
// Nếu chúng mà khác nhau thì có lúc chúng sẽ về 1. từ là slow == 1