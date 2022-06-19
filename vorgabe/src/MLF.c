#include "../lib/MLF.h"
#include <stdio.h>

static queue_object** MLF_queues;
//You can add more global variables here

process* MLF_tick (process* running_process){
/**
 * determine which is the current process to be processed. 
 * @param running_process the prevously running process
 * @result a pointer to the new running process (if something changed) or to the previously running process
 */ 
    return NULL;
}

int MLF_startup(){
    /**
 * Do everything you have to at startup in this function. It is called once.
 * @result 0 if everything was fine. Any other number if there was an error.
 */
    return 1;
}

process* MLF_new_arrival(process* arriving_process, process* running_process){
    /**
 * Handle new arrivals
 * @param arriving_process A pointer to a new arriving process
 * @param running_process A pointer to previously running process
 * @result A pointer to the new active (running) process (if that changed) or to the previously running process
 */ 
    return NULL;
}

void MLF_finish(){
/**
 * is called once after the all processes were handled. In case you want to cleanup something
 */
}





//ERSTES BEISPIEL
typedef struct 
{ 
      int process_id, arrival_time, burst_time, priority;
      int q, ready; 
}process_structure; 
 
int Queue(int t1) 
{ 
      if(t1 == 0 || t1 == 1 || t1 == 2 || t1 == 3) 
      { 
            return 1; 
      } 
      else
      {
            return 2; 
      }
} 
 
int main() 
{ 
      int limit, count, temp_process, time, j, y; 
      process_structure temp; 
      printf("Enter Total Number of Processes:\t"); 
      scanf("%d", &limit);  
      process_structure process[limit]; 
      for(count = 0; count < limit; count++) 
      { 
            printf("\nProcess ID:\t"); 
            scanf("%d", &process[count].process_id); 
            printf("Arrival Time:\t"); 
            scanf("%d", &process[count].arrival_time); 
            printf("Burst Time:\t"); 
            scanf("%d", &process[count].burst_time); 
            printf("Process Priority:\t"); 
            scanf("%d", &process[count].priority); 
            temp_process = process[count].priority; 
            process[count].q = Queue(temp_process);
            process[count].ready = 0; 
      }
      time = process[0].burst_time; 
      for(y = 0; y < limit; y++) 
      { 
            for(count = y; count < limit; count++) 
            { 
                  if(process[count].arrival_time < time) 
                  {
                        process[count].ready = 1; 
                  } 
            } 
            for(count = y; count < limit - 1; count++) 
            {
                  for(j = count + 1; j < limit; j++) 
                  { 
                        if(process[count].ready == 1 && process[j].ready == 1) 
                        { 
                              if(process[count].q == 2 && process[j].q == 1) 
                              { 
                                    temp = process[count]; 
                                    process[count] = process[j]; 
                                    process[j] = temp; 
                              } 
                        } 
                  } 
            } 
            for(count = y; count < limit - 1; count++) 
            { 
                  for(j = count + 1; j < limit; j++) 
                  {
                        if(process[count].ready == 1 && process[j].ready == 1) 
                        { 
                              if(process[count].q == 1 && process[j].q == 1) 
                              { 
                                    if(process[count].burst_time > process[j].burst_time) 
                                    { 
                                          temp = process[count]; 
                                          process[count] = process[j]; 
                                          process[j] = temp; 
                                    } 
                                    else 
                                    { 
                                          break; 
                                    } 
                              } 
                        } 
                  } 
            } 
            printf("\nProcess[%d]:\tTime:\t%d To %d\n", process[y].process_id, time, time + process[y].burst_time); 
            time = time + process[y].burst_time; 
            for(count = y; count < limit; count++) 
            { 
                  if(process[count].ready == 1) 
                  { 
                        process[count].ready = 0; 
                  } 
            } 
      } 
      return 0; 
}



//ZWEITES BEISPIEL
struct process
{
    char name;
    int AT,BT,WT,TAT,RT,CT;
}Q1[10],Q2[10],Q3[10];/*Three queues*/

int n;
void sortByArrival()
{
struct process temp;
int i,j;
for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
            {
                if(Q1[i].AT>Q1[j].AT)
                    {
                          temp=Q1[i];
                          Q1[i]=Q1[j];
                          Q1[j]=temp;
                    }
            }
    }
}

int main()
{
     int i,j,k=0,r=0,time=0,tq1=5,tq2=8,flag=0;
     char c;
     printf("Enter no of processes:");
     scanf("%d",&n);
     for(i=0,c='A';i<n;i++,c++)
     {
         Q1[i].name=c;
         printf("\nEnter the arrival time and burst time of process %c: ",Q1[i].name);
         scanf("%d%d",&Q1[i].AT,&Q1[i].BT);
         Q1[i].RT=Q1[i].BT;/*save burst time in remaining time for each process*/

    }
sortByArrival();
time=Q1[0].AT;
printf("Process in first queue following RR with qt=5");
printf("\nProcess\t\tRT\t\tWT\t\tTAT\t\t");
for(i=0;i<n;i++)
{

  if(Q1[i].RT<=tq1)
  {

       time+=Q1[i].RT;/*from arrival time of first process to completion of this process*/
       Q1[i].RT=0;
       Q1[i].WT=time-Q1[i].AT-Q1[i].BT;/*amount of time process has been waiting in the first queue*/
       Q1[i].TAT=time-Q1[i].AT;/*amount of time to execute the process*/
       printf("\n%c\t\t%d\t\t%d\t\t%d",Q1[i].name,Q1[i].BT,Q1[i].WT,Q1[i].TAT);

  }
  else/*process moves to queue 2 with qt=8*/
  {
      Q2[k].WT=time;
      time+=tq1;
      Q1[i].RT-=tq1;
      Q2[k].BT=Q1[i].RT;
      Q2[k].RT=Q2[k].BT;
      Q2[k].name=Q1[i].name;
      k=k+1;
      flag=1;
   }
}
if(flag==1)
 {printf("\nProcess in second queue following RR with qt=8");
  printf("\nProcess\t\tRT\t\tWT\t\tTAT\t\t");
}for(i=0;i<k;i++)
   {
    if(Q2[i].RT<=tq2)
     {
       time+=Q2[i].RT;/*from arrival time of first process +BT of this process*/
       Q2[i].RT=0;
       Q2[i].WT=time-tq1-Q2[i].BT;/*amount of time process has been waiting in the ready queue*/
       Q2[i].TAT=time-Q2[i].AT;/*amount of time to execute the process*/
       printf("\n%c\t\t%d\t\t%d\t\t%d",Q2[i].name,Q2[i].BT,Q2[i].WT,Q2[i].TAT);

    }
    else/*process moves to queue 3 with FCFS*/
    {
      Q3[r].AT=time;
      time+=tq2;
      Q2[i].RT-=tq2;
      Q3[r].BT=Q2[i].RT;
      Q3[r].RT=Q3[r].BT;
      Q3[r].name=Q2[i].name;
      r=r+1;
      flag=2;
    }
  }

{if(flag==2)
printf("\nProcess in third queue following FCFS ");
}
for(i=0;i<r;i++)
{
    if(i==0)
            Q3[i].CT=Q3[i].BT+time-tq1-tq2;
        else
            Q3[i].CT=Q3[i-1].CT+Q3[i].BT;

}

for(i=0;i<r;i++)
    {
        Q3[i].TAT=Q3[i].CT;
        Q3[i].WT=Q3[i].TAT-Q3[i].BT;
        printf("\n%c\t\t%d\t\t%d\t\t%d\t\t",Q3[i].name,Q3[i].BT,Q3[i].WT,Q3[i].TAT);

    }

}
