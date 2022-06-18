#include "../lib/LCFS.h"

static queue_object* LCFS_queue;
//You can add more global variables here

int LCFS_startup(){
    // TODO
    return 0;
}

process* LCFS_tick (process* running_process){
    // TODO
    return NULL;
}


process* LCFS_new_arrival(process* arriving_process, process* running_process){
    // TODO
    return NULL;
}

void LCFS_finish(){
    // TODO
}



//FCFS nur umdrehen
int main()
 
{
    int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
    printf("Enter total number of processes(maximum 20):");
    scanf("%d",&n);
 
    printf("nEnter Process Burst Timen");
    for(i=0;i<n;i++)
    {
        printf("P[%d]:",i+1);
        scanf("%d",&bt[i]);
    }
 
    wt[0]=0;   
 
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }
 
    printf("nProcessttBurst TimetWaiting TimetTurnaround Time");
 
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("nP[%d]tt%dtt%dtt%d",i+1,bt[i],wt[i],tat[i]);
    }
 
    avwt/=i;
    avtat/=i;
    printf("nnAverage Waiting Time:%d",avwt);
    printf("nAverage Turnaround Time:%d",avtat);
 
    return 0;
}
