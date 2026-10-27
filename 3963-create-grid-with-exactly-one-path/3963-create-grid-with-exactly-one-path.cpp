class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> s(m,string(n,'#'));
        
        for(int j=0;j<n;j++){
            s[0][j]='.';
        }
        for(int i=0;i<m;i++){
            s[i][n-1]='.';
        }
        return s;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna