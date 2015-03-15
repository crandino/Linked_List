#ifndef __DYNARRAY_H__
#define __DYNARRAY_H__

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
			delete data;
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
		if (data != NULL)
		{
			num_elements--;
			TYPE element_to_return = data[num_elements];
			if (num_elements == 0)
				data = NULL;
						
			return element_to_return;
		}
		return -1;
	}


	void Insert(int value, unsigned int position);
	int& operator[] (unsigned int index); // Este operador tiene un dilema con el const. p[1] = 15 no puede ser const. printf("%d", p[1]) puede serlo.
	const int& operator[] (unsigned int index) const;

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
