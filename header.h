/*
 * header.h
 *
 *  Created on: Dec 26, 2019
 *      Author: yavuz
 */

#ifndef HEADER_H_
#define HEADER_H_

#include<stdio.h>
#include<stdlib.h>

struct list {
	int val;
	struct list* next;
};
typedef struct list list_el;
typedef list_el* list_t;

list_t kreier_list();
list_t new_element(int);
void push(list_t*, int);
void free_list(list_t);

#endif /* HEADER_H_ */
