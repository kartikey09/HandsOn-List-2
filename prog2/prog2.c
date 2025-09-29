/*
============================================================================
Name : Q2
Author : Kartikey Rana
Description : Write a program to print the system resource limits. Use getrlimit system call. 
Date: 29th Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

// Helper function to print a specific resource limit
void print_limit(const char* resource_name, int resource) {
    struct rlimit limit;

    if (getrlimit(resource, &limit) == 0) {
        printf("%-25s ", resource_name);

        if (limit.rlim_cur == RLIM_INFINITY) {
            printf("%-10s ", "unlimited");
        } else {
            printf("%-10llu ", (unsigned long long)limit.rlim_cur);
        }

        if (limit.rlim_max == RLIM_INFINITY) {
            printf("%-10s\n", "unlimited");
        } else {
            printf("%-10llu\n", (unsigned long long)limit.rlim_max);
        }
    } else {
        perror("getrlimit error");
    }
}

int main() {
    printf("System Resource Limits:\n");
    printf("---------------------------------------------------------\n");
    printf("%-25s %-10s %-10s\n", "Resource", "Soft Limit", "Hard Limit");
    printf("---------------------------------------------------------\n");

    // Print various common resource limits
    print_limit("CPU time (s)", RLIMIT_CPU);
    print_limit("File size (b)", RLIMIT_FSIZE);
    print_limit("Data segment (b)", RLIMIT_DATA);
    print_limit("Stack size (b)", RLIMIT_STACK);
    print_limit("Core file size (b)", RLIMIT_CORE);
    print_limit("Resident set (b)", RLIMIT_RSS);
    print_limit("Processes", RLIMIT_NPROC);
    print_limit("Open files", RLIMIT_NOFILE);
    print_limit("Locked memory (b)", RLIMIT_MEMLOCK);
    print_limit("Address space (b)", RLIMIT_AS);

    return 0;
}


/*
 * System Resource Limits:
---------------------------------------------------------
Resource                  Soft Limit Hard Limit
---------------------------------------------------------
CPU time (s)              unlimited  unlimited
File size (b)             unlimited  unlimited
Data segment (b)          unlimited  unlimited
Stack size (b)            8388608    unlimited
Core file size (b)        0          unlimited
Resident set (b)          unlimited  unlimited
Processes                 unlimited  unlimited
Open files                1048576    1048576
Locked memory (b)         unlimited  unlimited
Address space (b)         unlimited  unlimited
*/
