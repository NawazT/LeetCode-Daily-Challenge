// Key  Notes
// Attempting to makw the num zero in left to right direction
// cause left setbits are the most significant and will take minimum steps overall
// If only 1 setbit ..for ex n = 1000
// the only way to make it zero is to set the 4th nit to zero
// and to do that we need 1 on 3rd too, cause only then we can change
// so, n = 1100, suppose it took x-steps to make the 1(000) -> 1(100)
// 1 step to 1100 -> 0100, now 100 -> 000 = x steps cause it took same for 100 -> 000;
// 1000 --(in x steps)--> 1100 -- (in 1 step) --> 0100 -- (in x steps) --> 000;
// so total = 2 * x + 1; what is x ? steps if 2nd bit was set... ----->(i)
// originally 3rd bit was set. so, if we knew the steps to make n 0 for (i-1)th set bit we can compue for ith set bit also..
// what if multiple set bits in n?
// like n = 1100
// we saw above 1000 -> 1100 -> 0000, so we know 1000 -> 0000..
// so F(1100 -> 0000) = F(1000 -> 0000) - F(1000 -> 1000) ----->(ii)
// if  n = 110010 -> 5th, 4th, and 2nd bit is set
//so we know the steps if only the 5th bit is set, from our formula above
// F(110010) = F(100000) - F(10010)
// where F(10010) means the no. of steps to convert 10010 to 0
// now F(10010)  has 4th and 2nd bit set.. if only 4th bit was set then... steps will be F(4) or F(10000) from our first formula
// now from 2nd fromula F(10010) = F(4) - F(0010)...now 0010 has only 2nd bit set which can be easily calculated by our formlua..
// F(110010) = F(5) - (F(4) - F(2))
// => F(n) = F(5) - F(4) + F(2) --> we can see a pattern..
// we need to know the set bits first and have and array of steps where arr[i] = steps if only ith bit was set

// TC = constant
// SC also constant

class Solution {
public:
    int minimumOneBitOperations(int n) {
        int i = 0;

        vector<int> setBits;

        while(i<32)
        {
            if(((n >> i) & 1) == 1) setBits.push_back(i);
            
            i++;
        }
        //reverse(setBits.begin(), setBits.end());

        vector<long long> F(31,0);
        F[0] = (long long)1;
        for(int i=1; i<31; i++)
        {
            F[i] = 2*F[i-1] + 1;
        }

        int sign = 1;
        int ans = 0;

        for(int i=setBits.size()-1; i>=0; i--)
        {
            ans += (sign*(int)F[setBits[i]]);
            sign*=(-1);
        }
        
        return ans;
    }
};