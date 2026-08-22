class Solution {
public:
    bool checkDivisibility(int n) {
        int original = n;
        int sum = 0, product = 1;

        while (n != 0) {
            int ld = n % 10;   // extract digit
            sum += ld;         // add to sum
            product *= ld;     // multiply into product
            n /= 10;           // remove digit
        }

        int c = sum + product;
        return (original % c) == 0;
    }
};
