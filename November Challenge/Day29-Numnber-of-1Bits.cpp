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

//Approach 2
// unsetting the right-most set bit 
// TC = O(32) ~ constanst
// SC = O(1) ~ constanst

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n > 0)
        {
            n = n & (n-1);
            ans++;
        }

        return ans;
    }
};

// Approach 3
// Using the remainder method
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n > 0)
        {
            if(n%2 == 1) ans++;
            n/=2;
        }

        return ans;
    }
};

