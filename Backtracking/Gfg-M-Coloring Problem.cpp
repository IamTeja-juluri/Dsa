bool isSafe(bool graph[101][101],int color[],int c,int node,int V){
    
    for(int i=0;i<V;i++){
        
        if(graph[node][i] && color[i]==c){
            return false;
        }
        
    }
    return true;
    
}

bool helper(bool graph[101][101],int color[],int node,int m,int V){
    
    if(node==V){
        return true;
    }
    
    for(int c=1;c<=m;c++){
        
        if(isSafe(graph,color,c,node,V)){
            
           color[node]=c;
           bool res= helper(graph,color,node+1,m,V);
           if(res) return true;
           color[node]=0;
            
        }
        
    }
    
    return false;
        
}



bool graphColoring(bool graph[101][101], int m, int V)
{
   
    int color[V]={0};
    
    return helper(graph,color,0,m,V);
    
}