// 这题主要注意上界会不会溢出
class Solution {
public:
    int int_max = 46340;
    int search(int x, int l, int r) {
        if (r == l) {
            return l;
        } else if (r - l == 1) {
            if (r < int_max && r * r == x)
                return r;
            else
                return l;
        } else {
            int mid = (l + r) / 2;
            if (mid > int_max)
                return search(x, l, mid);
            int tmp = mid * mid;
            if (tmp < x) {
                return search(x, mid, r);
            } else if (tmp > x) {
                return search(x, l, mid);
            } else {
                return mid;
            }
        }
    }
    
    int mySqrt(int x) {

        int mid = x / 2;
        int l = 1;
        if (mid > int_max)
            return search(x, l, mid);
        int tmp = mid * mid;
        if (tmp < x) {
            return search(x, mid, x);
        } else if (tmp > x){
            return search(x, l, mid);
        } else {
            return mid;
        }
        
    }
};