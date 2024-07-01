#include <stdio.h>

// Calculate waiting time for all processes:
void waiting_time(int processes[], int p, int burst_time[], int waiting_time[]){
    
    int i;
    
    waiting_time[0] = 0;

    for (i = 1; i < p; i++){
    	
        waiting_time[i] = burst_time[i - 1] + waiting_time[i - 1];
        
    }
    
}

//Calculate turnaround time for all processes:
void turnaround_time(int processes[], int p, int burst_time[], int waiting_time[], int turnaround_time[]) {
    
    int i;
    
    for (i = 0; i < p; i++){
    	
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        
    }
    
}

//Calculate average waiting time for all processes:
void average_time(int processes[], int p, int burst_time[]) {
	
	int i;
    int waiting_time[p], turnaround_time[p];
    int total_waiting_time = 0, total_turnaround_time = 0;

    //Callback function to calculate waiting time:
    waiting_Time(processes, p, burst_time, waiting_time);

    //Callback function to calculate turnaround time:
    turnaround_Time(processes, p, burst_time, waiting_time, turnaround_time);

    //Calculate total waiting time and total turnaround time:
    for (i = 0; i < p; i++){
    	
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    
	}

    float average_waiting_time = total_waiting_time / p;
    float average_turnaround_time = total_turnaround_time / p;

    printf("Average Waiting Time: %f \n", average_waiting_time);
    printf("Average Turnaround Time: %f \n", average_turnaround_time);
}

int main(){
	
	int i;
    int p;

    printf("Enter the number of processes : ");
    scanf("%d", &p);
    
    printf("\n");

    int processes[p], burst_time[p];
    
	//acquiring data
    for (i = 0; i < p; i++) {
    	
        processes[i] = i + 1;
        printf("Enter burst time for process %d : ", i + 1);
        scanf("%d", &burst_time[i]);
        
    }
    
    printf("\n");
	
	//the result
    average_time(processes, p, burst_time);

}

