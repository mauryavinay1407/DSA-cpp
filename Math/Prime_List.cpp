// problem  :  https://www.geeksforgeeks.org/problems/prime-list--170646/1

/*
Approach -  Using Sieve of Eratosthenes
Time Complexity        :  O( N + M*log N)
Space Complexity       :  O(N)
*/
class Solution {
  public:
    vector<int>sieveof(int max){
        vector<bool>pr(max,true);
        vector<int>primes;
        pr[0]=false;
        pr[1]=false;
        for(int i=2;i*i<=max;i++){
            if(pr[i]){
                for(int p=i*i;p<=max;p+=i){
                    pr[p]=false;
                }
            }
        }
        
        for(int i=2;i<=max;i++){
            if(pr[i]){
                primes.push_back(i);
            }
        }
        return primes;
    }
    Node *primeList(Node *head) {
        // code here
        // sieve +binary search?
        int max=1e4+100;
        vector<int>seive=sieveof(max);
        
        Node* temp=head;
        while(temp){
            int curr=temp->val;
            auto it=lower_bound(seive.begin(),seive.end(),curr);
            if(it==seive.begin()){
                temp->val=*it;
            }
            else{
                int x=*it;
                auto it2=--it;
                int y=*it2;
                //cout<<y<<" "<<x<<endl;
                if((curr-y)>(x-curr)){
                    temp->val=x;
                }
                else{
                    temp->val=y;
                }
            }
            temp=temp->next;
        }
        return head;
    }
};
