// Key Points
// if at any point l[i] = r[i] --> no change in total timing
// it is as if they didn't collided at all
// Ans = max(slowest_right, slowest_left)
// TC = O(N) + O(M)
// N = size of left, M = size of right

// CODE

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int slowest_left = INT_MIN, slowest_right = INT_MAX;
        int l = left.size(), r = right.size();

        for(int i=0; i < max(l,r); i++)
        {
            if(i<l && i<r)
            {
                slowest_left = max(left[i], slowest_left);
                slowest_right = min(right[i], slowest_right);
            }
            else if(i<l)
            {
                slowest_left = max(left[i], slowest_left);
            }
            else if(i<r)
            {
                slowest_right = min(right[i], slowest_right);
            }
        }

        return max(n-slowest_right, slowest_left);
    }
};