// TC = O(N)
// SC = O(N)

// Key points - start and end elements will have only one neighour start building from either end.

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size();
        if(n == 1) return adjacentPairs[0];

        unordered_map<int,vector<int>> mpp;

        for(int i=0;i<n;i++)
        {
            mpp[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            mpp[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
        }

        //now we have the mapping of pairs

        //lets find out the start and end elements

        vector<int> v;
        for(auto &it:mpp)
        {
            if(it.second.size() == 1)
            {
                v.push_back(it.first);
            }
        }

        int st = v[0], en = v[1];

        //we have the start of an array
        //lets start building the array from left side i.e from the left side
        vector<int> arr(n+1, 0);
        arr[0] = st;
        arr[n] = en;
        int ind = 1;
        //unordered_map<int,int> vis;
        //vis[st]++;
        //vis[en]++;
        int prev = arr[ind-1];
        while(ind < n)
        {
            //we'll append our elements to the right of prev;
            int n1 = mpp[arr[ind-1]].front();
            int n2 = mpp[arr[ind-1]].back();

            if(n1 != prev)
            {
                arr[ind] = n1;
            }
            else
            {
                arr[ind] = n2;
            }
            prev = arr[ind-1];
            ind++;
        }
        return arr;
    }
};