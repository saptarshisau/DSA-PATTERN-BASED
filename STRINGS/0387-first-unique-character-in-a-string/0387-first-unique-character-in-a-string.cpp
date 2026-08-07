class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26] = {0};
        
        for(char &ch : s) {
            arr[ch-'a']++;
        }
        
        
        for(int i = 0; i < s.length(); i++) {
            if(arr[s[i]-'a'] == 1) {
                return i;
            }
        }
        
        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna