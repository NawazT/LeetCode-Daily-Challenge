//Approach 1
// Checking each bit by using the right shift opeartion
// TC = O(32)
// SC = O(1)

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int i = 0;
        int ans = 0;
        while(i < 32)
        {
            if(((n>>i) & 1) == 1) ans++;
            i++;
        }

        return ans;
    }
};


