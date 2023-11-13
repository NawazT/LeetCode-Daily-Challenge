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

// Approach 2

// Sort time O(N)

// store pair of {char, count} in a vector and then build a sorted string of vowels, to pick the chars from.

// The sort functio starts ....

 auto sortV = [] (string &V) {

            pair<char, int> cnt[10] = {
                {'A',0},
                {'E',0},
                {'I',0},
                {'O',0},
                {'U',0},
                {'a',0},
                {'e',0},
                {'i',0},
                {'o',0},
                {'u',0}
            };

            for(auto &c : V)
            {
                for(int i=0;i<10;i++)
                {
                    if(cnt[i].first == c) 
                    {
                        cnt[i].second++;
                        break;
                    }
                }
            }
            string neo;
            for(auto &it : cnt)
            {
                for(int j=0;j<it.second;j++)
                {
                    neo.push_back(it.first);
                }
            }

            V = neo;
        };

        // The sort function ends....

    // Optimal Approach

    // couting sort

    class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ||
        ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')return true;

        return false;
    }
    string sortVowels(string s) {
        int freq[128]={0};

        for(int i=0;i<s.size();i++){
            if(isVowel(s[i]))freq[(int)s[i]]++;
        }

        int idx=0;
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                while(freq[idx]==0)idx++;
                s[i]=(char)idx;
                freq[idx]--;
            }
        }

        return s;
    }
};
    