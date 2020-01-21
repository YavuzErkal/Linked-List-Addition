/*
 * testprozedur.c
 *
 *  Created on: Dec 26, 2019
 *      Author: yavuz
 */

#include<stdio.h>
#include<stdlib.h>
#include"header.h"

list_t kreier_list() {
	list_t head = new_element(rand() % 10);
	for (int i = 0; i < rand() % 5; i++)
		push(&head, rand() % 10);
	return head;
}

void free_list(list_t liste) {
	list_t temp = liste;
	while (temp != NULL) {
		temp = temp->next;
		free(liste);
		liste = temp;
	}
}
