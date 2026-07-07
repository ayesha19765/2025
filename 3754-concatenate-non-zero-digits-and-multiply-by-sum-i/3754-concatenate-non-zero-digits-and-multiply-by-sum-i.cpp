class Solution {
public:
    long long reverse(long long n){
        long long ans = 0;

        while(n){
            ans = ans * 10 + n % 10;
            n /= 10;
        }

        return ans;
    }
    long long sumAndMultiply(int n) {
        n = reverse(n);
        long long x = 0, sum = 0;

        while(n){
            int dig = n % 10;

            if(dig){
                x = x * 10 + dig;
                sum += dig;
            }

            n /= 10;
        }

        return x * sum;
    }
};