#ifndef __SLIST_H__
#define __SLIST_H__

/* Modificar la clase para que acepte int, float, double, punteros a lo que sea... */

template <class TYPE1>
struct simpleNode {
	TYPE1 value;
	simpleNode<TYPE1>* next;
	simpleNode<TYPE1>* previous;
};

template <class TYPE1>
class SList {

private:
	simpleNode<TYPE1>* start;

public:

	SList() {
		start = NULL;
	}

	~SList() {
		delAll();
	}

	unsigned int count() const {
		unsigned int counter = 0;
		simpleNode<TYPE1>* tmp = start;
		while (tmp != NULL) {
			tmp = tmp->next;
			counter++;
		}
		return counter;
	}

	void add(TYPE1 _value) {
		// A new simpleNode is being created.
		simpleNode<TYPE1>* new_node = new simpleNode<TYPE1>;
		new_node->value = _value;
		new_node->next = NULL;
		// Once done, has to be added to the list.
		if (start != NULL) {
			simpleNode<TYPE1> *tmp = start;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new_node;
		}
		else
			start = new_node;
	}

	simpleNode<TYPE1>* getNodeAtPos(unsigned int _pos) const
	{
		// Node 1 is zero, node 2 is one, etc.
		if (start != NULL && _pos < count())
		{
			simpleNode<TYPE1>* tmp = start;
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

	bool del(simpleNode<TYPE1>* _node) {

		// Si el nodo no existe, petará.
		// Puede mejorarse añadiendo un booleano que indique error o no.

		if (_node != NULL && start != NULL)
		{
			if (_node != start)
			{
				simpleNode<TYPE1> *tmp = start;
				while (tmp->next != _node)
				{
					if (tmp->next == NULL)
						return false;
					tmp = tmp->next;
				}
				
				tmp->next = _node->next;
			}
			else
				start = start->next;
			delete _node;
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
				simpleNode<TYPE1>* node_to_delete = start;
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