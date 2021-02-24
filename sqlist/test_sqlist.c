#include "./sqlist.h"
#include <stdio.h>
#include <stdlib.h>

#define FAIL(str) printf("Test Failed!!!\n%s\n", #str)
#define SUCCESS(str) printf("Test Succeeded!!!\n%s\n", #str)

void test_create(sqlist *l);
void test_getLength(sqlist *l);
void test_insert(sqlist *l);

int main()
{
	/* test normal sqlist */
	sqlist *mylist;
	mylist = List_Create();
	test_create(mylist);	/* test whether being created successfully */
	test_getLength(mylist); /* test length */
	test_insert(mylist);	/* test inserting */
	test_remove(mylist);	/* test remove */
	return 0;
}

void test_create(sqlist *l)
{
	if (l == NULL)
		FAIL(unable to initialize a sequnce list !!!);
	else
		SUCCESS(create Sqlist);
}

void test_getLength(sqlist *l)
{
	/* test 1: Empty */
	if (l->getLength(l))
		FAIL(the initialized Sqlist is not empty);
	else if (!l->isEmpty(l))
	{
		FAIL(the isEmpty function does not give the right outcome);
	}
	else
		SUCCESS(test getLength);
}

void test_insert(sqlist *l)
{
	for (int i = 0; i < MAXSIZE + 2; i++)
	{
		if (l->insert(l, i + 1, i) == OK)
			continue;
		else
		{
			FAIL(insert malfunction);
			return;
		}
	}
	SUCCESS(test insert);
}

void test_remove(sqlist *l)
{
	int ret;
	int init_len = l->getLength(l);
	for (int i = 1; i <= l->length; i++)
	{
		ret = l->remove(l, l->length);
		if (ret != init_len - i)
		{
			FAIL(return value fail !!!);
			return;
		}
		else if (l->getLength(l) != init_len - i)
		{
			FAIL(length failed !!!);
			return;
		}
	}
	SUCCESS(remove succeeded !!!);
}