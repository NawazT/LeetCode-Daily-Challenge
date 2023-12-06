// TC = O(N)
// SC = O(1)

class Solution {
public:
    int totalMoney(int n) {
        int ans=0;
        int initial = 1;
        int prevInitial = 1;
        int days = 0;

        while(n-- > 0)
        {
            ans+=initial;
            initial+=1;
            days++;

            if(days == 7)
            {
                initial = prevInitial + 1;
                prevInitial++;
                days=0;
            }
        }

        return ans;
    }
};