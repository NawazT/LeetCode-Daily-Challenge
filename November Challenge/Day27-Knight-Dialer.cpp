// TC = O(N*4*3) -> O(N)
// SC = O(N)

class Solution {
public:
    int mod = 1000000007;

    long solve(int i, int j, int moves, long hash[][4][3]) {

        if(i < 0 || j < 0 || i >= 4 || j >= 3 || (i == 3 && j != 1)) 
        {
            return 0;
        }
        
        if(moves == 1) 
        {
            return 1;
        }

        if(hash[moves][i][j] > 0)
        {
            return hash[moves][i][j];
        }

        long ans = solve(i-1, j-2, moves-1,hash) %mod +
                   solve(i+1, j-2, moves-1,hash) %mod +
                   solve(i+1, j+2, moves-1,hash) %mod +
                   solve(i-1, j+2, moves-1,hash) %mod +
                   solve(i+2, j-1, moves-1,hash) %mod +
                   solve(i+2, j+1, moves-1,hash) %mod +
                   solve(i-2, j-1, moves-1,hash) %mod +
                   solve(i-2, j+1, moves-1,hash) %mod ;

        hash[moves][i][j] = ans;

        return ans%mod;
    }

    int knightDialer(int n) {
        //if(n == 1) return 10;

        // vector<vector<int>> numpad = {
        //                                 {1, 2, 3},
        //                                 {4, 5, 6},
        //                                 {7, 8, 9},
        //                                 {-1, 0,-1}
        //                             };

        long ans = 0;
        long hash[n+1][4][3];
        memset(hash,0,sizeof(hash));

        for(int i=0; i<4; i++)
        {
            for(int j=0; j<3; j++)
            {
                ans = (ans + solve(i,j,n,hash)) % mod;
            }
        }

        return (int)ans; 
    }
};