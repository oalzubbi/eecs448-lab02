/**
*	@author
*	@date
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList()
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{

	return(m_size);
	//changed the function to return the value of m_size
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front;
	bool isFound = false;

	if(isEmpty())//if it's empty juts return false
	{
		return(false);
	}
	while(temp!=nullptr) //this condition loops until the last node
	{
		if(temp->getValue()==value)
		{
			isFound=true;//return true if it matches the value
			break;//and break the loop when you find it
		}

		else
		{
			temp=temp->getNext();//if you don't find it, move on to the next element
		}
	}

	return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);

}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode = nullptr;
	Node<T>* secondintoLast = nullptr;
	bool isRemoved = false;
	if(isEmpty())//if it's empty, just return false
	{
		return(false);
	}

	lastNode = m_front;//start this here for the looping condition
	while(lastNode->getNext() != nullptr)//this loop allows you to get to the last element in the list
	{
		secondintoLast = lastNode;//secondintoLast will always be one behind lastNode
		lastNode = lastNode->getNext();
	}

	secondintoLast->setNext(nullptr);//set the secondintoLast node to nullptr to avoid a dangling pointer
	m_size--; //decrement size
	delete lastNode; //remove the last node

	return(true);
}

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
