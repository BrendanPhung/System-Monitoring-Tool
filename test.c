#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>

int main(int argc, char** argv) {

    struct sysinfo info;

    if (sysinfo(&info) == 0) {
        printf("Success of Info\n");

        long total_memory_mb = info.totalram / 1024 / 1024;
        long free_memory_mb = info.freeram / 1024 / 1024;
        long used_memory_mb = total_memory_mb - free_memory_mb;

        printf("Total RAM: %ld MB\n", total_memory_mb);
        printf("Free RAM: %ld MB\n", free_memory_mb);
        printf("Used RAM: %ld MB\n", used_memory_mb);
    }


    int opt;

    int option_index = 0;

    // Add Options
    static struct option long_options[] = {
        {"cpu", no_argument, 0, 'c'},
        {"cores", no_argument, 0, 'o'},
        {"memory", no_argument, 0, 'm'},
        {"samples", required_argument, 0, 's'},
        {"tdelay", required_argument, 0, 't'},
        {0, 0, 0, 0} 
    };

    // No Argument
    int cpu_flag = 0;
    int cores_flag = 0;
    int memory_flag = 0;

    // Argument (default values)
    int samples = 20;
    int tdelay = 500000; //in microseconds = 500 milliseconds = 0.5 seconds
    int samples_flag = 0;
    int tdelay_flag = 0;

    while ((opt = getopt_long(argc, argv, "", long_options, &option_index)) != -1) {

        //argv[optind - 1] + 2 to access the pointer to the opt after --
        if (strcmp(argv[optind - 1] + 2, long_options[option_index].name) != 0) {
            printf("Invalid option: %s\n", argv[optind - 1]);
            break;
        }

        switch (opt) {
            case 'c':
                printf("--cpu selected\n");
                memory_flag = 1;
                break;
            case 'o':
                printf("--cores selected\n");
                memory_flag = 1;
                break;
            case 'm':
                printf("--memory selected\n");
                memory_flag = 1;
                break;
            case 's':
                if (optarg != NULL) {
                    samples = atoi(optarg);
                }
                samples_flag = 1;
                printf ("--samples selected with value `%s'\n", optarg);
                break;
            case 't':
                if (optarg != NULL) {
                    tdelay = atoi(optarg);
                }
                tdelay_flag = 1;
                printf ("--tdelay selected with value `%s'\n", optarg);
                break;
        }
    }    


    // Run N Samples
    for (int i = 0; i < samples; i++) {
        if (cpu_flag == 1) {

        } 

        if (cores_flag == 1) {

        }

        if (memory_flag == 1) {

        }
    }

    // if ((samples_flag == 0) && (tdelay_flag == 0)) {
    //     samples = atoi(argv[2]);
    //     tdelay = atoi(argv[3]);
    //     printf("samples = %d\n", samples);
    //     printf("tdelay = %d\n", tdelay);
    // }

    

    //free(info);
    
    return 0;
}

//git add .
//git commit -m "message"
//git push 

//git pull origin master
//git reset --hard origin/master to overwrite local
// code . to open to curent directory
// git branch to check branch
//git checkout branch to checkout branch

//gcc test.c -o test

