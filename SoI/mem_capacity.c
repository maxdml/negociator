#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main (int argc, char **argv) {

    //Define cache sizes. Can be looked up dynamically in /sys/devices/system/cpu/cpuX/cache/indexZ 
    const int l1size = 32 * 1024;
    const int l2size = 256 * 1024;
    const int l3size = 6144 * 1024;
    const double mainmem = 16698277888;
    const double totalcachesize = l3size + l2size + l1size + mainmem;
    //gradually fill up all layers of cache

    int option;
    int coverage;

    while ( (option = getopt(argc, argv, "c:")) != -1) {
        switch (option) {
            case 'c' :
                coverage = atoi(optarg);
                break;
        }
    }
    printf("coverage: %d%%\n", coverage);

    int i = 0;

    for (i = 0; i < coverage; i++) {
        printf("cramming %d %% of total memory...\n", i);

        size_t tobecovered = (totalcachesize  / 100 ) * i;
        double *cover = (double *)malloc(tobecovered);

        int j = 0;
        double v = 64;
        for (j = 0; j < (tobecovered / sizeof(double)); j++) {
            cover[j] = v;
        }

        free(cover);
    }

return 0;
}
