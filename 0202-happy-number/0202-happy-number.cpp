class Solution {
public:
    bool isHappy(int n) {
        int slow = square(n);
        int fast = square(square(n));
        while (slow != fast) {
            slow = square(slow);
            fast = square(square(fast));
            if (slow == 1 || fast == 1)
                return true;
        }
        return slow==1;
    }

public:
    int square(int num) {
        int ans = 0;
        while (num > 0) {
            int rem = num % 10;
            num /= 10;
            ans += rem * rem;
        }
        return ans;
    }
};