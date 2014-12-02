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
    int runtime;

    if(argc<2){
	printf("Usage:\n");
	printf("\t ./mem-capacity2.exe -c <coverage percentage> -t <overall runtime>\n");
	return 0;
    }


    while ( (option = getopt(argc, argv, "c:t:")) != -1) {
        switch (option) {
            case 'c' :
                coverage = atoi(optarg);
                break;
            case 't':
		runtime = atoi(optarg);
		break;
        }
    }
    printf("coverage: %d%%\n", coverage);
    printf("time: %ds\n", runtime);

    int i = 0;
    double v = 64;

    printf("cramming %d %% of total memory...\n", coverage);
    size_t tobecovered = (totalcachesize/100) * coverage;
    double *cover = (double *)malloc(tobecovered);

    time_t start, now;
    double diff_t = 0;
    time(&start);

    while( diff_t< runtime){
      for(i=0; i<(tobecovered/sizeof(double)); i+=10){
  	cover[i] = v;
  	cover[i+1] = v;
  	cover[i+2] = v;
  	cover[i+3] = v;
  	cover[i+4] = v;
  	cover[i+5] = v;
  	cover[i+6] = v;
  	cover[i+7] = v;
  	cover[i+8] = v;
  	cover[i+9] = v;
      }
      time(&now);
      diff_t = difftime(now,start);
      sleep(1);
    }
printf("took %f seconds\n", diff_t);

free(cover);
return 0;
}
