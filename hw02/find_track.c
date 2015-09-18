/* Example code for Software Systems at Olin College.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define NUM_TRACKS 5

char tracks[][80] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};


// Finds all tracks that contain the given string.
//
// Prints track number and title.
void find_track(char search_for[])
{
    int i;
    for (i=0; i<NUM_TRACKS; i++) {
	if (strstr(tracks[i], search_for)) {
	    printf("Track %i: '%s'\n", i, tracks[i]);
	}
    }
}

// Finds all tracks that match the given pattern.
//
// Prints track number and title.
int find_track_regex(char pattern[])
{
    // TODO: fill this in
    int i;
    regex_t re;
    char buffer[100];
    int rc = regcomp(&re, pattern, REG_EXTENDED|REG_NOSUB);

    if (rc != 0) {
        regerror(rc, &re, buffer, 100);
        printf("regcomp() failed with '%s'\n", buffer);
        exit(EXIT_FAILURE);
    }
    for (i=0; i<NUM_TRACKS; i++){
        int status = regexec(&re, tracks[i], (size_t) 0, NULL, 0);
        if (status == 0) {
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }
    regfree(&re);
}

// Truncates the string at the first newline, if there is one.
void rstrip(char s[])
{
    char *ptr = strchr(s, '\n');
    if (ptr) {
	*ptr = '\0';
    }
}

int main (int argc, char *argv[])
{
    char search_for[80];

    /* take input from the user and search */
    printf("Search for: ");
    fgets(search_for, 80, stdin);
    rstrip(search_for);
    // find_track(search_for);
    find_track_regex(search_for);

    return 0;
}
