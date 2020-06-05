#pragma once
#include <cassert>
#include <iostream>
#include <fstream>
#include "mexception.h"

template <typename T>
class mvector final
{
	T* vec_;
	size_t size_;
	size_t capacity_;

	class mvector_exception : public mexception
	{
	public:
		mvector_exception() : mexception("unknown mvector exception") {}
		mvector_exception(const char* what) : mexception(what) {}
	};

	typedef T* iter;
public:
	mvector() : size_(), capacity_(), vec_() { ; }
	mvector(const mvector& other) : size_(other.size_), capacity_(other.size_), vec_()
	{
		vec_ = new T[size_];
		for (size_t i = 0; i < size_; ++i)
			vec_[i] = other.vec_[i];
	}
	mvector(const size_t _size, const T _val) : size_(_size), capacity_(size_ + 10), vec_()
	{
		vec_ = new T[capacity_];
		for (size_t i = 0; i < size_; ++i)
			*(vec_ + i) = _val;
	}
	mvector(const std::initializer_list<T> list) : size_(list.size()), capacity_(size_ + 10), vec_()
	{
		vec_ = new T[capacity_];
		for (size_t i = 0; i < size_; ++i)
			*(vec_ + i) = *(list.begin() + i);
	}
	~mvector()
	{
		if (capacity_ > 0)
			delete[] vec_;
		capacity_ = 0;
	}

	void push_back(const T val)
	{
		if (size_ + 1 >= capacity_)
		{
			if (capacity_ > 0)
				capacity_ *= 2;
			else
				capacity_ = 10;
			T* tmp = new T[capacity_];
			for (size_t i = 0; i < size_; ++i)
				tmp[i] = vec_[i];
			if (size_ > 0)
				delete[] vec_;
			vec_ = tmp;
		}
		*(vec_ + size_++) = val;
	}

	T pop_back()
	{
		if (size_ < 1)
			throw mvector_exception("An attempt into pop_back from an empty mvector");
		return vec_[--size_];
	}

	iter insert(const size_t _where, const iter _first, const iter _last)
	{
		assert(_where <= size_);
		assert(_first <= _last);

		assert(_last >= _first);
		size_t diff = _last - _first;

		if (size_ + diff >= capacity_)
		{
			capacity_ = size_ + diff + 10;
			T* tmp = new T[capacity_];

			for (size_t i = 0; i < _where; ++i)
				*(tmp + i) = vec_[i];
			for (size_t i = 0; i < diff; ++i)
				*(tmp + i + _where) = *(_first + i);
			for (size_t i = _where + diff; i < size_ + diff; ++i)
				*(tmp + i) = vec_[i - diff];

			delete[] vec_;
			vec_ = tmp;
			size_ += diff;

			return (this->begin() + _where);
		}

		for (size_t i = size_ - 1 + diff; i > _where + diff - 1; --i)
			vec_[i] = vec_[i - diff];

		for (size_t i = 0; i < diff; ++i)
			vec_[_where + i] = *(_first + i);
		size_ += diff;

		return (this->begin() + _where);
	}

	iter insert(const size_t _where, const T _val)
	{
		assert(_where <= size_);

		if (size_ + 1 >= capacity_)
		{
			if (capacity_ > 0)
				capacity_ *= 2;
			else
				capacity_ = 10;

			T* tmp = new T[capacity_];
			for (size_t i = 0; i < _where; ++i)
				tmp[i] = vec_[i];
			*(tmp + _where) = _val;
			for (size_t i = _where; i < size_ + 1; ++i)
				*(tmp + i + 1) = vec_[i];

			delete[] vec_;
			vec_ = tmp;
			++size_;
			return (this->begin() + _where);
		}

		for (size_t i = size_; i > _where; --i)
			vec_[i] = vec_[i - 1];
		vec_[_where] = _val;
		++size_;

		return (this->begin() + _where);
	}

	iter insert(const size_t _where, const T _val, const size_t _count)
	{
		assert(_where <= size_);

		if (size_ + _count >= capacity_)
		{
			capacity_ = size_ + _count + 10;
			T* tmp = new T[capacity_];

			for (size_t i = 0; i < _where; ++i)
				*(tmp + i) = vec_[i];
			for (size_t i = 0; i < _count; ++i)
				*(tmp + _where + i) = _val;
			for (size_t i = _where; i < size_; ++i)
				*(tmp + i + _count) = vec_[i];
			size_ += _count;

			delete[] vec_;
			vec_ = tmp;
			return (this->begin() + _where);
		}

		for (size_t i = size_ + _count - 1; i >= _where + _count; --i)
			vec_[i] = vec_[i - _count];
		for (size_t i = 0; i < _count; ++i)
			vec_[_where + i] = _val;
		size_ += _count;

		return (this->begin() + _where);
	}

	iter erase(const size_t _where)
	{
		assert(_where < size_);

		for (size_t i = _where; i < size_ - 1; ++i)
			vec_[i] = vec_[i + 1];
		--size_;

		return (this->begin() + _where);
	}

	iter erase(const size_t _first, const size_t _last)
	{
		assert(_first < _last && _last < size_);
		size_t diff = size_ - _last;

		for (size_t i = 0; i < diff; ++i)
			vec_[_first + i] = vec_[_last + i + 1];
		size_ -= _last - _first + 1;

		return (this->begin() + _first);
	}

	void reserve(const size_t _size)
	{
		T* tmp = new T[_size + size_];

		for (size_t i = 0; i < size_; ++i)
			tmp[i] = vec_[i];

		if (capacity_ > 0)
			delete[] vec_;
		vec_ = tmp;
		capacity_ = size_ + _size;
	}

	void resize(const size_t _size, const T _val = 0)
	{
		if (_size <= size_)
		{
			size_ = _size;
			return;
		}
		if (_size > capacity_)
		{
			capacity_ = _size + 10;
			T* tmp = new T[capacity_];

			for (size_t i = 0; i < size_; ++i)
				*(tmp + i) = vec_[i];
			for (size_t i = size_; i < _size; ++i)
				*(tmp + i) = _val;
			size_ = _size;
			delete[] vec_;
			vec_ = tmp;
			return;
		}

		for (size_t i = size_; i < _size; ++i)
			*(vec_ + i) = _val;
		size_ = _size;
	}
	void shrink_to_fit()
	{
		if (capacity_ > size_)
		{
			T* tmp = new T[size_];
			for (size_t i = 0; i < size_; i++)
				tmp[i] = vec_[i];
			delete[] vec_;
			vec_ = tmp;
			capacity_ = size_;
		}
	}

	void clear()
	{
		if (capacity_ > 0)
			delete[] vec_;
		size_ = 0;
		capacity_ = 0;
	}

	inline size_t size() const { return size_; }
	inline size_t capacity() const { return capacity_; }
	inline bool empty() const { return (size_ > 0 ? false : true); }

	inline T& front() { assert(size_ > 0);	return vec_[0]; }
	inline T& back() { assert(size_ > 0);	return vec_[size_ - 1]; }
	inline const T& front() const { assert(size_ > 0);	return vec_[0]; }
	inline const T& back() const { assert(size_ > 0);	return vec_[size_ - 1]; }

	inline iter begin() const { return &vec_[0]; }
	inline iter end() const { return (size_ > 0 ? &vec_[size_] : &vec_[1]); }

	inline T&operator[](const size_t i)
	{
		assert(i < size_);
		return vec_[i];
	};

	inline const T&operator[](const size_t i) const
	{
		assert(i < size_ && size_ > 0);
		return vec_[i];
	};

	mvector* operator=(const mvector& other)
	{
		if (this == &other)
			return this;

		if (capacity_ > 0)
			delete[] vec_;

		vec_ = new T[other.size_];
		size_ = other.size_;
		for (size_t i = 0; i < size_; ++i)
			vec_[i] = other.vec_[i];
		capacity_ = size_;
		return this;
	}
	mvector* operator=(const std::initializer_list<T>& list)
	{
		delete[] vec_;
		size_ = list.size();
		capacity_ = size_ + 10;
		vec_ = new T[capacity_];

		for (size_t i = 0; i < size_; ++i)
			*(vec_ + i) = *(list.begin() + i);

		return this;
	}

	friend bool operator==(const mvector& c1, const mvector& c2)
	{
		if (c1.size() != c2.size())
			return false;
		for (size_t i = 0; i < c1.size_; ++i)
			if (c1[i] != c2[i])
				return false;
		return true;
	}
	friend bool operator!=(const mvector& c1, const mvector& c2) { return !(c1 == c2); }
	friend bool operator<(const mvector& c1, const mvector& c2)
	{
		if (c1.size_ < c2.size_)
			return true;
		if (c1.size_ > c2.size_)
			return false;

		for (size_t i = 0; i < c1.size_; ++i)
			if (c1[i] >= c2[i])
				return false;
		return true;
	}
	friend bool operator>(const mvector& c1, const mvector& c2)
	{
		if (c1.size_ > c2.size_)
			return true;
		if (c1.size_ < c2.size_)
			return false;

		for (size_t i = 0; i < c1.size_; ++i)
			if (c1[i] <= c2[i])
				return false;
		return true;
	}
	friend bool operator<=(const mvector& c1, const mvector& c2) { return !(c1 > c2); }
	friend bool operator>=(const mvector& c1, const mvector& c2) { return !(c1 < c2); }
};