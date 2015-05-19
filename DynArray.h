#ifndef __DYNARRAY_H__
#define __DYNARRAY_H__

#include <assert.h> 

#define DYN_ARRAY_BLOCK_SIZE 16

template <class TYPE>
class DynArray {

private:

	TYPE *data;
	unsigned int allocated_memory;
	unsigned int num_elements;

	void reallocate(unsigned int new_mem_size)
	{
		TYPE *tmp = data;

		allocated_memory = new_mem_size;
		data = new TYPE[allocated_memory];

		if (num_elements > allocated_memory)
			num_elements = allocated_memory;

		if (tmp != NULL)
		{
			for (unsigned int i = 0; i < num_elements; i++)
				data[i] = tmp[i];

			delete[] tmp;
		}
	}

public:

	// Constructors
	DynArray<TYPE>() : data(NULL), allocated_memory(0), num_elements(0)
	{
		reallocate(DYN_ARRAY_BLOCK_SIZE);
	}

	DynArray<TYPE>(unsigned int new_memory_size) : data(NULL), num_elements(0)
	{
		reallocate(new_memory_size);
	}

	DynArray<TYPE>(const DynArray &array) : data(NULL), allocated_memory(0), num_elements(0)
	{
		reallocate(array.allocated_memory);
		for (unsigned int i = 0; i < array.num_elements; i++)
			pushBack(array.data[i]);
	}


	~DynArray<TYPE>()
	{
		delete[] data;
	}

	void pushBack(TYPE new_value)
	{
		if (num_elements == allocated_memory)
			reallocate(allocated_memory + 1);

		data[num_elements] = new_value;
		num_elements++;
	}

	bool pop(TYPE &value)
	{
		// When the element is deleted, it is necessary to return a copy of that element.
		if (data != NULL && num_elements > 0)
		{
			value = data[--num_elements];					
			return true;
		}
		return false;
	}

	bool insert(int new_value, unsigned int position)
	{
		if (position <= num_elements)
		{
			TYPE *tmp = new TYPE[allocated_memory];
			for (unsigned int i = 0; i < num_elements; i++)
			{
				tmp[i] = data[i];
			}
			
			if (num_elements == allocated_memory)
				reallocate(allocated_memory + 1);
			
			for (unsigned int i = 0; i < position; i++)
			{
				data[i] = tmp[i];
			}
			data[position] = new_value;
			for (unsigned int i = position; i < num_elements; i++)
			{
				data[i + 1] = tmp[i];
			}
			num_elements++;
			delete[] tmp;
			return true;
		}
		return false;
	}

	bool clear()
	{
		if (data != NULL)
		{
			num_elements = 0;
			return true;
		}
		return false;
	}

	void flip()
	{
		unsigned int loops = num_elements / 2;
		for (unsigned int i = 0; i < loops; i++)
			swap(data[i], data[num_elements - (1 + i)]);
	}

	// Auxiliar method useful to represent all the information.
	// It won't have its correspoding Unittest test. 
	void info() const
	{
		for (int i = 0; i < num_elements; i++)
		{
			printf("%s %d => %d\n", "Position", i, data[i]);
		}
		printf("%s: %d\n", "Number of elements", num_elements);
		printf("%s: %d\n\n", "Allocated memory", allocated_memory);
	}
	
	TYPE& operator[] (unsigned int index)
	{
		// For p[1] = 15;
		assert (index < num_elements);
		return data[index];
	}
		
	const TYPE& operator[] (unsigned int index) const
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
