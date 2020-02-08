/**
计数质数
统计所有小于非负整数 n 的质数的数量。
*/

// 直接数质数，时间不通过
class Solution {
private:
    bool isPrimes(int n) {
        if (n <= 3) return 1;
        for (int i = 2; i * i < n; i++) {
            if (n % i == 0) return 0;
        }
        return 1;
    }
public:
    int countPrimes(int n) {
        int count = 0;
        if (n < 2) return 0;
        int arr[n] = {0};
        for (int i = 2; i < n; i++) {
            if (arr[i] == 1) continue;
            if (isPrimes(i)) {
                count++;
                int j = (double)i < sqrt((double)n) ? i * i : n;
                while (j < n) {
                    arr[j] = 1;
                    j += i;
                }
            }
        }
        return count;
    }
};

// 剔除合数之后剩下的就是质数，快多了
class Solution {
private:
    bool isPrime(int n) {
        if (n <= 3) return 1;
        for (int i = 2; i * i < n; i++) {
            if (n % i == 0) return 0;
        }
        return 1;
    }
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        bool* arr = new bool[n];
        for (int i = 2; i < n; i++) arr[i] = true;
        for (int i = 2; i < n; i++) {
            if (i * i > n) break;
            if (!isPrime(i)) {
                arr[i] = false;
                continue;
            }
            for (int j = i * i; j < n; j+=i) {
                arr[j] = false;
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (arr[i] == true) {
                count++;
            }
        }

        return count;
    }
};
