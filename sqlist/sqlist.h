#ifndef SQLIST_H
#define SQLIST_H

#include "../common.h"
#define MAXSIZE 20
#define INCREMENT 5

typedef struct sqlist sqlist;
struct sqlist
{
	int size;	  /* maximum size of the list */
	int length; /* the current length of the list */
	int *data;  /* the storage of elements */
	int (*getLength)(sqlist *const me);
	int (*isEmpty)(sqlist *const me);
	Status (*insert)(sqlist *const, int i,int e);
	int (*remove)(sqlist *const, int i);/* remove r-th element */
};

/* Constructors and destructors  */
void List_Init(sqlist *const me, int (*getLengthfunction)(sqlist *const me),
			   int (*isEmptyfunction)(sqlist *const me),
			   Status (*insertfunction)(sqlist *const me, int i,int e),
			   int (removefunction(sqlist *const me, int i)));
void List_Cleanup(sqlist *const me);

/* Operations */
int List_getLength(sqlist *const me);
int List_isEmpty(sqlist *const me);
Status List_insert(sqlist *const me, int i,int e);
int List_remove(sqlist *const me, int i);

sqlist *List_Create();
void List_Destroy(sqlist *const me);

#endif // SQLIST_H
