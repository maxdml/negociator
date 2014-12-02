#define _GNU_SOURCE

#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/syscall.h>

int main (int argc, char *argv[]) {

    int option;
    int duration;
    char type;
    int pin;

    if (argc < 3) {
        printf("Usage: ./unit_s -d<duration> [-f (fp)|-i (int), -p (cpu affinity)]\n");

        return 1;
    }

    while ( (option = getopt(argc, argv, "d:p:fi")) != -1) {
        switch (option) {
            case 'f' :
                type = 'f'; 
                break;
            case 'i' :
                type = 'i'; 
                break;
            case 'd' :
                duration = atoi(optarg);
                break;
            case 'p' :
                pin = atoi(optarg); 
                break;
        }
    }

    cpu_set_t *cpusetp;
    cpusetp = CPU_ALLOC(1);

    size_t size;
    size = CPU_ALLOC_SIZE(1);
    CPU_ZERO_S(size,cpusetp);
    CPU_SET(pin, cpusetp);

    int set = sched_setaffinity(0, size, cpusetp);
    
    if (set != 0) {
        printf("Could not proceed to cpu pinning\n");
        return 1;
    }

    time_t t = time(NULL);
    //printf("Time at startup %d\n", (int)t);

    int dt = t + duration;
    //printf("Time to reach %d\n", dt);

    float result = 0;
    int c = 1;

    if (type == 'f') {
        while (c != 0) {
            float value = 3.14;

            result = value * value;

            if (dt <= time(NULL)) {
                c = 0;
            }
        }
    } else if (type == 'i') {
        while (c != 0) {
            int value = 3;

            result = value * value;

            if (dt <= (int)time(NULL)) {
                //printf("Time elapsed %d\n", (int)(time(NULL)));
                c = 0;
            }
        }
    } else {
        printf("Wrong or no type given. Use 'i' for integers or 'f' for fp\n");
    }

    printf("use the variable, you know. %f\n", result);

    return 0;
}
