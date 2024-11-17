 #ifndef PROCESS_H
#define PROCESS_H

#define P_SIZE 7 // Size of the processes to read from file

typedef struct _process {
    int pid;           
    int arrival_time;  
    int priority;      
} Process;

void process_ctr(Process *p, int pid, int arrival_time, int priority);

#endif // PROCESS_H
