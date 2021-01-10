#include<stdio.h>
#include<stdlib.h>

typedef unsigned short uint16_t;

struct PageInfo {
	// Next page on the free list.
	struct PageInfo* pp_link;

	// pp_ref is the count of pointers (usually in page table entries)
	// to this page, for pages allocated using page_alloc.
	// Pages allocated at boot time using pmap.c's
	// boot_alloc do not have valid reference count fields.

	uint16_t pp_ref;
};


void main()
{
	struct PageInfo arr_pi[100] = { 0 };
	struct PageInfo* i = &arr_pi[5] - arr_pi;
	printf("%d", i);

	struct PageInfo *p_pi = (struct PageInfo*)malloc(100*sizeof(struct PageInfo));
	struct PageInfo* i1 = (p_pi+9) - p_pi;
	printf("%d", i1);
}