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

// Optimal Approach

// Change each char of the given string such that our
// ans differ from every given string
// alter 0th char of 0th string and append to ans
// alter 1st char of 1st string and append to ans
// alter 2nd char of 2nd string and append to ans
// alter 3rd char of 3rd string and append to ans ...... and so on

// So finally our ans string will differ from each and every given string and will be of n length.

// TC = O(N)
// sc = O(1)

class Solution {
public: 
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        
        string ans = "";

        for(int i=0; i < n ; i++)
        {
            if(nums[i][i] == '0')
            {
                ans+="1";
            }
            else ans+="0";
        }

        return ans;
    }
};



