#include <stdio.h>
#include <stdbool.h>

//assigning the limit for number of processes and resources:
int limit_p = 10;
int limit_r = 10;

//calculating the need matrix:
void Need(int need[limit_p][limit_r], int max[limit_p][limit_r], int allocation[limit_p][limit_r], int p, int r) {
    
	int i,j;
	
	for (i = 0; i < p; i++){
		
		for (j = 0; j < r; j++){
			
			need[i][j] = max[i][j] - allocation[i][j];
			
		}
            
	}
        
}

//detection of dead-lock state:
void detection(int processes[], int available[], int max[][limit_r], int allocation[][limit_r], int p, int r) {
    
	int i,j,l,k;
	int need[limit_p][limit_r];
	
    Need(need, max, allocation, p, r);
	
	//assigning finish vector:
	bool finish[10] = {0};
    
    //assigning work vector:
    int work[limit_r];
    
    //initialising work vector to available
    for (i = 0; i < r; i++){
    	
    	work[i] = available[i];
    	
	}
      
	//detection:  
	int count = 0;
    
    while (count < p) {
    	
        bool found = false;
        
        for (l = 0; l < p; l++) {
        	
            if (!finish[l]) {
            	
                bool canAllocate = true;
                
                for (j = 0; j < r; j++) {
                	
                    if (need[l][j] > work[j]) {
                    	
                        canAllocate = false;
                        
                        break;
                        
                    }
                    
                }
                
                if (canAllocate) {
                	
                    for (k = 0; k < r; k++){
                    	
                    	work[k] += allocation[l][k];
                    	
					}
                        
                    finish[l] = true;
                    
                    found = true;
                    
                    count++;
                    
                }
                
            }
            
        }
        
        if (!found) {
        	
            printf("System is not in a safe state\n");

        }
    }
    
    printf("System is in a safe state\n");
}

int main() {
	
	int i,j;
    int p, r;
    
    int processes[limit_p];
    int available[limit_r];
    int max[limit_p][limit_r];
    int allocation[limit_p][limit_r];

    printf("Enter number of processes: ");
    scanf("%d", &p);
    printf("Enter number of resource types: ");
    scanf("%d", &r);

    printf("Enter the Max Matrix :\n");
    for (i = 0; i < p; i++){
    	
    	for (j = 0; j < r; j++){
    		
    		scanf("%d", &max[i][j]);
    		
		}
            
	}
        
	printf("Enter the Allocation Matrix :\n");
    for (i = 0; i < p; i++){
    	
    	 for (j = 0; j < r; j++){
    	 	
    	 	scanf("%d", &allocation[i][j]);
    	 	
		 }
            
	}
       
    printf("Enter the Available resources vector: ");
    for (i = 0; i < r; i++){
    	
    	scanf("%d", &available[i]);
    	
	}
        
	detection(processes, available, max, allocation, p, r);

    return 0;
    
}
