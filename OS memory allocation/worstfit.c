#include <stdio.h>

void worstFit(int blockSize[],int m,int processSize[],int n)
{
    //Block allocations for process
    int allocation[n];

    //Initially allocate the index of -1 to all allocation blocks
    for (int i=0;i<n;i++)
    {
        allocation[i]=-1;
    }

    //Fetching the process
    for (int i=0;i<n;i++)
    {
        //Setting the index with maximal wastage
        int best_idx=-1;
        //Keeping the track of free space in best block
        int diff;
        
        //Running for-loop over blocksizes 
        for (int j=0;j<m;j++)
        {
            if (blockSize[j]>=processSize[i])
            {
                //Choosing first block as the best allocated block
                if (best_idx==-1)
                {
                    diff=blockSize[j]-processSize[i];
                    best_idx=j;
                }
                else
                {
                    int inter=blockSize[j]-processSize[i];
                    //Check if this free space is less than that of current best
                    if (diff<inter)
                    {
                        diff=inter;
                        best_idx=j;
                    }
                }
            }
        }

        if (best_idx==-1)
            continue;

        //At the end allot the block to process and re-calculate free-space
        blockSize[best_idx]=processSize[i];
        allocation[i]=best_idx;
    }
    
    //Now printing the allocation array
    for(int i=0;i<n;i++)
    {
        if (allocation[i]!=-1)
            printf("\nBlock for Process No %d with Size %d is %d",i+1,processSize[i],allocation[i]+1);
        else
            printf("\nBlock for Process No %d with Size %d cannot be allocated",i+1,processSize[i]);
    }
    printf("\n\nEnd of process\n");
}


int main() 
{ 
    int blockSize[] = {100, 500, 200, 300, 600}; 
    int processSize[] = {212, 417, 112, 426}; 
    int m = sizeof(blockSize)/sizeof(blockSize[0]); 
    int n = sizeof(processSize)/sizeof(processSize[0]); 
  
    worstFit(blockSize, m, processSize, n); 
  
    return 0 ; 
}