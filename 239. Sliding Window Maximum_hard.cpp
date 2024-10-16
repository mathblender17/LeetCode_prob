class Solution {
    /**
    A double ended queue(deque) is used  to keep the TC O(n) else it beomes O(n^2)
    A monotonic decreasing queue is to be maintained
    - if the element about to be inserted is greater than the element in the back pop_back till existing element is smaller than the element before it
    We only use the leftmost element from the deque as it is the highest
    we start taking the leftmost element after the window is filled atleast once (j+1>=k)
    **/
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0;int j=0;
        deque<int> dq;
        vector<int>res;

        while(j<nums.size()){
            while(!dq.empty() && nums[dq.back()]<nums[j]){
                dq.pop_back();
            }
            dq.push_back(j);
            //to maintain the the sliding  window - if a element is left from the older window it is removed - as i is the staring index for window
            if(i>dq.front()){
                dq.pop_front();
            }
            if(j+1>=k){
                res.push_back(nums[dq.front()]);
                i++;
            }
            j++;
        }
        return res;
    }
};
