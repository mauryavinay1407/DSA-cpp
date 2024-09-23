// problem:  https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

/*
Approach-1 Brute force 
Time Complexity: O(n*m^logm)
Space Complexity: O(m)          // creating temp 
where m = size of pat
*/

	int search(string pat, string txt) {
	 int count=0;
	 string p=pat;
	 sort(p.begin(),p.end());
	 for(int i=0;i<txt.length();i++){
	     string temp="";
	     for(int j=i;j<txt.length();j++){
	         temp+=txt[j];
	         if(temp.length()==p.length())
	         break;
	     }
	     sort(temp.begin(),temp.end());
	     if(temp==p)
	     count++;
	  }
	 return count;   
	 }
};

/*
Approach-2 using sliding window 
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution{
public:
    bool isValid(vector<int>& letters){
        for(int i=0;i<26;i++)
         if(letters[i]>0)
          return false;
      return true;
    }
 
	int search(string pat, string txt) {
	 vector<int> letters(26,0);
	 
	 for(auto& p:pat)
	 letters[p-'a']++;
	 
	 int i=0,j=0;
	 int count=0;
	 while(j<txt.length()){
	     letters[txt[j]-'a']--;
	     if(j-i+1==pat.size()){
	         if(isValid(letters))
	         count++;
	       letters[txt[i]-'a']++;
	       i++;
	     }
	     j++;
	 }
	 return count;
	}

};
