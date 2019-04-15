class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> retVal;
        for (int i = 0; i < rowIndex+1; ++i)
            retVal.push_back(vector<int>(i+1));
        retVal[0][0] = 1;
        if (!rowIndex)
            return retVal[0];
        retVal[1][0] = 1;
        retVal[1][1] = 1;
        int i, j;
        for (i = 2; i <= rowIndex; ++i) {
            retVal[i][0] = 1;
            retVal[i][i] = 1;
            for (j = 1; j < i; ++j)
                retVal[i][j] = retVal[i-1][j-1] + retVal[i-1][j];
        }
        return retVal[rowIndex];
    }
};