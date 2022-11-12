/*#include <stdio.h>*/

#include "shlang.h"

#define QUEUE_SIZE 10

int main() {





	int x;
	shlang_queue_t *q;
	shlang_recv_t *r;
	m = 5;

	q = shlang_init(QUEUE_SIZE, sizeof(int));
	r = shlang_follow(q);

	for (x = 0; x < 10; x++) {
		shlang_trans(q, &x);
	}

	for (x = 0; x < 10; x++) {
		/*int data = *(int*) */shlang_get(r);
		/*printf("ptr: %zu data: %d\n", r->ptr, data);*/
	}

	for (x = 0; x < 10; x++) {
		shlang_trans(q, &x);
	}

	for (x = 0; x < 10; x++) {
		/*int data = *(int*) */shlang_get(r);
		/*printf("ptr: %zu data: %d\n", r->ptr, data);*/
	}

	shlang_free(q);

	return 0;
}
