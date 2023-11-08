// Key Points

// ** 1 We can always waste the time.
// ** 2 Diagonally moving is the fastest way.
// ** 3 Minimum time to reach (fx,fy)  = maximum (Horizontal dist, Vertical Dist).
// ** 4 if (given time >= minTime) We can always reach (fx,fy).

// // Edge Case
// ** if(sx,sy == fx,fy) and t==1, we can't reach fx,fy in given time.

// TC = O(1)
// SC = O(1)

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        // int y = abs(fx - sx);
        // int x = abs(fy - sy);

        if(sx == fx && sy == fy) return t != 1 ;

        //int min_time = max(y,x);

        return t >= max(abs(fx - sx), abs(fy - sy));
    }
};