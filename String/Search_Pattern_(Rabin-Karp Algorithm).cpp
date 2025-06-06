// problem  :  https://www.geeksforgeeks.org/problems/search-pattern-rabin-karp-algorithm--141631/1

/*
Approach-1 : Brute Force Using direclty simple function and checking ( without hashing)
Time Complexity       :  O(n * m)
Space Complexity      :  O(1)
*/
class Solution {
public:
    int hashFunc(char ch){
        return ch - 'a' + 1;
    }    
    vector<int> search(string &pat, string &txt) {
        // code here.
        int m = pat.length();
        int n = txt.length();
        int func = 0;
        for(auto& p : pat){
            func += hashFunc(p);
        }
        
        int total = 0;
        
        int i=0;
        vector<int> result;
        for(int j=0;j<txt.length();j++){
            total += hashFunc(txt[j]);
            
            if(j - i + 1 == m){
                if(txt.substr(i,m) == pat){
                    result.push_back(i + 1);
                }
                total -= hashFunc(txt[i]);
                i++;
            }
        }
        
        return result;
    }
};
/*
Approach-2 : Using Rabin-Karp (hashing)
Time Complexity       :  O(n + m)
Space Complexity      :  O(1)
*/
class Solution {
public:
    int base = 26;
    int mod = 1e9 + 7;

    vector<int> search(string &pat, string &txt) {
        int m = pat.length();
        int n = txt.length();

        if(m > n) return {};

        long long patHash = 0, txtHash = 0, power = 1;

        // Precompute the highest base power: base^(m-1)
        for(int i = 0; i < m - 1; i++) {
            power = (power * base) % mod;
        }

        // Compute hash of pattern and first window
        for(int i = 0; i < m; i++) {
            patHash = (patHash * base + (pat[i] - 'a')) % mod;
            txtHash = (txtHash * base + (txt[i] - 'a')) % mod;
        }

        vector<int> result;
        for(int i = 0; i <= n - m; i++) {
            if(patHash == txtHash && txt.substr(i, m) == pat) {
                result.push_back(i + 1);
            }

            // Roll the hash
            if(i < n - m) {
                txtHash = (txtHash - (txt[i] - 'a') * power % mod + mod) % mod;
                txtHash = (txtHash * base + (txt[i + m] - 'a')) % mod;
            }
        }

        return result;
    }
};
