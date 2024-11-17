#define _GNU_SOURCE
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>

#include "util.h"
#include "process.h"

Process *parse_file(FILE * f) {
    size_t s = 0;
    char *headers = NULL;
    size_t line_len = 0;

    line_len = getline(&headers, &line_len, f);
    free(headers);

    Process *pptr = (Process *) malloc(P_SIZE * sizeof(Process));
    if (pptr == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    while (!feof(f)) {
        int t_pid, t_arrival_time, t_priority;
        if (fscanf(f, "%d,%d,%d\n", &t_pid, &t_arrival_time, &t_priority) != 3) {
            fprintf(stderr, "Error: Invalid data format in file.\n");
            free(pptr);
            exit(EXIT_FAILURE);
        }
        process_ctr(&pptr[s], t_pid, t_arrival_time, t_priority);
        s++;
    }

    return pptr;
}
