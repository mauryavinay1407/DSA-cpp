class Solution {
public:
        list<int> slidingWindowTemplate(const string &s, const string &t) {
        list<int> result;
        if(t.length() > s.length()) return result;

        unordered_map<char, int> map;
        for(char c : t) {
            map[c] = map.count(c) ? map[c] + 1 : 1;
        }
        int counter = map.size();
        
        int begin = 0, end = 0;
        int len = INT_MAX;
        
        while(end < s.length()) {
            char c = s[end];
            
            if(map.count(c)) {
                map[c]--;
                if(map[c] == 0) counter--;
            }
            end++;
            
            while(counter == 0) {
                char tempc = s[begin];
                if(map.count(tempc)) {
                    if(map[tempc] == 0) counter++;
                    map[tempc]++;
                }
                
                begin++;
            }
        }
        return result;
    }
};
