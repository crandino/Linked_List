#include <stdio.h>
#include "LinkedList.h"

SList::SList() {
	start = NULL;
}

unsigned int SList::count() const {
	unsigned int counter = 0;
	node* tmp = start;
	while (tmp != NULL) {
		tmp = tmp->next;
		counter++;
	}
	return counter;
}

void SList::add(int _value) {
	// A new node is being created.
	node *new_node = new node;
	new_node->value = _value;
	new_node->next = NULL;
	// Once done, has to be added to the list.
	if (start != NULL) {
		node *tmp = start;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
	}
	else
		start = new_node;
}

//void SList::del(node *_node) {
void SList::del(int _value) {
	
	if (start != NULL) 
		{
		node *tmp = start;
		if (tmp->value != _value)
		{
			while (tmp->next->value != _value)
				tmp = tmp->next;
			tmp->next = tmp->next->next;

		}
		else 
		{
			start = tmp->next;
			delete tmp;
		}
	}
}