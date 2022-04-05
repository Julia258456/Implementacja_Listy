#pragma once
#include "node.h"
//#include <exception>
#include <string>

template<class T>
class List
{
public:
	List();
	List(const List& otherList);
	~List();
	void push_front(T value);
	void push_back(T value);
	void erase(Node<T>* value_ptr);
	void pop_front();
	void pop_back();
	void print();
	void swapElements(Node<T>* value1_ptr, Node<T>* value2_ptr);
	void insert(T value, int index);

	Node<T>* operator[](int index) const;
	List<T>& operator=(const List<T>& otherList);
	bool operator==(const List<T>& otherList);
	friend std::ostream& operator<<(std::ostream& stream, const List<T>& list);
	friend std::istream& operator>>(std::istream& stream, const List<T>& list);

	int indexOf(T& val);
	void moveToFront(int index);
	Node<T>* getHead();
	Node<T>* getTail();
	int getSize();

private:
	int size;
	Node<T>* head, * tail;
};

template<class T>
List<T>::List() {
	size = 0;
	head = tail = nullptr;
}

template<class T>
List<T>::List(const List& otherList)
{
	for (int i = 0; i < otherList.size; i++) {
		push_back(otherList[i]->value);
	}
}

template<class T>
List<T>::~List() {
	while (size) {
		pop_back();
	}
}

template<class T>
void List<T>::push_back(T value)
{
	Node<T>* node = new Node<T>(value);

	node->next = nullptr;
	node->prev = tail;
	tail = node;

	if (node->prev) {
		node->prev->next = node;
	}
	else {
		head = node;
	}

	size++;
}

template<class T>
void List<T>::push_front(T value)
{
	Node<T>* node = new Node<T>(value);

	node->prev = nullptr;
	node->next = head;
	head = node;

	if (node->next) {
		node->next->prev = node;
	}
	else {
		tail = node;
	}

	size++;
}

template<class T>
void List<T>::erase(Node<T>* value_ptr)
{

	if (size <= 0) {
		throw std::exception("Brak elementow ktore mozna usuwac.");
	}

	if (value_ptr->next && value_ptr->prev) {
		size--;
		delete value_ptr;

		return;
	}

	if (value_ptr->next != nullptr) {
		value_ptr->next->prev = value_ptr->prev;
	}
	else {
		tail = value_ptr->prev;
	}

	if (value_ptr->prev != nullptr) {
		value_ptr->prev->next = value_ptr->next;
	}
	else {
		head = value_ptr->next;
	}

	delete value_ptr;
	size--;
}

template<class T>
void List<T>::pop_back()
{
	if (size > 0) {
		erase(tail);
	}
	else {
		throw std::exception("Lista jest pusta.");
	}
}

template<class T>
void List<T>::pop_front()
{
	if (size > 0) {
		erase(head);
	}
	else {
		throw std::exception("Lista jest pusta.");
	}
}

template<class T>
void List<T>::print()
{
	Node<T>* tmp = head;
	std::cout << "Liczba elementow listy: " << size << std::endl;

		for (int i = 0; i < size; i++) {
			std::cout << tmp->value << std::endl;
			tmp = tmp->next;
		}
}

template<class T>
void List<T>::swapElements(Node<T>* value1_ptr, Node<T>* value2_ptr)
{
	if (size < 2 || value1_ptr == value2_ptr) {
		throw std::exception("Zamiana jest niemozliwa.");
	}

	Node<T>* tmp;


	// Sprawdzenie czy te elementy sa na poczatku lub koncu
	if ((value1_ptr == head && value2_ptr == tail) || (value1_ptr == tail && value2_ptr == head)) {
		tmp = head;
		head = tail;
		tail = tmp;
	}
	else if (value1_ptr == head) {
		head = value2_ptr;
	}
	else if (value1_ptr == tail) {
		tail = value2_ptr;
	}
	else if (value2_ptr == head) {
		head = value1_ptr;
	}
	else if (value2_ptr == tail) {
		tail = value1_ptr;
	}

	// Zmiana kolejnosci elementow jesli byly podane nie po kolei
	if (value2_ptr->next == value1_ptr) {
		tmp = value1_ptr;
		value1_ptr = value2_ptr;
		value2_ptr = tmp;
	}

	Node<T>* tmp1 = value1_ptr->prev;
	Node<T>* tmp2 = value2_ptr->prev;
	Node<T>* tmp3 = value1_ptr->next;
	Node<T>* tmp4 = value2_ptr->next;

	// Sprawdzenie czy s¹ obok siebie
	if ((value1_ptr->next == value2_ptr && value2_ptr->prev == value1_ptr)
		|| value1_ptr->prev == value2_ptr && value2_ptr->next == value1_ptr) {
		value1_ptr->prev = tmp3;
		value2_ptr->prev = tmp1;
		value1_ptr->next = tmp4;
		value2_ptr->next = tmp2;
	}
	else {
		value1_ptr->prev = tmp2;
		value2_ptr->prev = tmp1;
		value1_ptr->next = tmp4;
		value2_ptr->next = tmp3;
	}

	if (value1_ptr->prev != nullptr) {
		value1_ptr->prev->next = value1_ptr;
	}

	if (value1_ptr->next != nullptr) {
		value1_ptr->next->prev = value1_ptr;
	}

	if (value2_ptr->prev != nullptr) {
		value2_ptr->prev->next = value2_ptr;
	}

	if (value2_ptr->next != nullptr) {
		value2_ptr->next->prev = value2_ptr;
	}
}

template <class T>
void List<T>::insert(T value, int index){

	if (index > size) {
		throw std::exception("Lista jest za krotka aby dodac element w tym miejscu.");
	}
	else if (index < 0) {
		throw std::exception("Wartosc powinna byæ nieujemna.");
	} 
	else if (index == 0) {
		push_front(value);
	}
	else if (index == size) {
		push_back(value);
	}
	else {

		Node<T>* node = new Node<T>(value);
		Node<T>* tmp;

		tmp = operator[](index - 1);
		node->prev = tmp;
		node->next = tmp->next;
		node->prev->next = node;
		node->next->prev = node;

		size++;

	}
}

template<class T>
Node<T>* List<T>::operator[](int index) const
{
	if (size == 0) {
		throw std::exception("Lista jest pusta.");
	}
	else if (index < 0) {
		throw std::exception("Wartosc powinna byæ nieujemna.");
	}
	else if (index > (size - 1)) {
		throw std::exception("Obiekt o takim indeksie nie istnieje.");
	}
	else if (size > index) {
		Node<T>* tmp = head;
		int num = 0;

		while (tmp) {
			if (index == num) {
				return tmp;
			}

			num++;
			tmp = tmp->next;
		}
	}
}

template<class T>
List<T>& List<T>::operator=(const List<T>& otherList)
{
	if (&otherList == this) {
		return *this;
	}

	while (size) {
		pop_back();
	}
	head = tail = nullptr;
	size = 0;

	for (int i = 0; i < otherList.size; i++) {
		push_back(otherList[i]->value);
	}

	return *this;
}

template<class T>
bool List<T>::operator==(const List<T>& otherList)
{
	if (size != otherList.size) {
		return false;
	}

	for (int i = 0; i < otherList.size; i++) {
		if (!(otherList[i]->value == operator[](i)->value)) {
			return false;
		}
	}

	return true;
}

template<class T>
std::ostream& operator<<(std::ostream& stream, List<T>& list)
{
	for (int i = 0; i < list.getSize(); i++) {
		stream << list[i]->value;
		if (i + 1 < list.getSize()) {
			stream << std::endl;
		}
	}
	if (list.getSize() > 0) {
		stream << std::endl;
	}

	return stream;
}

template<class T>
std::istream& operator>>(std::istream& stream, List<T>& list)
{
	T tmp;

	while (stream >> tmp) {
		list.push_back(tmp);
	}

	return stream;
}

template<class T>
int List<T>::indexOf(T& val)
{
	if (size == 0) {
		throw "Lista jest pusta.";
	}

	Node<T>* currentNode = head;
	int index = 0;

	while (currentNode) {
		if (val == currentNode->value) {
			return index;
		}

		index++;
		currentNode = currentNode->next;
	}

	if (index == size) {
		throw "Obiekt o takim indeksie nie istnieje.";
	}

	return -1;
}

template<class T>
void List<T>::moveToFront(int index)
{
	if (size == 0) {
		throw std::exception("Lista jest pusta.");
	}
	else if (index == 0) {
		throw std::exception("Ten obiekt jest juz na poczatku listy.");
	}
	else if (index < 0) {
		throw std::exception("Wartosc powinna byæ nieujemna.");
	}
	else if (index > (size - 1)) {
		throw std::exception("Obiekt o takim indeksie nie istnieje.");
	}
	else {
		Node<T>* tmp;
		tmp = operator[](index); 

		if (tmp == tail) {
			tail = tmp->prev;
			tmp->prev->next = nullptr;
			tmp->prev = nullptr;
			tmp->next = operator[](0);
			tmp->next->prev = tmp;
			head = tmp;
		}
		else{
			tmp->next->prev = tmp->prev;
			tmp->prev->next = tmp->next;
			tmp->prev = nullptr;
			tmp->next = operator[](0);
			tmp->next->prev = tmp;
			head = tmp;
		}
	}
}

template<class T>
Node<T>* List<T>::getHead()
{
	return head;
}

template<class T>
Node<T>* List<T>::getTail()
{
	return tail;
}

template<class T>
int List<T>::getSize()
{
	return size;
}