class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int begin = 0, end = numbers.size()-1;
        int tmp;
        int j;
        vector<int> retVal(2, 0);
        while (begin < numbers.size() - 1) {
          tmp = target - numbers[begin];
            if (tmp > numbers[end]) {
                ++begin;
                continue;
            }
            for (j = numbers.size()-1; j>begin; --j) {
                if (numbers[j] < tmp)
                    break;
                if (numbers[j] == tmp) {
                    retVal[0] = begin + 1;
                    retVal[1] = j+1;
                    return retVal;
                }
            }
            while (numbers[begin+1] == numbers[begin] && begin+1 < numbers.size() / 2)
                begin++;
            begin++;
        } 
        
        return retVal;
    }
};