class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        k%=m;
        if(k==0) return 1;

        for(int i=0; i<n;i++){
            for(int j=0; j<m;j++){
                int originalIndex;
                if(i%2==0){
                     originalIndex=(j+k)%m;
            }
            else{
                originalIndex=(j-k+m)%m;
            }
            if(mat[i][j]!=mat[i][originalIndex]){
                return false;
            }
            
            }


            
            
        }
        return true;
    }
};