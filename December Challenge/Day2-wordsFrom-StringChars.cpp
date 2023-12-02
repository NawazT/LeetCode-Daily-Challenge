// Approach 1
// TC = O(str.length() * words.length())
// SC = O(26)

class Solution {
public:
    bool isGood(string str, vector<int> freq) {
        for(char &c : str) 
        {
            if(freq[c-'a'] <= 0)
            {
                return false;
            }
            else freq[c-'a']--;
        }
        return true;
    }

    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;

        vector<int> freq(26,0);

        for(char &c : chars)
        {
            freq[c-'a']++;
        }

        for(int i=0; i<words.size(); i++)
        {
            string curr = words[i];

            if(isGood(curr, freq))
            {
                ans+=curr.length();
            }
        }
        return ans;
    }
};