int countMinOperations(int arr[], int n) {
        // code here
        
        int res=0;
        
        while(1){
            
            int zerocnt=0;
            
            int i;
            
            for(i=0;i<n;i++){
                if(arr[i]%2==1)
                break;
                if(arr[i]==0)
                zerocnt+=1;
            }
            
            if(zerocnt==n)
            return res;
            
            //when odd is not present
            if(i==n){
                for(int j=0;j<n;j++){
                    arr[j]/=2;
                }
                res+=1;
            }
            
            else{
                for(int j=0;j<n;j++){
                    if(arr[j]%2 == 1){
                    arr[j]-=1;
                    res+=1;
                    }
                }
            }
            
            
        }
        
        return 0;
        
    }
