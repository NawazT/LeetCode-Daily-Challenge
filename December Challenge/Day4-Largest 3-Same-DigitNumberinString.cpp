// TC = O(N)
// SC = O(1)

class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int digit = -1;

        for(int i=0;i<num.length()-2;i++)
        {
            if(num[i] == num[i+1] && num[i] == num[i+2])
            { //good integer
                if(num[i] - '0' > digit)
                {
                    digit = num[i] - '0';
                    ans = num.substr(i,3);
                } 
            }
        }
        return ans;
    }
};
