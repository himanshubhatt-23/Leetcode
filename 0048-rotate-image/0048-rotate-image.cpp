class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int edgeLength = matrix.size();

        int top = 0;
        int bottom = edgeLength - 1;

        while (top < bottom) {
            for (int col = 0; col < edgeLength; col++) {
                int temp = matrix[top][col];
                matrix[top][col] = matrix[bottom][col];
                matrix[bottom][col] = temp;
            }
            top++;
            bottom--;
        }

        for (int row = 0; row < edgeLength; row++) {
            for (int col = row + 1; col < edgeLength; col++) {
                int temp = matrix[row][col];
                matrix[row][col] = matrix[col][row];
                matrix[col][row] = temp;
            }
        }        
    }
};


//class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int row = matrix.size();
//         int col = matrix[0].size();

//         for ( int i = 0 ; i < row ; i++){
//             for ( int j = i+1; j< col ; j++){
//                 swap(matrix[i][j], matrix[j][i]);
//             }
//         }

//         for (int k = 0 ; k < row ; k++){
//             reverse(matrix[k].begin(), matrix[k].end());
//         }
//     }
// };