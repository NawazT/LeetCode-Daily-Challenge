//three length palindrome means first and last char must be equal...
//Brute Force Take 3 loops for each char and a map to keep check of the unique condition        
//TC - O(N^3)        
//SC - O(N)

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<string, int> mpp;
        int ans = 0;
        int n = s.length();
        for(int i = 0; i<n;i++)
        {
            string tmp{s[i]};

            for(int j=i+1; j<n;j++)
            {
                tmp.push_back(s[j]);
                for(int k=j+1; k<n;k++)
                {
                    tmp.push_back(s[k]);
                    //cout<<tmp<<" ";
                    if(s[i] == s[k])
                    {
                        if(mpp.find(tmp) == mpp.end())
                        {
                            ans++;
                            mpp[tmp]++;
                        }
                    }
                    tmp.pop_back();
                }
                tmp.pop_back();
            }
            tmp.pop_back();
        }
        return ans;
    }
};

// This will give TLE