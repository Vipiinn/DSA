class Solution {
public:

    bool isPrime(int n){
        if(n < 2) return false; 
        for(int i=2;i<n;i++){
            if(n%i == 0) return false;
        }

        return true;
    }

    int countPrimeSetBits(int left, int right) {

        int count = 0;
        
        for(int i=left;i<=right;i++){
            int Scount = 0;
            int num = i;
            while(num > 0){  
                if(num & 1) Scount++;
                num = num >> 1;
            }
            if(isPrime(Scount)) count++;
        }

        return count;
    }
};