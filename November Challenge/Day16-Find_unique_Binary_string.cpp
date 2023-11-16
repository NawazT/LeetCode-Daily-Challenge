// Key Points
// Prepare set of all decimal values given
// running a loop and check for each number
// TC = O(N^2)
// SC = O(N)

class Solution {
public:
    // int helper(string &s) {
    //     int dec = 0;
    //     int base = 1;
    //     int n = s.length();

    //     for(int i = n-1; i>=0; i--)
    //     {
    //         if(s[i] == '1')
    //         {
    //             dec+=base;
    //         }
    //         base*=2;
    //     }
    //     return dec;
    // }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> s;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            s.insert(stoi(nums[i], 0, 2));
        }

        for(int i=0;i<= pow(2,n)-1; i++)
        {
            if(s.find(i) == s.end())
            {
                string temp = bitset<16>(i).to_string();
                return temp.substr(16-n, n);
            }
        }
        return "-1";
    }
};

// Slight Optimization
// If the loop goes from 0 to n, there is atleast 1 one number which will not be found in our set cause there is only n-1 number of n length binary 

for(int i=0; i <= n ; i++)
        {
            if(s.find(i) == s.end())
            {
                string temp = bitset<16>(i).to_string();
                return temp.substr(16-n, n);
            }
        }



        