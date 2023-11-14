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

//first and lasy has to be equal- find left and righmost ind of a char
//then all the unique char from left+1 to right-1 willl contribute to our answer
//TC = O(N)
//SC = O(1)

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> letters;
        int n = s.length();

        for(int i=0;i<n;i++)
        {
            letters.insert(s[i]);
        }

        int ans = 0;

        for(char letter : letters)
        {
            int left = -1;
            int right = -1;

            for(int i=0;i<n;i++)
            {
                if(s[i] == letter)
                {
                    if(left == -1)
                    {
                        left = i;
                    }

                    right = i;
                }
            }

            unordered_set<char> middle;

            for(int i = left+1; i<=right-1; i++)
            {
                middle.insert(s[i]);
            }

            ans+=middle.size();
        }

        return ans;
    }
};