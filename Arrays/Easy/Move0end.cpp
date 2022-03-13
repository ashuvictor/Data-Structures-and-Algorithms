/*
Move 0 to end*/
   int j=0;
    for(int i=0;i<A.size();i++){
        if(A[i]!=0)
        {swap(A[i],A[j]);
        j++;}
    }
    return A;
