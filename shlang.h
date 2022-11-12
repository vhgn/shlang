/**
 * Multi-Queue system in C
 * Copyright (C) 2022 Vahagn @ https://github.com/vhgn
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>
 *
 * @file shlang.h
 *
 * @author Vahagn @ https://github.com/vhgn
 * @date 2022-11-06
 */

#ifndef SHLANG_HEADER
#define SHLANG_HEADER

#include <stdlib.h>

typedef struct shlang_queue shlang_queue_t;
typedef struct shlang_recv shlang_recv_t;

struct shlang_queue {
	size_t ptr;
	shlang_recv_t *min;
	shlang_recv_t *max;

	void *arr;
	size_t len;
	size_t type;
};

struct shlang_recv {
	size_t ptr;
	shlang_recv_t *next;
	shlang_queue_t *queue;
};

/**
 * Initialize queue with given size (count of elements) and type size
 */
shlang_queue_t *shlang_init(size_t len, size_t type);

/**
 * Follow the queue, get a receiver with unique pointer
 */
shlang_recv_t *shlang_follow(shlang_queue_t *queue);

/**
 * Get the next element
 *
 * Returns pointer if exists
 * Returns 0 if queue is empty
 */
void *shlang_get(shlang_recv_t *recv);

/**
 * Transmit data with size specified earlier
 *
 * Returns 1 if queue is full
 * Returns 0 otherwise
 */
int shlang_trans(shlang_queue_t *q, void *data);

#endif /* SHLANG_HEADER */
