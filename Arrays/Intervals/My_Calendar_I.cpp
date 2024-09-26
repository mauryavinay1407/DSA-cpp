// problem:  https://leetcode.com/problems/my-calendar-i/description/

/*
Approach-1: Brute Force
Time C: O(n^2)
Space C: O(n)
*/

using P=pair<int,int>;
class MyCalendar {
private:
   vector<P> cal;
public:
    MyCalendar() {
        
    }
      bool book(int start, int end) {
        for(int i = 0; i<cal.size(); i++) {
            P curr = cal[i];
            if(!(end <= curr.first || start >= curr.second))
                return false;
        }
        
        cal.push_back({start, end});
        return true;
    }
};

/*
Approach-2: using lower_bound
Time C: O(nlogn)
Space C: O(n)
*/

using P=pair<int,int>;
class MyCalendar {
private:
  set<P> st;
public:
    MyCalendar() {
        
    }
      bool book(int start, int end) {
       auto it=st.lower_bound({start,end});
       if(it!=st.end() && end>it->first)
        return false;
       if(it!=st.begin()){
        auto pre=prev(it);
        if(pre->second>start)
        return false;
       }
       st.insert({start,end});
       return true;
    }
};

/*
Approach-3: using min and max (very simple)
Time C: O(n)
Space C: O(n)
*/
class MyCalendar {
private:
   vector<pair<int,int>> cal;
public:
    MyCalendar() {
        
    }

    bool book(int start, int end) {
        if(cal.empty()){
            cal.push_back({start,end});
            return true;
        }
        for(auto [tempstart, tempend] : cal) {
            if (max(tempstart, start) < min(tempend, end)) {
                return false;
            }
        }
        cal.push_back({start,end});
        return true;
    }
};
