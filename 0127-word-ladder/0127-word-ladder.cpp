class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,int> mp,vis;

        for(auto &it: wordList){
            mp[it]++;
            vis[it] = -1;
        }

        if(!mp[endWord]) return 0;

        queue<string> q;
        q.push(beginWord);

        int cnt = 0;

        while(!q.empty()){
            int n = q.size();

            while(n--){
                string curr = q.front();
                q.pop();

                if(curr == endWord)
                    return cnt + 1;

                string temp = curr;
                int sz = curr.size();

                for(int i = 0; i < sz; i++){
                    for(int j = 0; j < 26; j++){

                        temp[i] = 'a' + j;

                        if(mp[temp] && vis[temp] == -1){
                            vis[temp] = 1;
                            q.push(temp);
                        }
                    }

                    temp[i] = curr[i];
                }
            }

            cnt++;
        }

        return 0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna