#include <bits/stdc++.h>
using namespace std;

// Computes the maximum consecutive 1s after flipping at most one 0
int maxConsecutiveOne(vector<int> arr, int N)
{
  //curr-> 1s afeter zero, x-> 1s before 0
    int curr = 0;
    int x = 0;
    int ret = 0;
    bool gotZero = false;

    for(int num : arr) {
        if(num == 1) {
            curr++;

            if(gotZero)
                ret = max(ret, x + 1 + curr);
            else
                ret = max(ret, curr);
        }
        else {
            gotZero = true;

            x = curr;
            curr = 0;

            ret = max(ret, x + 1);
        }
    }
  return ret;
}

int main() {
    vector<int> arr = {0,1,0,1,1};
    int N = arr.size();

    cout << maxConsecutiveOne(arr, N);
}
