// TC - O(NlogN)
// SC - O(N)

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = speed.size();
        vector<double> timeLeft(n,0);

        for(int i=0; i<n; i++)
        {
            timeLeft[i] = (double)dist[i]/(double)speed[i];
        }

        sort(timeLeft.begin(), timeLeft.end());
        int minus = 1;
        int ans = 0;

        for(int i=0;i<n;i++)
        {
            if(timeLeft[i] <= 0)
            {
                break;
            }

            timeLeft[i] = -1;
            ans++;

            if(i < n-1)
            {
                timeLeft[i+1]-=(double)minus;
            }

            minus++;
        }

        return ans==0 ?  1 : ans;
    }
};

