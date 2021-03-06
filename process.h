#pragma once

typedef enum {
	NOT_YET_ARRIVED, READY, RUNNING, BLOCKED, FINISHED
} process_state;

typedef enum {
    NO_BURST, IO_BURST, CPU_BURST, CX_ON, CX_OFF
} burst_type;

typedef struct process {
    char id; 
    int t_arrive; 
    int num_cpu_burst; 
    int counter_cpu_burst;
    burst_type current_burst_type;
    int current_burst_start;
    int current_burst_start_overall;
    int queue_entry_time;
    bool cpu_burst_preempted;
    int **burst; 
    int tau;
    int next_tau;  //SRT need it to calculate tau
    int TAT;
    int WT;
    process_state state;
} process;

process *copy_process(const process* proc_tmpl);
void free_process(process* proc);
void print_process(const process *proc);
void print_process_summary(const process *proc);
