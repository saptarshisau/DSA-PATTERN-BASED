class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        int n = start.size();
        
        map<int, int> events;
        for(int i = 0; i < n; i++) {
            int startPoint = start[i];
            int endPoint   = end[i];
            
            events[startPoint]++;
            events[endPoint]--;
        }
        
        int result = 0;
        int count = 0;
        
        for(auto& p : events){
            count   += p.second;
            result  = max(result, count);
        }
        return result;
    }
};



// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna