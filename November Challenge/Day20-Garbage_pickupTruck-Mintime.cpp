// TC = O(N) -> for prefix sum +  O(N*3*10) -> for counting the no. of particular garbages
// SC = O(N) -> for prefix sum

// We just need to figure out two things
// 1. Last index of the house for a particular garbge
// 2. Total count of each garbage

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int tp=0, tm=0, tg=0;
        int p=0, g=0, m=0;

        int n = garbage.size(), ms = travel.size();
        vector<int> pre(n,0);

        for(int i=0; i < ms; i++) // -> O(N)
        {
            pre[i+1] = pre[i] + travel[i];
        }

        for(int i=0;i<n;i++) // -> O(N)
        {
            string curr = garbage[i];
            int p_cnt = count(curr.begin(), curr.end(), 'P'); // -> O(10)
            if(p_cnt > 0)
            {
                tp = i;
                p+=p_cnt;
            }
            int g_cnt = count(curr.begin(), curr.end(), 'G'); // -> O(10)
            if(g_cnt > 0)
            {
                tg = i;
                g+=g_cnt;
            }
            int m_cnt = count(curr.begin(), curr.end(), 'M'); // -> O(10)
            if(m_cnt > 0)
            {
                tm = i;
                m+=m_cnt;
            }
        }

        return (pre[tp] + pre[tm] + pre[tg] + m + p + g);
    }
};