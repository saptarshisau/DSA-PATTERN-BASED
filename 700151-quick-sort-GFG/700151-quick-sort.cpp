class Solution {
public:
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[low];

        int l = low;
        int r = high;

        while(l < r) {

            while(l <= high && arr[l] <= pivot) {
                l++;
            }

            while(r >= low && arr[r] > pivot) {
                r--;
            }

            if(l < r) {
                swap(arr[l], arr[r]);
            }
        }

        swap(arr[low], arr[r]);

        return r;
    }

    void quickSort(vector<int>& arr, int low, int high) {
        if(low >= high)
            return;

        int pInd = partition(arr, low, high);

        quickSort(arr, low, pInd - 1);
        quickSort(arr, pInd + 1, high);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna