#ifndef _TDEQUE_H_
#define	_TDEQUE_H_
#include <iostream>
#include <string>
#include <stdexcept>

template <class T>
class Deque{
private:
	// Private data to implement the deque
	int cap, qSize;
	T *q, remove, *q2;

public:
	// Constructor
	Deque()
	{
		cap = 8;								// Initial/minimum size queue
		q = new T[cap];							// Array of the queue
	}

	// Destructor
	~Deque()
	{
		delete[] q;
	}

	// Inserts an element at the front of the queue 
	void push_front(T item)
	{
		if (qSize < 0)
		{
			try
			{
				throw out_of_range("Error. Cannot insert element before queue's initial position.");
			}
			catch (exception e)
			{
				cout << "Error. Cannot insert element before queue's initial position." << endl;
				throw;
			}
		}
		else
		{
			for (int i = qSize - 1; i >= 0; --i)	// Items move over to the right to make space for item
			{
				q[i + 1] = q[i];
			}
			q[0] = item;							// An item is inserted at the front of the queue
			++qSize;								// Increment element amount in queue
			modifySize();							// Automatically doubles or halves depending if queue is full
		}											// or less than 1 / 4 full and not already of minimum size
	}

	// Inserts an element at the back of the queue 
	void push_back(T item)
	{
		if (qSize >= cap)
		{
			try
			{
				throw out_of_range("Error. Cannot insert element after queue's last position.");
			}
			catch (exception e)
			{
				cout << "Error. Cannot insert element after queue's last position." << endl;
				throw;
			}
		}
		else
		{
			q[qSize] = item;						// Insert element at back of queue
			++qSize;								// Increment element amount in queue
			modifySize();							// Automatically doubles or halves depending if queue is full 
		}											// or less than 1 / 4 full and not already of minimum size 
	}

	// Removes the element at the front of the queue 
	T pop_front()
	{
		if (empty())							// If element == 0, then return Error; items cannot be removed from an empty queue
		{
			try
			{
				throw runtime_error("Error. Cannot remove element from an empty queue.");
			}
			catch (exception e){
				cout << "Error. Cannot remove from an empty queue." << endl;
				throw;
			}
		}
		else									// Otherwise, remove item from the front of the queue 
		{
			remove = q[0];
			--qSize;							// Decrease element amount in queue
			for (int i = 0; i < qSize; ++i)	// Items move over to the left
			{
				q[i] = q[i + 1];
			}
			return remove; 						// Return
			modifySize();						// Automatically doubles or halves depending if queue is full 
		}										// or less than 1 / 4 full and not already of minimum size 
	}

	// Removes the element at the back of the queue 
	T pop_back()
	{
		if (empty())							// If element == 0, then return Error; items cannot be removed from an empty queue
		{
			try
			{
				throw runtime_error("Error. Cannot remove from an empty queue.");
			}
			catch (exception e){
				cout << "Error. Cannot remove from an empty queue." << endl;
				throw;
			}
		}
		else									// Otherwise, remove item from the back of the queue 
		{
			remove = q[qSize - 1];
			--qSize; 							// Decrease element amount in queue
			return remove;						// Return
			modifySize();						// Automatically doubles or halves depending if queue is full 
		}										// or less than 1 / 4 full and not already of minimum size 
	}

	// Returns the size of the queue
	int size()
	{
		return cap;
	}

	// Checks to see if the queue is empty 
	bool empty()
	{
		if (qSize == 0)						// If empty, return true		
		{
			return true;
		}
		else									// Otherwise, return false
		{
			return false;
		}
	}

	// Checks capacity after each push/pop, then automatically doubles or halves the queue given certain conditions
	void modifySize(void)
	{
		if (qSize == cap)						// Check if queue is full
		{
			q2 = new T[cap * 2];				// The queue doubles in size when it is full
			cap = cap * 2; 						// New capacity is doubled
			for (int i = 0; i < qSize; ++i)	// Iterate so that values in q are acquired by q2
			{
				q2[i] = q[i];
			}
			q = q2; 							// Rename for output
		}										// Check if queue is less than 1/4 full and not already of minimum size
		else if ((qSize < (cap / 4)) && (cap > 8))
		{
			q2 = new T[cap / 2];				// The queue becomes half its size
			cap = cap / 2; 						// New capacity is halved
			for (int i = 0; i < qSize; ++i)	// Iterate so that values in q are acquired by q2
			{
				q2[i] = q[i];
			}
			q = q2;								// Rename for output
		}
	}

	/* Prints the contents of the queue from front to back
	* to stdout with one string per line followed by a blank line
	*/
	std::string toStr()
	{
		for (int i = 0; i < qSize; i++)		// Print array of queue followed by new line
		{
			std::cout << q[i] << std::endl;
		}
		return "";								// Return
	}
};

#endif /* _TDEQUE_H_ */
