/*
 * listenaddition1.c
 *
 *  Created on: Dec 24, 2019
 *      Author: yavuz
 */

#include"header.h"
#include<time.h>

void push(list_t* head_ref, int val) {
	list_t new_element = malloc(sizeof(list_el));
	if (new_element == NULL) {
		printf("Speicher aus");
		exit(1);
	}
	new_element->val = val;
	new_element->next = (*head_ref);
	(*head_ref) = new_element;
}

void print_list(list_t liste) {
	list_t temp = liste;
	while (temp != NULL) {
		printf("%d", temp->val);
		temp = temp->next;
	}
	printf("\n");
}

list_t new_element(int val) {
	list_t element = malloc(sizeof(list_el));
	if (element == NULL) {
		printf("Speicher aus!\n");
		exit(1);
	}
	element->val = val;
	element->next = NULL;
	return element;
}

list_t add_lists(list_t liste1, list_t liste2) {
	list_t res = NULL;
	list_t temp, prev = NULL;

	int carry = 0, sum=0;
	while (liste1 != NULL || liste2 != NULL) {
		sum = carry + (liste1? liste1->val: 0) + (liste2? liste2->val: 0);
		carry = (sum >= 10)? 1: 0;
		sum = sum % 10;
		temp = new_element(sum);
		if (res == NULL) {
			res = temp;
		} else {
			prev->next = temp;
		}
		prev = temp;

		if (liste1)
			liste1 = liste1->next;
		if (liste2)
			liste2 = liste2->next;
	}
	if (carry > 0) {
		temp->next = new_element(carry);
	}
	return res;
}

unsigned int length(list_t p) {
	int counter = 0;
	while (p != NULL) {
		counter++;
		p = p->next;
	}
	return counter;
}

list_t append(list_t p, int x) {
	list_t element = malloc(sizeof(list_el));
	if (element == NULL) {
		printf("Speicher aus!\n");
		exit(1);
	}
	element->val = x;
	element->next = p;
	return element;
}

int main() {
	srand(time(0));

	list_t list_array[10];
	for (int i = 0; i < 10; i++) {
		list_array[i] = kreier_list();
		printf("Liste %d: ", i);
		print_list(list_array[i]);
		// printf("Length: %d\n", length(list_array[i]));
	}
	list_t res = NULL;
	int index1 = 3, index2 = 4;
	res = add_lists(list_array[index1], list_array[index2]);
	printf("List %d + List %d: ", index1, index2);
	print_list(res);

	print_list(append(list_array[0], 9));

	for (int i = 0; i < 10; i++) {
		free_list(list_array[i]);
	}
	return 0;
}
