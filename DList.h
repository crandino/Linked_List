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

	void add(TYPE new_value)
	{
		doubleNode<TYPE>* new_node = new doubleNode<TYPE>;
		new_node->value = new_value;
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

	doubleNode<TYPE>* getNodeAtPos(unsigned int position) const
	{
		// Node 1 is zero, node 2 is one, etc.
		if (start != NULL && position < count())
		{
			unsigned int pos_counter = 0;
			doubleNode<TYPE>* tmp = start;
			
			while (pos_counter != position)
			{
				tmp = tmp->next;
				pos_counter++;
			}
			return tmp;
		}
		return NULL;
	}

	bool del(doubleNode<TYPE>* node_to_erase)
	{
		if (start != NULL && node_to_erase != NULL)
		{
			if (start != node_to_erase)
			{
				doubleNode<TYPE>* tmp = start;
				while (tmp->next != node_to_erase)
				{
					tmp = tmp->next;
					//We check if the node is not in the list at all.
					if (tmp->next == NULL)
						return false;
				}
				tmp->next = node_to_erase->next;
				if (node_to_erase->next != NULL)
					node_to_erase->next->previous = tmp;
			}
			else
			{
				if (start->next == NULL)
				{
					start = NULL;
				}
				else
				{
					start = start->next;
					start->previous = NULL;
				}

			}
			delete node_to_erase;
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

	doubleNode<TYPE>* getFirst() const 
	{
		return start;
	}

	doubleNode<TYPE>* getLast() const
	{
		if (start != NULL)
		{
			doubleNode<TYPE>* tmp = start;
			while (tmp->next != NULL)
				tmp = tmp->next;
			return tmp;
		}
		return NULL;
	}

	void info() const
	{
		if (start != NULL) {
			doubleNode<TYPE>* tmp = start;
			unsigned int node_num = 1;
			while (tmp != NULL)
			{
				printf("%s %d : %s %f | ", "Number", node_num, "Value", tmp->value);
				printf("%s %p | %s %p | %s %p\n", "Node", tmp, "Next", tmp->next, "Previous", tmp->previous);
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
