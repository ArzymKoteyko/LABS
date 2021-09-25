#include <iostream>
#include "queue.h"

using namespace std;

Queue::Queue() {
	queue_head.value = 0;
	queue_head.ptr_next = &queue_head;
	queue_head.ptr_back = &queue_head;
}


void Queue::append_start (int new_value) {
	queue_element *ptr = new queue_element;
	ptr -> value = new_value;

	ptr -> ptr_back = &queue_head;	
	queue_head.ptr_next -> ptr_back = ptr;

	ptr -> ptr_next = queue_head.ptr_next;
	queue_head.ptr_next = ptr;

	queue_head.value++;
}
int Queue::pop_start() {
	int res_value = queue_head.ptr_next -> value;
	queue_element *ptr = queue_head.ptr_next;
	
	queue_head.ptr_next -> ptr_next -> ptr_back = &queue_head;
	queue_head.ptr_next = queue_head.ptr_next -> ptr_next;
	queue_head.value--;	
	delete ptr;
	return res_value;
}
void Queue::append_back (int new_value) {
	queue_element *ptr = new queue_element;
	ptr -> value = new_value;

	ptr -> ptr_next = &queue_head;
	queue_head.ptr_back -> ptr_next = ptr;

	ptr -> ptr_back = queue_head.ptr_back;
	queue_head.ptr_back = ptr;

	queue_head.value++;
}
int Queue::pop_back () {
	int res_value = queue_head.ptr_back -> value;
	queue_element *ptr = queue_head.ptr_back;

	queue_head.ptr_back -> ptr_back -> ptr_next = &queue_head;
	queue_head.ptr_back = queue_head.ptr_back -> ptr_back;
	queue_head.value--;
	delete ptr;
	return res_value;
}


void Queue::say_size() {
	cout << "Queue size: " << queue_head.value << "\n";
}
void Queue::say_queue () {
	
	queue_element* start = &queue_head;
	queue_element* ptr = queue_head.ptr_next;
	cout << "Queue elemnts: ";
	while (ptr != start) {
		cout << ptr -> value << " ";
		ptr = ptr -> ptr_next;
	}
	cout << "\n";
}
