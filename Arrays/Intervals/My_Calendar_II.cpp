// problem:  https://leetcode.com/problems/my-calendar-ii/description/

/*
Approach: using vector of pairs of intervals
Time Complexity: O(N + T)
Space Complexity: O(N)
Where N is the number of single bookings and T is the number of double bookings.
*/

class MyCalendarTwo {
public:
    vector<pair<int,int>> cal;
    vector<pair<int,int>> temp;
    MyCalendarTwo() {
        
    }
    bool book(int start, int end) {
       for(auto [tempFirst,tempSecond]:temp){
        if(max(start,tempFirst)<min(end,tempSecond))
         return false;
       }
       for(auto [first,second]:cal){
        if(max(start,first)<min(end,second)){
            temp.push_back({max(start,first),min(end,second)});
        }
       }
       cal.push_back({start,end});
       return true;
    }

};
