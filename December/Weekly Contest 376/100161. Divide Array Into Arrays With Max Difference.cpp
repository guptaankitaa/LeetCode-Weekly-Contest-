class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        
   int n = nums.size();
        vector<vector<int>> result;
        
        //sort the array
        sort(nums.begin(), nums.end());
        
        //iterate through the sorted array to form groups
        for(int i=0; i <n; i+=3){
            if(i+2 < n){
                //check the differnece condition
                if(nums[i+2]- nums[i] <= k){
                    result.push_back({nums[i], nums[i+1], nums[i+2]});
                } else{
                    //if the difference condition is not met, return an empty array
                    return {};
                }
            } else{
                //if there are not enough element to form a group, return an empty array
               return {};
            }
        }
        return result;
    }
};
