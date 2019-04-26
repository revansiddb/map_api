#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<math.h>

int minimumTime(int robo, int T, int task[], int n);
int getMaximum(int a[], int n);
int isPossible(int time, int robo, int task[], int n);

int main(void) //main program
{ 
    int task[] = {4,5,10}; 
    int n = sizeof(task)/sizeof(task[0]); 
    int robo = 2, T = 5,r;
    r = minimumTime(robo, T, task, n);
    printf("%d\n",r);
    return 0; 
} 


int minimumTime(int robo, int T, int task[], int n) // Returns minimum time required to finish given array of tasks 
{    
    int end = 0, start = 0; 
    for (int i = 0; i < n; ++i) 
        end += task[i]; 
    int res = end; 
    int task_max = getMaximum(task, n); 
 
    while (start <= end) 
    { 
        int mid = (start + end) / 2; 
        if (mid >= task_max && isPossible(mid, robo, task, n)) 
        { 
            res = fmin(res, mid);  
            end = mid - 1; 
        } 
        else
            start = mid + 1; 
    } 

    return (res * T); 
} 

int getMaximum(int a[], int n) 
{ 
    int result = a[0]; 
    for (int i=1; i<n; i++) 
    if (a[i] > result) 
        result = a[i]; 
    return result; 
} 

// Returns true if it is possible to finish task[] within given time 'time' 
int isPossible(int time, int robo, int task[], int n) 
{   
    int count = 1; 
    int curr_time = 0; 
    
    for (int i = 0; i < n;) 
    { 
        if (curr_time + task[i] > time) 
        { 
            curr_time = 0; 
            count++; 
        } 
        else
        { 
            curr_time += task[i]; 
            i++; 
        } 
    } 

    // Returns true if count is smaller than k 
    return (count <= robo); 
} 












