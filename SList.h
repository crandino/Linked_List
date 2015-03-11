#ifndef __SLIST_H__
#define __SLIST_H__

/* Modificar la clase para que acepte int, float, double, punteros a lo que sea...
   Para casa:
   - Hacer otra lista, donde el nodo tendrá dos punteros, apuntando hacia delante 
   y hacia atrás. El primero hacia atrás apuntará a NULL, al igual que el último 
   hacia delante. Repetir todos los métodos: add y delete se verán modificados bastante.
 */

struct node {
	int value;
	node* next;
	node* previous;
};

class SList {

private:
	node* start;

public:

	SList() {
		start = NULL;
	}

	unsigned int count() const {
		unsigned int counter = 0;
		node* tmp = start;
		while (tmp != NULL) {
			tmp = tmp->next;
			counter++;
		}
		return counter;
	}

	void add(int _value) {
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

	node* getNodeAtPos(unsigned int _pos) const
	{
		// Node 1 is zero, node 2 is one, etc.
		if (start != NULL && _pos < count())
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

	void del(node *_node) {

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

	void delAll() {

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
	
};

#endif __SLIST_H__