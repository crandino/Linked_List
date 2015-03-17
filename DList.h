#ifndef __DLIST_H__
#define __DLIST_H__

template <class TYPE>
struct doubleNode {
	TYPE value;
	doubleNode<TYPE>* next;
	doubleNode<TYPE>* previous;
};

template <class TYPE>
class DList {

private:
	doubleNode<TYPE>* start;

public:
	DList()
	{
		start = NULL;
	}

	unsigned int count() const
	{
		unsigned int counter = 0;
		doubleNode<TYPE>* tmp = start;
		while (tmp != NULL)
		{
			tmp = tmp->next;
			counter++;
		}
		return counter;
	}

	void add(TYPE _value)
	{
		doubleNode<TYPE>* new_node = new doubleNode<TYPE>;
		new_node->value = _value;
		new_node->next = NULL;

		if (start != NULL)
		{
			doubleNode<TYPE>* tmp = start;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new_node;
			new_node->previous = tmp;
		}
		else
		{
			new_node->previous = NULL;
			start = new_node;
		}
	}

	doubleNode<TYPE>* getNodeAtPos(unsigned int _pos) const
	{
		// Node 1 is zero, node 2 is one, etc.
		if (start != NULL && _pos < count())
		{
			unsigned int pos_counter = 0;
			doubleNode<TYPE>* tmp = start;
			
			while (pos_counter != _pos)
			{
				tmp = tmp->next;
				pos_counter++;
			}
			return tmp;
		}
		return NULL;
	}

	bool del(doubleNode<TYPE>* _node)
	{
		if (start != NULL && _node != NULL)
		{
			if (start != _node)
			{
				doubleNode<TYPE>* tmp = start;
				while (tmp->next != _node)
					tmp = tmp->next;
				tmp->next = _node->next;
				if (_node->next != NULL)
					_node->next->previous = tmp;
			}
			else
			{
				if (_node->next != NULL)
				{
					start = _node->next;
					_node->next->previous = NULL;
				}
				else
					start = NULL;
			}
			delete _node;
			return true;
		}
		return false;
	}

	bool delAll() {

		if (start != NULL)
		{
			while (start->next != NULL)
			{
				doubleNode<TYPE>* node_to_delete = start;
				start = start->next;
				delete node_to_delete;
			}
			start = NULL;
			return true;
		}
		return false;
	}

	void info() const
	{
		if (start != NULL) {
			doubleNode<TYPE>* tmp = start;
			unsigned int node_num = 1;
			while (tmp != NULL)
			{
				printf("%s %d: %s %d | %s %p | %s %p | %s %p\n",
					    "Number", node_num,
						"Value", tmp->value,
						"Node", tmp,
						"Next", tmp->next,
						"Previous", tmp->previous);
				tmp = tmp->next;
				node_num++;
			}	
			printf("%s\n", "--------------------------------");
		}
		else
			printf("%s\n", "Empty Double Linked List");
	}

};


#endif // !__DLIST_H__
