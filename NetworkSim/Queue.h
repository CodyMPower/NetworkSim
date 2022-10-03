#pragma once
#include <cstdlib>
#include <cstdio>

class Queue
{
public:
	Queue(unsigned int capacity);
	
	bool isFull();
	bool isEmpty();
	void enqueue(double item);
	double dequeue();
	void updateElements(double stepSize, double maxSize);
	int frontVal() { return front; }
	int rearVal() { return rear; }
	int sizeVal() { return size; }
	void printElements();

	~Queue();

private:
	int front, rear, size;
	unsigned int capacity;
	double* arr;
};

