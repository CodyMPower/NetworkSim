#include "Queue.h"

Queue::Queue(unsigned int capacity)
{
	this->capacity = capacity;
	this->front = 0;
	this->size = 0;
	this->rear = capacity - 1;
	this->arr = (double*)malloc(sizeof(double) * capacity);
}

bool Queue::isFull()
{
	return (size == capacity);
}

bool Queue::isEmpty()
{
	return size == 0;
}

void Queue::enqueue(double item)
{
	if (isFull())
		return;

	rear = (rear + 1) % capacity;
	arr[rear] = item;
	size ++;
}

double Queue::dequeue()
{
	if (isEmpty())
		return INT_MIN;

	int element = arr[front];
	front = (front + 1) % capacity;
	size--;
	return element;
}

void Queue::updateElements(double stepSize, double maxSize)
{
	if (isEmpty())
		return;

	if (front <= rear)
		for (int i = front; i <= rear; i++)
		{
			arr[i] += stepSize;
			if (arr[i] > maxSize)
				dequeue();
		}
	else
	{
		for (int i = front; i < capacity; i++)
		{
			arr[i] += stepSize;
			if (arr[i] > maxSize)
				dequeue();
		}

		for (int i = 0; i <= rear; i++)
		{
			arr[i] += stepSize;
			if (arr[i] > maxSize)
				dequeue();
		}
	}

}

void Queue::printElements()
{
	if (isEmpty())
	{
		printf("{ }\n");
		return;
	}

	printf("{ ");
	if (front <= rear)
	{
		for (int i = front; i < rear; i++)
		{
			printf("%f, ", arr[i]);
		}
		
	} else
	{
		for (int i = front; i < capacity; i++)
		{
			printf("%f, ", arr[i]);
		}

		for (int i = 0; i < rear; i++)
		{
			printf("%f, ", arr[i]);
		}
	}
	printf("%f }\n", arr[rear]);
}

Queue::~Queue()
{
	free(arr);
}
