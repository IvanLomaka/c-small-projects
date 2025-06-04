#include <stdlib.h>
#include <stdio.h>

#define MAX_LEN 1000

typedef struct _slist {
    char * nomefile;
    struct _slist * next;
} slist_t;

int returnLen(slist_t *head) {
    FILE *fp;
    int count;
    int n;

    fp = fopen(head->nomefile, "r");

    count = 0;
    if(fp != NULL) {
        while((fscanf(fp, "%d", &n)) == 1) {
            count++;
        }

        fclose(fp);

        return count;
    } else return -1;
}

slist_t *checkLen(slist_t *head) {
    int minLen = -1;
    slist_t *node = NULL;
    int len;
    slist_t *current = head;

    while(current != NULL) {
        len = returnLen(current);
        if(len != -1 && len < minLen) {
            minLen = len;
            node = current;
        }

        current = current->next;
    }

    return node;
}
