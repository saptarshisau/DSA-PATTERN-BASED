class Solution {
public:
    bool isDigit(char ch){return ch>='0'&&ch<='9';}
    int calculate(string s) {
        int n=s.size();
        int number=0,res=0;
        vector<int> num;
        vector<char> ops;
        for(int i=0;i<n;i++){
            if(s[i]==' ')continue;
            if(isDigit(s[i])) {
                number=number*10 + (s[i]-'0');
            }
            else{
                num.push_back(number);
                number=0;
                ops.push_back(s[i]);
            }
        }
        num.push_back(number);
        for(int i=0;i<ops.size();){
            if(ops[i]=='*'){
                num[i]=num[i]*num[i+1];
                num.erase(num.begin()+i+1);
                ops.erase(ops.begin()+i);
            }else if(ops[i]=='/'){
                num[i]=num[i]/num[i+1];
                num.erase(num.begin()+i+1);
                ops.erase(ops.begin()+i);
            }else {
                i++;
            }
        }
        res=num[0];
        for(int i=0;i<ops.size();i++){
            if(ops[i]=='+'){
                res+=num[i+1];
            }else if(ops[i]=='-'){
                res=res-num[i+1];
            }
        }
        return res;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna