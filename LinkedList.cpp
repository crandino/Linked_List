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

node* SList::getNodeAtPos(int _pos) const
{
	// Node 1 is zero, node 2 is one, etc.
	if (start != NULL && _pos >= 0 && _pos < count())
	{
		node* tmp = start;
		int pos_counter = 0;
		while (pos_counter != _pos)
		{
			tmp = tmp->next;
			pos_counter++;
		}
		return tmp;
	}
	else
		return NULL;
}

void SList::del(node *_node) {

	// Si el nodo no existe, petará.
	// Puede mejorarse añadiendo un booleano que indique error o no.
	
	if (_node != NULL && start != NULL)
	{
		if (_node != start)
		{
			node *tmp = start;
			while (tmp->next != _node)
				tmp = tmp->next;
			tmp->next = _node->next;
		}
		else
			start = start->next;
		delete _node;
	}
}

void SList::delAll() {

	// Hacerla booleana. Este método lo podría llamar el destructor
	// de la clase.

	if (start != NULL)
	{
		while (start->next != NULL)
		{
			node* node_to_delete = start;
			start = start->next;
			delete node_to_delete;
		}
		delete start;
		start = NULL;
	}
}