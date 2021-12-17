#ifndef __QUEUE_H__
#define __QUEUE_H__



template <class T>
class TQueue
{
private:
	int size, hi, li, count;
	T* mas;
public:
	TQueue(int s = 10);
	~TQueue();
	void setsize(int s);
	int GetCount() { return count; }
	int GetSize() { return size; }
	bool Empty() const;
	bool Full() const;
	void Push(const T elem);
	T InfoLi() const;
	T GetLi();
};

template<class T>
void TQueue<T>::setsize(int s) 
{
	if ((s < 1) || (s > 100))
		throw s;
	size = s;
	hi = size - 1;
	delete[] mas;
	mas = new T[size];
}
template<class T>
TQueue<T>::TQueue(int s)
{
	if ((s < 1)||(s>100))
		throw s;
	size = s;
	count = 0;
	li = 0;
	hi = size - 1;
	mas = new T[size];
}
template <class T>
TQueue<T>::~TQueue()
{
	delete[]mas;
}
template<class T>
bool TQueue<T>::Empty() const
{
	if (count == 0)
		return true;
	return false;
}
template<class T>
bool TQueue<T>::Full() const
{
	if (count == size)
		return true;
	return false;
}
template <class T>
void TQueue<T>::Push(const T elem)
{
	if (Full() == true)
		throw count;

		hi = (hi+1) % size;
		mas[hi] = elem;
	count++;
}
template<class T>
T TQueue<T>:: InfoLi() const
{
	if (Empty()==true)
		throw count;
	return mas[li];
}
template<class T>
T TQueue<T>::GetLi()
{
	if (Empty() == true)
		throw count;
	count--;
	li = (li + 1) % size;
	if (li == 0)
		return mas[size - 1];
	return mas[li-1];
}
#endif