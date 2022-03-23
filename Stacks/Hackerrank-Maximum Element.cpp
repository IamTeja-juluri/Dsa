#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int t;
    cin>>t;
    stack<int>max;
     max.push(0);

    stack<int>st;
    
    while(t--){
        int a;
        cin>>a;
        if(a==1){
            int val;
            cin>>val;
            if(max.top()<=val)
                max.push(val);
             else
                max.push(max.top()) ;  
            st.push(val);
        }
        else if(a==2){
              max.pop();
            st.pop();
        }
        else {
            cout<<max.top()<<endl;
        }
    }    
    
}

// app 2
#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int t;
    cin>>t;
    stack<int>max;
     max.push(0);

    stack<int>st;
    
    while(t--){
        int a;
        cin>>a;
        if(a==1){
            int val;
            cin>>val;
            if(max.top()<=val)
                max.push(val);
            st.push(val);
        }
        else if(a==2){
             if(st.top()==max.top())
              max.pop();
            st.pop();
        }
        else {
            cout<<max.top()<<endl;
        }
    }    
    
}
