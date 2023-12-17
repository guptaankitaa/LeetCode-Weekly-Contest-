class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        
    int n = grid.size();
        unordered_set<int> seen;
        unordered_set<int> missing;
        
        int repeating = 0;
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                int num = grid[i][j];
                
                //Check for repeating numbers
                if(seen.count(num)){
                    repeating = num;
                } else{
                    seen.insert(num);
                }
                
                //Populates the missing number set
                if(num <= n*n){
                    missing.insert(num);
                }
            }
        }
        //find the missing number
        
        for(int i=1; i <= n*n; ++i){
            if(!missing.count(i) && seen.count(i) == 0){
                return {repeating, i};
            }
        }
        return {repeating,0};
    }
};
