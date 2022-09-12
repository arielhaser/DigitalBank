#include "List.h"

//////////////////////// List Class //////////////////

List::Link* List::includes(int c) const
{
	// loop to test each element
	for (Link* p = last; p != NULL; p = p->next)
		if (c == p->value->number)
			return p;
	// not found
	return NULL;
}

List::Link* List::prevLink(int code) const // check if vaule is in the list
{
	if (code == lastElement()->code)
		return last;
	// loop to test each element
	for (Link* p = last; p != NULL; p = p->next)
		if (code == p->next->value->code)
			return p;
	// not found
	return NULL;
}

List::Link::Link(Account* val, Link* nxt) : //add link
	value(val), next(nxt) {}

List::Link::Link(const Link& source) : //copy link
	value(source.value), next(source.next) {}

List::Link::~Link() {
	delete value;
}

List::List() : last(NULL) {} // creat list

List::List(const List& l) // copy list
{
	Link* src, * trg;
	if (l.last == NULL)
		last = NULL;
	else
	{
		last = new Link((l.last)->value, NULL);
		src = l.last;
		trg = last;
		while (src->next != NULL)
		{
			trg->next = new Link((src->next)->value, NULL);
			src = src->next;
			trg = trg->next;
		}
	}
}

List::~List() // list destractor
{
	clear();
}

void List::clear() // empty all elements from the List
{
	Link* next;
	for (Link* p = last; p != NULL; p = next)
	{
		// delete the element pointed to by p
		next = p->next;
		delete p;
	}
	// mark that the List contains no elements
	last = NULL;
}

bool List::isEmpty() const // ask if list is empty
{
	return last == NULL;
}

void List::add(Account* val) // start the creation of the link
{
	last = new Link(val, last);
}

Account* List::lastElement() const // return the last value that entered
{
	// return last value in List
	if (isEmpty()) {
		expout ex;
		ex.reason = "\tthe List is empty, no last Element";
		throw ex;
	}
	return last->value;
}

void List::removeLast() // remove the last value that entered
{
	// make sure there is a last element
	if (isEmpty()) {
		expout ex;
		ex.reason = "\tthe List is empty, no Elements to move";
		throw ex;
	}
	// save pointer to the removed node
	Link* p = last;
	// reassign the last node
	last = p->next;
	// recover memory used by the last element
	delete p;
	cout << "\tAccount has been deleted" << endl;
}

void List::removeSelected(Link* p) {
	if (p == last)
		removeLast();
	else {
		Link* tmp = p->next;
		p->next = p->next->next;
		delete tmp;
		cout << "\tAccount has been deleted" << endl;
	}
}