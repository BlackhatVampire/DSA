class Solution {
public:
    bool isHappy(int n) {
        int slow = square(n);
        int fast = square(square(n));
        while (slow != fast) {
            slow = square(slow);
            fast = square(square(fast));        // becuase when a pointer becomes 1 ...the nit will remain 1 throught the whole loop ;
        }
        return slow==1;         // asking wheather slow and fast meet at 1 or not
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