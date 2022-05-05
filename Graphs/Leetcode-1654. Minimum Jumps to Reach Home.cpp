//Standard Template 1
class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
      
        queue<pair<int,int> >q;
        q.push({0,1});
        int steps=0;
        unordered_set<int> st;
        
        for(auto x:forbidden)
            st.insert(x);
        
        while(!q.empty()){
            
            int n=q.size();
            for(int i=0;i<n;i++){
                int num=q.front().first;
                int check=q.front().second;
                q.pop();
                if(num==x)
                    return steps;
                if(st.find(num)!=st.end())
                    continue;
                st.insert(num);
                
                if(check==1 && (num-b)>=0 )
                    q.push({num-b,0});
                
                if((num-b)<=2000)
                    q.push({num+a,1});
            }
            
            steps+=1;
        }
        
        return -1;
    }
};
