// TC = O(N*M)
// SC = O(N) 

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> mpp;
        for(int i=0;i<paths.size();i++)
        {
            mpp[paths[i][0]] = paths[i][1];
        }

        for(int i=0;i<paths.size();i++)
        {
            for(auto &s : paths[i])
            {
                if(mpp.find(s) == mpp.end())
                {
                    return s;
                }
            }
        }

        return "";
    }
};