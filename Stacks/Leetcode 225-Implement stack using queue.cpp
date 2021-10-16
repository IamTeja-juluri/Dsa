//Approach 1 where push operation is expensive
class MyStack {
public:
    queue<int>q1;
    queue<int>q2;
    
    MyStack() {
        
    }
    
    void push(int x) {
        
        if(q1.empty()){
            q1.push(x);
        }
        else{
            
            while(q1.empty()==false){
                
                int n=q1.front();
                q1.pop();
                q2.push(n);
            }
            q1.push(x);
            
            while(q2.empty()==false){
                q1.push(q2.front());
                q2.pop();
            }
            
        }
        
    }
    
    int pop() {
        
        int n=q1.front();
        q1.pop();
        return n;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
//Approach 2 where pop operation is expensive

class MyStack {
public:
    queue<int>q1;
    queue<int>q2;
    
    MyStack() {
        
    }
    
    void push(int x) {
        
            q1.push(x);
        
    }
    
    int pop() {
        
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }        
        int n=q1.front();
        q1.pop();
        
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        
        return n;
        
        
    }
    
    int top() {
        
        
         while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }        
        int n=q1.front();
        q1.pop();
        
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        q1.push(n);
        return n;
        
    }
    
    bool empty() {
        
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
//Approach 3
// using single queue efficient method
class MyStack {
public:
    queue<int>q;
    
    
    MyStack() {
        
    }
    
    void push(int x) {
        
       
        int size=q.size();
         q.push(x);
        
        while(size--){
            
            int n=q.front();
            q.pop();
            q.push(n);
        }
           
        
    }
    
    int pop() {
        
      
       int n=q.front();
        q.pop();
        return n;
        
        
    }
    
    int top() {
        
     return q.front();
        
    }
    
    bool empty() {
        
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
