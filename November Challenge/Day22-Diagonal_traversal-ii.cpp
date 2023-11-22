// wee need to find a way, by which we can tell 
// if an element belongs to a particular diagonal path or not
// we may observe that the sum of i+j for a particular diag remains constant
// like for diag3 = 2,0; 1,1; 0,2 ---> 2+0 = 1+1 = 0+1 = 2;
// so we can map each element with the sum of their row+column values
//            j
//    i-> 0   1,2,3
//        1   4,5,6
//        2   7,8,9
// diagName = {{i,j}}      sum(i+j)        Elements
// diag1 = 0,0             sum(i+j) = 0 -> 1 
// diag2 = 1,0; 0,1                   1 -> 4,2
// diag3 = 2,0; 1,1; 0,2              2 -> 7,5,3
// diag4 = 2,1; 1,2                   3 -> 8,6
// diag5 = 2,2                        4 -> 9
// ans = 1,4,2,7,5,3,8,6,9
// TC = O(N*M) + O(K) -> N = rows, M = columns, K = no.of diagonals
// SC = O(N)

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {

        unordered_map<int, vector<int>> mpp;

        for(int i = nums.size()-1; i>=0; i--)
        {
            for(int j=0; j<nums[i].size(); j++)
            {
                mpp[i+j].push_back(nums[i][j]);
            }
        }

        vector<int> ans;

        int diag = 0;

        while(mpp.find(diag) != mpp.end())
        {
            for(int &i : mpp[diag])
            {
                ans.push_back(i);
            }
            diag++;
        }

        return ans;
        
    }
};