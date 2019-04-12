class Solution {
public:
    int romanToInt(string s) {
        int ll = s.size();
        int num = 0;
        char ch = s[0];
        switch (ch) {
            case 'I': num += 1; break;
            case 'V': num += 5; break;
            case 'X': num += 10; break;
            case 'L': num += 50; break;
            case 'C': num += 100; break;
            case 'D': num += 500; break;
            case 'M': num += 1000; break;
            default: break;
        }
        for (int i = 1; i < ll; ++i) {
            if  (s[i] == 'I') {
                num += 1;
            } else if (s[i] == 'V') {
                if (s[i-1] == 'I') {
                    num -= 2;
                } 
                num += 5;
            } else if (s[i] == 'X') {
                if (s[i-1] == 'I') {
                    num -= 2;
                }
                num += 10;
            } else if (s[i] == 'L') {
                if (s[i-1] == 'X')
                    num -= 20;
                num += 50;
            } else if (s[i] == 'C') {
                if (s[i-1] == 'X')
                    num -= 20;
                num += 100;
            } else if (s[i] == 'D') {
                if (s[i-1] == 'C')
                    num -= 200;
                num += 500;
            } else if (s[i] == 'M') {
                if (s[i-1] == 'C')
                    num -= 200;
                num += 1000;
            }
        }
        return num;
    }
};