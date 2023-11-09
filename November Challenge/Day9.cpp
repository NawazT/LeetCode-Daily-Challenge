// Key point
// l length homogenous string will have total l(l+1)/2, homogenous strings


// TC - O(n)
// SC - O(1)


class Solution {
public:
    int countHomogenous(string s) {
        int l=0, ans=0;

        for(int i=0;i<s.length();i++)
        {
            if(i > 0 && s[i] == s[i-1])
            {
                l+=1;
            }
            else
            {
                l=1;
            }
            ans+=l;
            ans%=1000000007;
        }
        return ans;
    }
};