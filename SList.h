#ifndef __SLIST_H__
#define __SLIST_H__

/* Modificar la clase para que acepte int, float, double, punteros a lo que sea... */

template <class TYPE>
struct simpleNode {
	TYPE value;
	simpleNode<TYPE>* next;
	simpleNode<TYPE>* previous;
};

template <class TYPE>
class SList {

private:
	simpleNode<TYPE>* start;

public:

	SList() {
		start = NULL;
	}

	~SList() {
		delAll();
	}

	unsigned int count() const {
		unsigned int counter = 0;
		simpleNode<TYPE>* tmp = start;
		while (tmp != NULL) {
			tmp = tmp->next;
			counter++;
		}
		return counter;
	}

	void add(TYPE new_value) {
		// A new simpleNode is being created.
		simpleNode<TYPE>* new_node = new simpleNode<TYPE>;
		new_node->value = new_value;
		new_node->next = NULL;
		// Once done, has to be added to the list.
		if (start != NULL) {
			simpleNode<TYPE> *tmp = start;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new_node;
		}
		else
			start = new_node;
	}

	simpleNode<TYPE>* getNodeAtPos(unsigned int position) const
	{
		// Node 1 is zero, node 2 is one, etc.
		if (start != NULL && position < count())
		{
			simpleNode<TYPE>* tmp = start;
			int pos_counter = 0;
			while (pos_counter != position)
			{
				tmp = tmp->next;
				pos_counter++;
			}
			return tmp;
		}
		else
			return NULL;
	}

	bool del(simpleNode<TYPE>* node_to_erase) {

		// Si el nodo no existe, petará.
		// Puede mejorarse añadiendo un booleano que indique error o no.

		if (node_to_erase != NULL && start != NULL)
		{
			if (node_to_erase != start)
			{
				simpleNode<TYPE> *tmp = start;
				while (tmp->next != node_to_erase)
				{
					if (tmp->next == NULL)
						return false;
					tmp = tmp->next;
				}
				
				tmp->next = node_to_erase->next;
			}
			else
				start = start->next;
			delete node_to_erase;
			return true;
		}
		return false;
	}

	bool delAll() {

		// Hacerla booleana. Este método lo podría llamar el destructor
		// de la clase.

		if (start != NULL)
		{
			while (start->next != NULL)
			{
				simpleNode<TYPE>* node_to_delete = start;
				start = start->next;
				delete node_to_delete;
			}
			delete start;
			start = NULL;
			return true;
		}
		return false;
	}
	
};

#endif __SLIST_H__