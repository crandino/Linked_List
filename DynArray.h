#ifndef __DYNARRAY_H__
#define __DYNARRAY_H__

template <class TYPE>
class DynArray {

public:

	TYPE *data;
	unsigned int allocated_memory;
	unsigned int num_elements;

	void reallocate(unsigned int _new_mem_size)
	{
		if (data != NULL && _new_mem_size >= num_elements)
		{

		}








		if (data != NULL)
		{
			DynArray<TYPE> *tmp = new DynArray<TYPE>[allocated_memory];
			for (unsigned int i = 0; i < num_elements; i++)
			{
				tmp[i] = data[i];
			}
			delete[] data;
			allocated_memory = _new_mem_size;
			DynArray<TYPE> *data = new DynArray<TYPE>[allocated_memory];
			for (unsigned int i = 0; i < num_elements; i++)
			{
				data[i] = tmp[i];
			}
		}
		else
		{
			delete[] data;
			allocated_memory = _new_mem_size;
			DynArray<TYPE> *data = new DynArray<TYPE>[allocated_memory];
			data = NULL;
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
		/*if (num_elements == allocated_memory)
			reallocate(allocated_memory + 1);*/

		if (data != NULL)
		{
			DynArray<TYPE> *tmp = new DynArray<TYPE>[allocated_memory -1];
			for (unsigned int i = 0; i < num_elements; i++)
			{
				tmp[i] = data[i];
			}
			delete[] data;
			DynArray<TYPE> *data = new DynArray<TYPE>[allocated_memory];
			for (unsigned int i = 0; i < num_elements; i++)
			{
				data[i] = tmp[i];
			}
			data[num_elements] = _value;
			num_elements++;
		}
		else {
			reallocate(allocated_memory + 1);
			data = &_value;
			num_elements++;
		}
	}

	int pop(); // Al borrar l'element, has de tornar una còpia. No ho pots fer de cap altra manera;
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
