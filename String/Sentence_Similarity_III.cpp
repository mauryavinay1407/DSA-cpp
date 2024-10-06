// problem:  https://leetcode.com/problems/sentence-similarity-iii/description/
/*
Approach-1 (simple using pointers)
T.C : O(m+n)
S.C : O(m+n)
*/
class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.length() < s2.length()) {
            swap(s1, s2);
        }

        vector<string> vec1, vec2;
        stringstream ss1(s1);
        string token;
        while(ss1 >> token) {
            vec1.push_back(token);
        }

        stringstream ss2(s2);
        while(ss2 >> token) {
            vec2.push_back(token);
        }

        int i = 0, j = vec1.size()-1; 
        int k = 0, l = vec2.size()-1;

        while(k < vec2.size() && i < vec1.size() && vec2[k] == vec1[i]) {
            k++;
            i++;
        }

        while(l >= k && vec2[l] == vec1[j]) {
            j--;
            l--;
        }
        
        return l < k;

    }
};


/*
Approach-2 (simple deque)
T.C : O(m+n)
S.C : O(m+n)
*/
class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.length() < s2.length()) {
            swap(s1, s2);
        }

        deque<string> deq1, deq2;
        stringstream ss1(s1);
        string token;
        while(ss1 >> token) {
            deq1.push_back(token);
        }

        stringstream ss2(s2);
        while(ss2 >> token) {
            deq2.push_back(token);
        }

        while(!deq1.empty() && !deq2.empty() && deq1.front() == deq2.front()) {
            deq1.pop_front();
            deq2.pop_front();
        }

        while(!deq1.empty() && !deq2.empty() && deq1.back() == deq2.back()) {
            deq1.pop_back();
            deq2.pop_back();
        }
        
        return deq2.empty();

    }
};
