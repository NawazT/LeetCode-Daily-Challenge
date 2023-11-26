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

// TC = O(N*M);

class Solution {
public:

    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;

        vector<pair<int,int>> prevHeights;

        for(int row = 0; row < n; row++)
        {
            vector<pair<int,int>> currHeights;
            vector<bool> seen(m,false);

            for(auto [height,col] : prevHeights)
            {
                if(matrix[row][col] == 1) 
                {
                    currHeights.push_back({height+1, col}); 
                    seen[col] = true;
                }
            }

            for(int j=0;j<m;j++)
            {
                if(!seen[j] && matrix[row][j] == 1)
                {
                    currHeights.push_back({1,j});
                } 
            }

            for(int i=0;i<currHeights.size(); i++)
            {
                int h = currHeights[i].first;
                int b = i+1;

                ans = max(ans, h*b);
            }

            prevHeights = currHeights;

        }



        return ans;
    }
};