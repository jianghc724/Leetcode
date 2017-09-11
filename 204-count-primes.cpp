class Solution {
public:
    set<int> allPrimes;
    
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        } else if (n <= 3) {
            return 1;
        }
        
        allPrimes.insert(2);
        
        for (int i = 3; i < n; i++) {
            if (isPrime(i)) {
                allPrimes.insert(i);
            }
        }
        
        return allPrimes.size();
    }
    
    bool isPrime(int n) {
        set<int>::iterator it = allPrimes.begin();
        int upper = sqrt(n);
        int cur = *it;
        while (cur <= upper) {
            if (n % cur == 0) {
                return false;
            }
            it++;
            if (it == allPrimes.end()) {
                break;
            }
            cur = *it;
        }
        return true;
    }
};
