#pragma once

//#include "Header.h" 



template <typename DT>
class vctor 
{
public:
    typedef DT& reference;
    typedef size_t size_type;
    typedef DT value_type;
    typedef DT* pointer;
    typedef long difference_type;
    typedef DT* iterator;
    explicit vctor(long long = 100);


    long long push_back(DT);


    DT pop_back();


    long long size() const;
    DT& operator[](long long);

     iterator& begin();

     iterator end();
private:
    DT* arr;
    long long capacity;
    long long length;

};


template <typename DT>
vctor<DT>::vctor(long long n)
    : capacity(n), arr(new DT[n]), length(0)
{
}
 
template <typename DT>
long long vctor<DT>::push_back(DT data)
{
    if (length == capacity) {
        DT* old = arr;
        arr = new DT[capacity = capacity * 2];
        copy(old, old + length, arr);
        delete[] old;
    }
    arr[length++] = data;
    return length;
}


template <typename DT>
DT vctor<DT>::pop_back()
{
    return arr[length-- - 1];
}


template <typename DT>
long long vctor<DT>::size() const
{
    return capacity;
}


template <typename DT>
DT& vctor<DT>::operator[](long long index)
{
 
    if (index >= length) {
        throw std::out_of_range{"out of range in vector"};
    }

    return *(arr + index);
}

template <typename DT>
typename vctor<DT>::iterator&
vctor<DT>::begin()
{
    return arr;
}

template <typename DT>
typename vctor<DT>::iterator
vctor<DT>::end() 
{
    return arr + capacity;
}
