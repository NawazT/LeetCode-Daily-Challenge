// TC = O(N^2 * log(nums[i]))
// SC = O(1)
class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int revI = rev(nums[i]);
                int revJ = rev(nums[j]);

                if(nums[i] + revJ == nums[j] + revI)
                {
                    cout<<revI<<" "<<revJ<<endl;
                    ans++;
                } 
            }
        }
        return ans;
    }

    int rev(int a)
    {
        int ans = 0;
        while(a>0)
        {
            if(a>=10)
            {
                ans+=(a%10);
                a/=10;
                ans*=10;
            }
            else
            {
                ans+=a;
                a/=10;
            }
        }
        return ans;
    }
};

// TC = O(N *log(nums[i])) + O(N)
// SC = O(2*N)

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        long ans = 0;
        int n = nums.size();
        vector<int> diff(n,0);
        
        for(int i=0;i<n;i++)
        {
            int revI = rev(nums[i]);
            diff[i] = nums[i]-revI;
            cout<<diff[i]<<" ";
        }

        unordered_map<int,int> mpp;
        int j=n-1;
        while(j>=0)
        {
            if(mpp.find(diff[j]) != mpp.end())
            {
                ans+=(long)mpp[diff[j]];
                ans%=1000000007;
            }
            mpp[diff[j]]++;
            j--;
        }

        return (int)ans%1000000007;
    }

    int rev(int a)
    {
        int ans = 0;
        while(a>0)
        {
            if(a>=10)
            {
                ans+=(a%10);
                a/=10;
                ans*=10;
            }
            else
            {
                ans+=a;
                a/=10;
            }
        }
        return ans;
    }
};

// TC = O(N*log(nums[i]))
// SC = O(N)

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        long ans = 0;
        int n = nums.size();
        //vector<int> diff(n,0);
        unordered_map<int,int> mpp;
        // int j=n-1;
        for(int i=n-1;i>=0;i--)
        {
            int revI = rev(nums[i]);
            // diff[i] = nums[i]-revI;
            // cout<<diff[i]<<" ";
            int diff = nums[i] - revI;

            if(mpp.find(diff) != mpp.end())
            {
                ans+=(long)mpp[diff];
                ans%=1000000007;
            }
            mpp[diff]++;
        }

        
        // while(j>=0)
        // {
            // if(mpp.find(diff[j]) != mpp.end())
            // {
            //     ans+=(long)mpp[diff[j]];
            //     ans%=1000000007;
            // }
            // mpp[diff[j]]++;
        //     j--;
        // }

        return (int)ans%1000000007;
    }

    int rev(int a)
    {
        int ans = 0;
        while(a>0)
        {
            if(a>=10)
            {
                ans+=(a%10);
                a/=10;
                ans*=10;
            }
            else
            {
                ans+=a;
                a/=10;
            }
        }
        return ans;
    }
};

