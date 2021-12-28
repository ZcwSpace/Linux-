#ifndef H_SEM_H
#define H_SEM_H

extern void print_error(char *str);
extern int get_sem(int sem_num);
extern void init_sem(int sem_id,int sem_num,int val);
extern void delete_sem(int sem_id,int sem_num_sum);
extern void signal_catch(int signal_index);
extern void v_sem(int sem_id);
extern void p_sem(int sem_id);

#define NSEMS 1 

union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  array;  /* Array for GETALL, SETALL */
 };

#endif