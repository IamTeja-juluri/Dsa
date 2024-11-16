class Solution {
public:
    int findTheWinner(int n, int k) {

        list<int> l;
        int i=1;

        while(i<=n){
            l.push_back(i);
            i+=1;
        }

        auto it = l.begin();
        auto startPtr = it;

        while(l.size()>1){

            for(int i=1;i<k;i++){
                it++;
                if(it==l.end()){
                    it=l.begin();
                }
            }

            it = l.erase(it);

            if (it == l.end()) {
                it = l.begin();
            }

          
        }

        return l.front();
        
    }
};
