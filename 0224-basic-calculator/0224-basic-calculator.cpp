class Solution {
public:
    bool isDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }

    int calculate(string s) {
        stack<int> st;
        int result = 0, sign = 1;
        long long number = 0;

        for (char ch : s) {
            if (isDigit(ch)) {
                number = number * 10 + (ch - '0');
            }
            else if (ch == '+') {
                result += sign * number;
                number = 0;
                sign = 1;
            }
            else if (ch == '-') {
                result += sign * number;
                number = 0;
                sign = -1;
            }
            else if (ch == '(') {
                st.push(result);
                st.push(sign);

                result = 0;
                sign = 1;
            }
            else if (ch == ')') {
                result += sign * number;
                number = 0;

                result *= st.top();
                st.pop();

                result += st.top();
                st.pop();
            }
        }

        result += sign * number;
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna