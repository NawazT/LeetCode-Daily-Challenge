// TC = O(NlogN)
// SC = O(1)

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int ans = 0;
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int triplets = n/3;
        int t = n-2;
        while(t >= triplets)
        {
            ans+=piles[t];
            t-=2;
        }
        return ans;
    }
};

class Solution {
public:    
    int maxCoins(vector<int>& A) {
        sort(A.begin(), A.end());
        int res = 0, n = A.size();
        for (int i = n / 3; i < n; i += 2)
            res += A[i];
        return res;
    }
};