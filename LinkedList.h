#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

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
	//void del(node *n);
	void del(int);
	unsigned int count() const;
};

#endif __LINKEDLIST_H__