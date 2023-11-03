//Approach 1 
//

// Intuition 🚀
// The problem is to build an array target using stack operations. To do this, we can start with an empty stack and iterate through the target array. For each element in the target array, we need to determine whether we should push or pop to match the element in target. The intuition is that if the current element in target does not match the current element we want to push (denoted by the current variable), we can push and pop until they match, and then push the current element. We repeat this process for all elements in the target array.

// Approach 🚀
// Initialize an empty list result to store the stack operations.
// Initialize a variable current to 1. This variable represents the current number that we want to push onto the stack.
// Iterate through the target array.
// For each element in the target array, compare it with the current variable:
// If the current element in target is greater than the current variable, it means we need to push and pop until they match:
// While the current is less than the current element in target, push the current number onto the stack and generate a "Push" operation, then immediately pop to match the current element. Increment the current variable.
// If the current element in target matches the current variable, simply push the current element onto the stack and increment the current variable.
// Continue this process for all elements in the target array.
// Return the result list, which contains the stack operations needed to build the target array.
// The approach essentially simulates the stack operations required to match the elements in the target array and builds the result list accordingly. The "Push" and "Pop" operations are generated based on the comparison between the current element in target and the current variable. This approach is simple and straightforward, but it may not be the most efficient, as it involves multiple "Push" and "Pop" operations in some cases.

// ✒️Code

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int i = 1;

        for(int j=0; j<target.size(); j++)
        {
            if(i == target[j])
            {
                ans.push_back("Push");
                i++;
            }
            else
            {
                while( i != target[j])
                {
                    ans.push_back("Push");
                    ans.push_back("Pop");
                    i++;
                }
                ans.push_back("Push");
                i++; 
            }
        }
        return ans;
    }
};