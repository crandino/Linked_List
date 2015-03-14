#ifndef __DYNARRAY_H__
#define __DYNARRAY_H__

class DynArray {

private:

	int *data;
	unsigned int allocated_memory;
	unsigned int num_elements;

public:

	DynArray() : data(NULL), allocated_memory(0), num_elements(0) {}
	DynArray(unsigned int _new_memory_size) : data(NULL), num_elements(0) {
		reallocate(_new_memory_size);
	}

	~DynArray() { if (data != NULL) delete[] data; }

	void reallocate (unsigned int _new_mem_size);
	void pushBack (int value);
	int pop(); // Al borrar l'element, has de tornar una còpia. No ho pots fer de cap altra manera;
	void Insert(int value, unsigned int position);
	int& operator[] (unsigned int index); // Este operador tiene un dilema con el const. p[1] = 15 no puede ser const. printf("%d", p[1]) puede serlo.
	const int& operator[] (unsigned int index) const;
	
};


#endif // !__DYNARRAY_H__
