//each next element has 2 options only:
// 1. Stay as equal to prev
// 2. It can be prev+1

// TC - O(NlogN)
// SC - O(1)

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();

        sort(arr.begin(), arr.end());

        if(arr[0] != 1)
        {
            arr[0] = 1;
        }

        for(int i = 0; i < n-1; i++)
        {
            if(abs(arr[i] - arr[i+1]) <= 1) continue;

            else
            {
                int s = min(arr[i], arr[i+1]);
                int ind = (s==arr[i]) ? i+1 : i;
                arr[ind] = s+1;
            }
        }

        return *max_element(arr.begin(), arr.end());

    }
};