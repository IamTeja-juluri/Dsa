class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size())
            return false;

        int times = s.size();
        int counter = 1;

        while(counter<=times){
            string s1 = s.substr(0,counter);
            string s2 = s.substr(counter);
            string res = s2+s1;
            if(res == goal)
                return true;
            counter+=1;
        }

        return false;
    }
};
