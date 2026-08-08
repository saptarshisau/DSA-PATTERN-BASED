class Solution {
public:
    int f(int x) {
        for(int i = 0; i < 32; i++) {
            if((x >> i) & 1)
                return i;
        }
        return -1;
    }

    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();

        int ele_xor = 0;

        // XOR all elements in the grid
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ele_xor ^= grid[i][j];
            }
        }

        // XOR with numbers from 1 to n*n
        for(int i = 1; i <= n * n; i++) {
            ele_xor ^= i;
        }

        int set_bit = f(ele_xor);

        int sec_bit1 = 0, sec_bit0 = 0;

        // Partition grid elements
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if((grid[i][j] >> set_bit) & 1)
                    sec_bit1 ^= grid[i][j];
                else
                    sec_bit0 ^= grid[i][j];
            }
        }

        // Partition numbers 1...n*n
        for(int i = 1; i <= n * n; i++) {
            if((i >> set_bit) & 1)
                sec_bit1 ^= i;
            else
                sec_bit0 ^= i;
        }

        // Determine which one is repeated
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == sec_bit0)
                    cnt++;
            }
        }

        if(cnt)
            return {sec_bit0, sec_bit1}; // {repeated, missing}
        else
            return {sec_bit1, sec_bit0};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna