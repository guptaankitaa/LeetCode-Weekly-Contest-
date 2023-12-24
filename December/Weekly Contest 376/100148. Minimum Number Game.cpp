class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int> arr;
        int n = nums.size();
        
        int alice = 0;
        int bob = 0;
        
         sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i+=2){
            alice = nums[i];
            bob = nums[i+1];
            arr.push_back(bob);
            arr.push_back(alice);
        }
            return arr;
    }
   
};
