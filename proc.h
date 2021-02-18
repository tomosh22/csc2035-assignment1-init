/******** DO NOT EDIT THIS FILE ********/
#ifndef _PROC_H
#define _PROC_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Introduction 
 * 
 * proc.h defines constants, types and functions that support simulation
 * and provide meta information about process in the simulation to control
 * their execution.
 *
 * see the applications bwait_consumer, bwait_producer, sem_consumer and 
 * sem_producer for usage.
 */

#define MAX_FILENAME_LEN 31
#define MIN_ID 0
#define MAX_ID 99

typedef enum proctype {
    BWAIT_CONS_PROC, BWAIT_PROD_PROC, SEM_CONS_PROC, SEM_PROD_PROC 
} proctype_t;

/*
 * specification of range of work to do. During a simulation, when 
 * a work a deley is required to simulate work to be done, a random 
 * number for the millisecond delay is generated between the work_ms min
 * and max values.
 */
typedef struct work_ms {
    long min;
    long max;
} work_ms_t;

/* 
 * process descriptor type
 */
typedef struct proc {
    proctype_t type;    // process type (see above)
    char name[MAX_FILENAME_LEN + 1];    // process name
    int id;             // process id
    int jobs;           // number of jobs to do 
    bool is_init;       // is init process that sets up shared memory etc.
    long delay_start;   // delay process start
    long delay_exit;    // delay process exit
    work_ms_t crit_work;    // work to do in critical section
    work_ms_t noncrit_work; // work to do in non-critical section
    void* queue;            // the shared job queue
    void (*queue_destructor)(void*);    // destructor for the queue
    void* mutex;            // the busy waiting mutex (NULL for semaphore queue)
    void (*mutex_destructor)(void*);    // destructor for the queueu
    /* job control fields to detect skipped jobs during simulation */
    int skips;            
    int skip_limit;
} proc_t;

/*
 * control struct to pass shared object constructors and destructors
 * to proc_setup for initialisation of simulation.
 */
typedef void* (*constructor_t)(proc_t*);
typedef void (*destructor_t)(void*); 

typedef struct shobj_ctrl {
    constructor_t constructor;
    destructor_t destructor;
} shobj_ctrl_t;

/*
 * exit simulation with error message
 */
void error_exit(const char* err_msg);

/*
 * For use in a critical section to inject a random millisecond delay in
 * process execution (during which the process will block). The random 
 * delay will be in the range of the proc.crit_work min and max values.
 *
 */
void do_critical_work(proc_t* proc);

/*
 * For use in a non-critical section to inject a random millisecond delay in
 * process execution (during which the process will block). The random 
 * delay will be in the range of the proc.noncrit_work min and max values.
 */
void do_noncritical_work(proc_t* proc);


void delay_ms(long ms);

proc_t* proc_init(int argc, char** argv, proctype_t type);

proc_t* proc_new(proctype_t type, char* name, int id, int jobs, bool is_init,
    int delay_start, int delay_exit, work_ms_t crit_work, 
    work_ms_t noncrit_work);
    
void proc_delete(proc_t* proc);
    
proc_t* proc_setup(int argc, char** argv, int proc_type, 
    shobj_ctrl_t* queue_ctrl, shobj_ctrl_t* mutex_ctrl);
    
void proc_teardown(proc_t* proc);

#endif