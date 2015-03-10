#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

/* Modificar la clase para que acepte int, float, double, punteros a lo que sea...
   Para casa:
   - Hacer otra lista, donde el nodo tendrá dos punteros, apuntando hacia delante 
   y hacia atrás. El primero hacia atrás apuntará a NULL, al igual que el último 
   hacia delante. Repetir todos los métodos: add y delete se verán modificados bastante.
 */

struct node {
	int value;
	node* next;
};

class SList {

private:
	node* start;

public:
	SList();
	void add(int);
	unsigned int count() const;
	node* getNodeAtPos(int) const;
	void del(node*);
	void delAll();
	
};

#endif __LINKEDLIST_H__