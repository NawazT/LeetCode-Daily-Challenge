// TC = O(N*M*MlogM);

class Solution {
public:

    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;

        vector<int> countOnes(m,0);

        for(int row = 0; row < n; row++)
        {
            for(int col = 0; col < m; col++)
            {
                if(matrix[row][col] == 1) countOnes[col]+=1;
                else countOnes[col] = 0;
            }

            vector<int> height = countOnes;

            sort(height.begin(), height.end());

            for(int j=0; j<m; j++)
            {
                ans = max(height[j]*(m-j), ans);
            }

        }



        return ans;
    }
};