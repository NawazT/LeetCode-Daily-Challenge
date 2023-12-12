// TC = O(NlogN)
// SC = O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i : nums)
        {
            pq.push(i);
            if(pq.size() > 2) 
            {
                pq.pop();
            }
        }

        int i = pq.top(); pq.pop();
        int j = pq.top(); pq.pop();

        long ans = (long(i) - 1) * ((long)j -1);

        return (int)ans;

    }
};