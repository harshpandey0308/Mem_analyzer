#ifndef PROCESS_DATA_HPP
#define PROCESS_DATA_HPP

#include<unistd.h>
#include<cstdint>

typedef struct Process_Identity{
       pid_t PID;                  // Process ID 
       uint64_t e_time;        // Helps to know the beginning of a process and also helps recognise to different process with same pid
}Process_Identity;

typedef enum state{
       R,            // Running/Runable - currently executing or ready to execute.
       S,            // Interruptible sleep - waiting for an event;can be awakened by the signal 
       D,            // Waiting for certain kernel operations , usually I/O
       T,            // Execution stopped , usually by a signal
       t,            // stopped by a debugger or tracing mechanism
       Z,            // Process has terminated but waiting for its parent process to collect its exit status
       X,            // Process is dead , generally a transient state.
       I             // Idle kernel thread
}proc_state;

typedef struct Raw_Data{
       pid_t pid;                            // Process PID 
       pid_t ppid;                           // process's parent id
       char *proc_name;                      // process name
       char state;                     // process state

       uint64_t RSS;                         // Resident Set Size - physical memory currently occupied by the process
       uint64_t Vmsize;                      // Virtual Memory Size - total virtual address space acquired by the process
       uint64_t Vm_Swap;
       uint64_t RSS_anon;
       uint64_t Rss_File;
       uint64_t Rss_Shmmem;
}Raw_Data;


int extract_info();
       

#endif

