// TC = O(N)
// SC = O(1)

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i=0,j=0,k=0,l=0;
        int n = word1.size(), m = word2.size();

        while(i<n && j<m)
        {
            if(word1[i][k++] != word2[j][l++])
            {
                return false;
            }
            if(k >= word1[i].size())
            {
                i++;
                k=0;
            }
            if(l >= word2[j].size())
            {
                j++;
                l=0;
            }
        }
        return i == word1.size() && j == word2.size(); 
    }
};