// Key Points - 
// Store all vowels.
// Sort the vowels.
// one by one put the sorted order of vowels in the original string

// TC - O(N) + O(NlogN) + O(N)
// SC - O(N)

class Solution {
public:
    bool isVowel(char ch) 
    { 
        // Make the list of vowels 
        string str = "aeiouAEIOU"; 
        return (str.find(ch) != string::npos); 
    } 

    string sortVowels(string s) {

        string ans = s;
        string v;

        for(char &c : ans)
        {
            if(isVowel(c))
            {
                v.push_back(c);
                //cout<<c<<" ";
            }
        }
        //cout<<endl;
        //cout<<"Done"<<endl;

        sort(v.begin(), v.end());

        //cout<<"Done1"<<endl;

        int i=0;
        int j=0;

        while(i < v.length())
        {
            if(isVowel(ans[j]))
            {
                //cout<<ans[j]<<" og ";
                //cout<<v[i]<<" act ";
                ans[j] = v[i];
                //cout<<ans[j]<<" ";
                j++;i++;
            }
            else j++;
        }

        return ans;
    }
};