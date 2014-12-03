#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <unistd.h>

int main (int argc, char **argv) {

    int option;
    int duration;

    while ( (option = getopt(argc, argv, "d:")) != -1) {
        switch (option) {
            case 'd' :
                duration = atoi(optarg);
                break;
        }
    }
    printf("duration: %d sec \n", duration);

    time_t t_start = time(NULL);
    time_t t = 0;
    int dt = t_start + duration;

    int *access = (int *)malloc(4*sizeof(int));

    int read[4];

    while (t < dt ) {
        read[0] = access[0];
        read[1] = access[1];
        read[2] = access[2];
        read[3] = access[3];
        
        t = time(NULL);
	free(access);
        access = (int *)malloc( 4*sizeof(int) );
    }

    printf("using the var, you know... %d, %d, %d, %d\n", read[0], read[1], read[2], read[3]);

    free(access);

    return 0;
}
