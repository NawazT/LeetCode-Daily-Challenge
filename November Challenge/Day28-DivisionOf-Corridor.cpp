// TC = O(N) + O(N)
// SC = O(N)
// maths approach
// toatl ways  = product of (number of options for each divider)

class Solution {
public:
    int numberOfWays(string s) {
        int n = s.length();
        int totalSeats = count(s.begin(), s.end(), 'S');

        if(totalSeats % 2 != 0 || totalSeats == 0) return 0;
        
        int dividers = (totalSeats/2) - 1;

        vector<int> dividerOptions(dividers, 1); //space -> O(N)
        int sCnt = 0, j = 0;
        for(int i = 0; i < n; i++ ) // -> O(N)
        {
            //cout<<s[i]<<" first"<<endl;
            if(s[i] == 'S')
            {
                sCnt++;
            }

            if(sCnt == 2 && j < dividers)
            {
                while(s[i+1] == 'P')
                {
                    dividerOptions[j]++;
                    i++;
                }
                j++;
                sCnt = 0;
                //cout<<s[i]<<" wkb"<<endl;
            }
        }

        long ans = 1;

        for(auto &i : dividerOptions) // O(N)
        {
            ans = (ans*(long)i)%1000000007;
        }

        return (int)ans;
    }
};