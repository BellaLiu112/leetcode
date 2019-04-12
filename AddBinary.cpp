#include <string>

class Solution {
public:
    string addBinary(string a, string b) {
        int a_cur = a.size()-1, b_cur = b.size()-1;
        string str;
        int carry = 0;
        while(a_cur > -1 && b_cur > -1) {
            if (a[a_cur] == '0' && b[b_cur] == '0') {
                if (carry) {
                    str.push_back('1');
                    carry = 0;
                } else {
                    str.push_back('0');
                }
            } else if (a[a_cur] == '1' && b[b_cur] == '1') {
                if (carry) {
                    str.push_back('1');
                } else {
                    str.push_back('0');
                }
                carry = 1;
            } else {
                if (carry) {
                    str.push_back('0');
                } else {
                    str.push_back('1');
                }
            }
            --a_cur;
            --b_cur;
        }
        
        while (a_cur > -1) {
            if (a[a_cur] == '0'){
                if (carry){
                    str.push_back('1');
                    carry = 0;
                } else {
                    str.push_back('0');
                }
            } else {
                if (carry) {
                    str.push_back('0');
                } else {
                    str.push_back('1');
                }
            }
            --a_cur;
        }
        
        while (b_cur > -1) {
            if (b[b_cur] == '0'){
                if (carry){
                    str.push_back('1');
                    carry = 0;
                } else {
                    str.push_back('0');
                }
            } else {
                if (carry) {
                    str.push_back('0');
                } else {
                    str.push_back('1');
                }
            }
            --b_cur;
        }
        if (carry)
            str.push_back('1');
        
        string tmp;
        int i = str.size()-1;
        while (i > -1) {
            tmp.push_back(str[i]);
            --i;
        }
        return tmp;
    }
};