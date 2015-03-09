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
	void del(const node *n);
	unsigned int count() const;
	const node* getNodeAtPos(int _pos) const;
};

#endif __LINKEDLIST_H__