// Brute force
        // Extract the elements of range nums[l[i]], nums[r[i]]
        // sort them
        // Check diff of every pair of consecutive elements
        // TC = O(M* (N + NlogN + N))

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    
        vector<bool> ans;
        int m = l.size();
        int n = nums.size();

        for(int i=0; i<m; i++) //-> O(M)
        {
            int lt = l[i];
            int rt = r[i];

            if((rt - lt) == 1) {ans.push_back(true);continue;}
            else{
                vector<int> temp;
                copy(nums.begin() + lt, nums.begin() + (rt+1), back_inserter(temp)); //-> O(N)

                sort(temp.begin(),temp.end()); // ->O(NlogN)

                int diff = temp[1] - temp[0];
                int flag = true;
                for(int j=2;j<temp.size();j++) // -> O(N)
                {
                    cout<< temp[j]<<" "<<temp.size();
                    if((temp[j] - temp[j-1]) != diff)
                    {
                        flag = false;
                        break;
                    }
                }
                ans.push_back(flag);
                temp.clear();
                temp.shrink_to_fit();
            }
        }
        return ans;
    }
};

