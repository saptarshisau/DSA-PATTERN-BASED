class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        set<string> ans;

        int curr = 0, ini_r = -1;

        // Find kth 1
        for(int i = 0; i < n; i++){
            if(s[i] == '1') curr++;

            if(curr == k){
                ini_r = i;
                break;
            }
        }

        if(ini_r == -1) return "";

        int l = 0;

        // Remove leading zeroes from first window
        while(l <= ini_r && s[l] == '0'){
            l++;
        }

        int mini = ini_r - l + 1;

        ans.insert(
            string(s.begin() + l, s.begin() + ini_r + 1)
        );

        // IMPORTANT: start AFTER ini_r
        int r = ini_r + 1;

        while(r < n){

            if(s[r] == '1'){

                // Remove the oldest 1
                l++;

                // Skip zeroes until next 1
                while(l <= r && s[l] != '1'){
                    l++;
                }

                int len = r - l + 1;

                mini = min(mini, len);

                ans.insert(
                    string(s.begin() + l, s.begin() + r + 1)
                );
            }

            r++;
        }

        // Remove strings that aren't minimum length
        for(auto it = ans.begin(); it != ans.end(); ){
            if(it->size() != mini){
                it = ans.erase(it);
            }
            else{
                it++;
            }
        }

        // Lexicographically SMALLEST
        return *ans.begin();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna