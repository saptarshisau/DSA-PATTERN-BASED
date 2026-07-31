class Solution {
public:
    bool isDigit(char ch){return ch>='0'&&ch<='9';}
    int calculate(string s) {
        int n=s.size();
        char ops='+';
        int number=0;
        stack<int> st;
        for(int i=0;i<=n;i++){
            char ch = (i==n)? '+':s[i];
            if(isDigit(ch)){
                number=number*10 + (ch-'0');
            }
            else if(ch!=' '){
                if(ops=='+'){
                    st.push(number);
                }else if(ops=='-'){
                    st.push(-number);
                }else if(ops=='*'){
                    int top=st.top();
                    st.pop();
                    st.push(top*number);
                }else{
                    int top=st.top();
                    st.pop();
                    st.push(top/number);
                }
                ops=ch;
                number=0;
            }
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna