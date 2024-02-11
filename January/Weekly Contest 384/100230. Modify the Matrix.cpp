class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int numCol = matrix[0].size(); 
        vector<int> maxValues(numCol, INT_MIN);

        
        for (int col = 0; col < numCol; col++) {
            for (int row = 0; row < matrix.size(); row++) {
                maxValues[col] = max(maxValues[col], matrix[row][col]);
            }
        }

       
        for (int col = 0; col < numCol; col++) {
            for (int row = 0; row < matrix.size(); row++) {
                if (matrix[row][col] == -1) {
                    matrix[row][col] = maxValues[col];
                }
            }
        }

        return matrix;
    }
};
