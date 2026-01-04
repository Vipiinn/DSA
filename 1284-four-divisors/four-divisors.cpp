class Solution {
public:

    int noOfDivisor(int n){
        int count = 0;
        int sum = 0;

        for(int i = 1; i * i <= n; i++){
            if(n % i == 0){
                int d1 = i;
                int d2 = n / i;

                count++;
                sum += d1;

                if(d1 != d2){
                    count++;
                    sum += d2;
                }

                if(count > 4) return 0;
            }
        }

        if(count == 4) return sum;
        return 0;
    }

    int sumFourDivisors(vector<int>& nums) {

        int sum = 0;

        for(int i = 0; i < nums.size(); i++){
            sum += noOfDivisor(nums[i]);
        }

        return sum;
    }
};
