class Solution {
public:
    bool judgeSquareSum(int c) {
        int j=sqrt(c);
        int i=0;
        while(i<=j){
            if((long long)i*i+j*j<c) i++;
            else if((long long)i*i+j*j>c) j--;
            else return true;
        }
        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna