// https://leetcode.com/problems/koko-eating-bananas/description/

class Solution {
    public:
        int minEatingSpeed(vector<int>& v, int h) {
            int mn=INT_MAX;
            int mx = *max_element(v.begin(), v.end());
            int low=1;
            int high=mx;
            while(low<=high){
                int mid= low + (high-low)/2;
                long long sum=0;
                for(auto i : v){
                    sum+=ceil((double)i/mid);
    
                }
                if(sum<=h){
                    mn=min(mn,mid);
                    high=mid-1;
                    
                }
                else{
                    low=mid+1;
                    
    
                }
              
            }
            return mn;
    
    
            
        }
    };