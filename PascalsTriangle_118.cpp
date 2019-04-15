class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> retVal;
        if (!numRows)
            return retVal;
        int i, j;
        for (i = 0; i < numRows; ++i) 
            retVal.push_back(vector<int>(i+1));
        retVal[0][0] = 1;
        if (numRows == 1)
            return retVal;
        retVal[1][0] = 1;
        retVal[1][1] = 1;
        for (i = 2; i < numRows; ++i) {
            // 先填首和尾
            retVal[i][0] = 1;
            retVal[i][i] = 1;
            // 遍历上一行
            for (j = 1; j < i; ++j) 
                retVal[i][j] = retVal[i-1][j] + retVal[i-1][j-1];   
        }
        return retVal;
    }
};