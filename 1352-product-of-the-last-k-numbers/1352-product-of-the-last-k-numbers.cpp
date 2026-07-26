class ProductOfNumbers {
public:
vector<int> a,pref;
int pref_pro,las_zero;
    ProductOfNumbers() {
        pref_pro=1;
        las_zero=-1;
        pref.push_back(1);
    }
    
    void add(int num) {
        a.push_back(num);
        if(!num){
            las_zero=a.size()-1;
            pref_pro=1;
            pref.push_back(1);
            return;
        }
        pref_pro*=num;
        pref.push_back(pref_pro);
    }
    
    int getProduct(int k) {
        int n=a.size();
        if(n-k<=las_zero) return 0;
        return pref_pro/pref[n-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna