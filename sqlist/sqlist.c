#include <stdlib.h>
#include <stdio.h>
#include "./sqlist.h"

void List_Init(sqlist *const me, int (*getLengthfunction)(sqlist *const me),
               int (*isEmptyfunction)(sqlist *const me),
               Status (*insertfunction)(sqlist *const me, int i, int e),
               int (*removefunction)(sqlist *const me, int i)) {
    /* initialize atttributes */
    me->length = 0;
    me->size = MAXSIZE;
    me->getLength = getLengthfunction;
    me->isEmpty = isEmptyfunction;
    me->insert = insertfunction;
    me->remove = removefunction;
    me->data = (int *) malloc(sizeof(int)*me->size);
}

/**
  * @brief destructor of sqlist
  * 
  */
void List_Cleanup(sqlist *const me) {}

/**
 * @brief return the current length of sqlist
 * 
 * @param me the pointer to the list
 * @return int the total length
 */
int List_getLength(sqlist *const me) {
    return me->length;
}

int List_isEmpty(sqlist *const me) {
    return (me->length == 0);
}

Status List_insert(sqlist *const me, int i, int e) {
    int *newbase, *p, *q;
    if (i < 1 || me->length + 1 < i)
        return ERROR; /* wrong index to insert */
    if (me->length == me->size) {
        newbase = (int *) realloc(me->data, (MAXSIZE + INCREMENT) * sizeof(int));
        if (!newbase)
            return OVERFLOW; /* no enough space for increment */
        me->data = newbase;
        me->size += INCREMENT;
    }
    p = &(me->data[me->length-1?me->length:0]);
    for ( q = &(me->data[i-1]); q <= p; p--)
    {
        *(p + 1) = *p;
    }
    *q = e;
    me->length++;
    return OK;
}

int List_remove(sqlist *const me, int i) {
    int *p, *q;
    if (i < 1 || i > me->length)
        return ERROR;
    p = &(me->data[me->length-1]);
    q = &(me->data[i - 1]);
    int ret = *q;
    // for (q < p; q++)
    while(q++ < p)
        *p = *(p + 1);
    me->length--;
    return ret;
}

sqlist *List_Create() {
    sqlist *me = (sqlist *) malloc(sizeof(sqlist));
    if (me) {
        List_Init(me, List_getLength, List_isEmpty, List_insert, List_remove);
    }
    return me;
}

void List_Destroy(sqlist *const me) {
    if (me != NULL) {
        List_Cleanup(me);
    }
    free(me);
}