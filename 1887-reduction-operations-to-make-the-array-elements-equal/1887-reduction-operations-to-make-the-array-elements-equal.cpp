class Solution {
public:
    int reductionOperations(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(), arr.end());
        int steps = 0;

        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] != arr[i + 1]) {
                steps += (n - 1 - i);
            }
        }

        return steps;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna