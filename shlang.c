#include <string.h>

#include "shlang.h"

shlang_queue_t *shlang_init(size_t len, size_t type) {
	shlang_queue_t *queue;

	queue = (shlang_queue_t *) malloc(sizeof(shlang_queue_t));

	queue->arr = malloc(len * type);
	queue->len = len;
	queue->type = type;
	queue->min = NULL;
	queue->max = NULL;
	queue->ptr = 0;

	return queue;
}

shlang_recv_t *shlang_follow(shlang_queue_t *queue) {
	shlang_recv_t *recv;

	recv = (shlang_recv_t *) malloc(sizeof(shlang_recv_t));
	recv->ptr = queue->ptr;
	recv->queue = queue;

	if (queue->max)
		queue->max->next = recv;

	queue->max = recv;
	recv->next = NULL;

	if (queue->min == NULL) {
		queue->min = recv;
	}

	return recv;
}

void *shlang_get(shlang_recv_t *recv) {
	void *temp, *queue_data, *copied_data;

	if (recv->ptr == recv->queue->ptr)
		return 0;

	queue_data = ((char *) recv->queue->arr) + recv->ptr++ * recv->queue->type;
	copied_data = malloc(recv->queue->type);
	memcpy(copied_data, queue_data, recv->queue->type);

	if (recv->ptr >= recv->queue->len) {
		recv->ptr = 0;
	}

	if (recv->ptr > recv->queue->min->ptr) {
		temp = recv->next;
		recv->next = recv->queue->min;

		recv->queue->min->next = temp;
		recv->queue->min = recv;
	}

	return copied_data;
}

int shlang_trans(shlang_queue_t *queue, void *data) {
	void *dest = ((char *) queue->arr) + queue->ptr * queue->type;

	memcpy(dest, data, queue->type);

	queue->ptr++;
	if (queue->ptr >= queue->len)
		queue->ptr = 0;

	return queue->min && queue->min->ptr != queue->ptr;
}
