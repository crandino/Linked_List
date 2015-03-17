#ifndef __DYNARRAY_H__
#define __DYNARRAY_H__

#include <assert.h> 
#include "Utilities.h"

template <class TYPE>
class DynArray {

private:

	TYPE *data;
	unsigned int allocated_memory;
	unsigned int num_elements;

	void reallocate(unsigned int _new_mem_size)
	{
		if (data != NULL)
		{
			TYPE *tmp = new TYPE[allocated_memory];
			for (unsigned int i = 0; i < num_elements; i++)
			{
				tmp[i] = data[i];
			}
			delete[] data;
			allocated_memory = _new_mem_size;
			data = new TYPE[allocated_memory];
			for (unsigned int i = 0; i < num_elements; i++)
			{
				data[i] = tmp[i];
			}
		}
		else
		{
			delete[] data;
			allocated_memory = _new_mem_size;
			data = new TYPE[allocated_memory];
		}
	}

public:

	DynArray<TYPE>() : data(NULL), allocated_memory(0), num_elements(0) {}
	DynArray<TYPE>(unsigned int _new_memory_size) : data(NULL), num_elements(0) {
		reallocate(_new_memory_size);
	}

	~DynArray<TYPE>() { if (data != NULL) delete[] data; }

	void pushBack(TYPE _value)
	{
		if (num_elements == allocated_memory)
			reallocate(allocated_memory + 1);

		data[num_elements] = _value;
		num_elements++;
	}

	TYPE pop()
	{
		// When the element is deleted, it is necessary to return a copy of that element.
		// Cuidado con num_elements, que no sea cero y le restemos uno más.
		if (data != NULL)
		{
			num_elements--;
			TYPE element_to_return = data[num_elements];
			/*if (num_elements == 0)
				data = NULL;*/						
			return element_to_return;
		}
		return -1;
	}

	bool insert(int _value, unsigned int _position)
	{
		if (_position <= num_elements)
		{
			TYPE *tmp = new TYPE[allocated_memory];
			for (unsigned int i = 0; i < num_elements; i++)
			{
				tmp[i] = data[i];
			}
			
			if (num_elements == allocated_memory)
				reallocate(allocated_memory + 1);
			
			for (unsigned int i = 0; i < _position; i++)
			{
				data[i] = tmp[i];
			}
			data[_position] = _value;
			for (unsigned int i = _position; i < num_elements; i++)
			{
				data[i + 1] = tmp[i];
			}
			num_elements++;
			return true;
		}
		return false;
	}

	void info() const
	{
		for (int i = 0; i < num_elements; i++)
		{
			printf("%s %d => %d\n", "Position", i, data[i]);
		}
		printf("%s: %d\n", "Number of elements", num_elements);
		printf("%s: %d\n\n", "Allocated memory", allocated_memory);
	}
	
	int& operator[] (unsigned int index)
	{
		// For p[1] = 15;
		assert (index < num_elements);
		return data[index];
	}
		
	const int& operator[] (unsigned int index) const
	{
		// For printf("%d", p[1]);
		assert (index < num_elements);
		return data[index];
	}

	unsigned int getMemory() const
	{
		return allocated_memory;
	}

	unsigned int getNumElements() const
	{
		return num_elements;
	}
};


#endif // !__DYNARRAY_H__
