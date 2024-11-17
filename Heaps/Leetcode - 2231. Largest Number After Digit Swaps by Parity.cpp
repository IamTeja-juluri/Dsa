class Solution {
public:
    int largestInteger(int num) {

        priority_queue<int> even_pq;
        priority_queue<int> odd_pq;

        string s = to_string(num);

        while(num!=0){
            int r = num%10;
            if((r%2)==0)
                even_pq.push(r);
            else
                odd_pq.push(r);
            num = num/10;
        }

        int ans = 0;

        for(int i=0;i<s.size();i++){
            int val = s[i] - '0';
            int top;
            if(val%2 == 1){
                top = odd_pq.top();
                odd_pq.pop();
            }else{
                top = even_pq.top();
                even_pq.pop();
            }
            ans = ans*10+top;
        }

        return ans;
    }

};
