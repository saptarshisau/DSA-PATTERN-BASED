class Solution {
public:
    void f(stack<int>& s, int ind, int n) {
        if (ind == n / 2) {
            s.pop();
            return;
        }

        int x = s.top();
        s.pop();

        f(s, ind + 1, n);

        s.push(x);
    }

    void deleteMid(stack<int>& s) {
        int n = s.size();
        f(s, 0, n);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna