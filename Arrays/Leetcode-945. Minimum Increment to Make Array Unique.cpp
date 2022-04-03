class Solution {
public:
    int minIncrementForUnique(vector<int>& a) {
        
        sort(a.begin(),a.end());
        int cost=0;
        int n=a.size();
        for(int i=1;i<n;i++){
            if(a[i]==a[i-1]){
                a[i]=a[i-1]+1;
                cost+=1;
            }
            else if(a[i]<a[i-1]){
                 cost=cost+(a[i-1]+1-a[i]);
                 a[i]=a[i-1]+1;
            }
            
        }
        
        return cost;
    }
};
