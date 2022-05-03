//Gives Tle with bfs
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        queue<string>q;
        set<string>st;
        
        q.push(s);
        st.insert(s);
        
        while(!q.empty()){
            
            string curr=q.front();
            q.pop();
            
            for(int i=0;i<pairs.size();i++){
                string temp=curr;
                swap(temp[pairs[i][0]],temp[pairs[i][1]]);
                if(st.find(temp)==st.end()){
                    st.insert(temp);
                    q.push(temp);
                }
            }
        }
        
        auto it=st.begin();
        return *(it);
    }
};
