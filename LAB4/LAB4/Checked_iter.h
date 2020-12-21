#pragma once


template<class Cont, class Iter = typename Cont::iterator>

class Checked_iter : public std::iterator_traits<Iter>
{//Iter curr, Cont c
public:
	typedef Iter* pointer;
	typedef int difference_type;
	typedef Iter& reference;
	//typedef Iter value_type;
	typedef typename Cont::value_type value_type;
	typedef Iter iterator_type;

	void valid(Iter p) const
	{

		if (c->end() == p)
		{
			return;
		}
		int countr = 0;
		for (Iter pp = c->begin(); pp != c->end() /*&& countr < c->size()*/; ++pp, countr++)
		{
			if (pp == p)
			{
				return;
			}
		}
		throw std::out_of_range{ "invalid iterator!" };

	}
	Cont& cont()
	{
		return *c;
	}
	bool operator==(const Checked_iter& j)
	{
		return c == j.c && curr == j.curr;
	}
	bool operator!=(const Checked_iter& j)
	{
		return !(c == j.c && curr == j.curr);
	}
	bool operator== (typename Cont::value_type& x) const
	{
		return false;
	}
	/*
	нет инициализатора по умолчанию
	используем копирующий конструктор по умолчанию
	и копирующее присваивание по умлочанию
	*/
	Checked_iter(Cont& x, Iter p) : c(&x), curr(p) { valid(p); }
	Checked_iter(Cont& x, Checked_iter p) : c(&x), curr(p.curr) { valid(curr); }
	//Checked_iter(Cont& x, Checked_iter& p) : c(&x), curr(p.curr) { valid(p); }
	Checked_iter(Cont& x) : c(&x), curr(x.begin()) { }
	typename Cont::reference operator*()
	{
		/*if (curr == c->end())
		{
			throw out_of_range{"invalid *iterator"};
		}*/
		valid(curr);
		return *curr;
	}
	pointer operator->() const
	{
		return &*curr; // проверяется *
	}
	typedef int difference;
	//typedef int difference_type;
	Checked_iter& operator+(typename Cont::difference_type d) const
	{
		if (c->end() - curr < d || d < -(curr - c->begin()))
			throw std::out_of_range{"invalid iterator + ..."};
		Checked_iter* tmp = new Checked_iter(*c, curr + d);
		valid(tmp->curr);
		return *tmp;
	}
	Checked_iter& operator-(typename Cont::difference_type d) const
	{
		if ((curr - c->begin()) < d || d < -(c->end() - curr))
			throw std::out_of_range{ "invalid iterator - ..." };
		Checked_iter* tmp = new Checked_iter(*c, curr - d);
		valid(tmp->curr);
		return *tmp;
	}
	typename Cont::reference operator[](typename Cont::difference_type d) const
	{
		if (c->end() - curr <= d || d < -(curr - c->begin()))
			throw std::out_of_range{"invalid []"};
		Iter* tmp = new Iter(curr + d);
		valid(*tmp);
		return **tmp;
	}
	Checked_iter& operator++()
	{
		if(curr==c->end())
			throw std::out_of_range{"invallid ++iterator"};
		++curr;
		valid(curr);
		return *this;
	}
	Checked_iter& operator++(int)
	{
		Checked_iter tmp = *this;
		++* this;
		valid(tmp);
		return tmp;
	}
	Checked_iter& operator--()
	{
		if (curr == c->begin())
			throw std::out_of_range{ "invallid --iterator" };
		--curr;
		return *this;
	}
	Checked_iter& operator--(int)
	{
		Checked_iter tmp = *this;
		--* this;
		return tmp;
	}
	difference_type index() const
	{
		return curr - c.begin();
	}
	Iter unchecked() const
	{
		return curr;
	}
	// +, -, < и т п самостоятельно
	difference operator-(Checked_iter& other) const
	{
		return curr - other.curr;
	}
	auto& operator+(Checked_iter& other) const
	{
		return curr + other.curr;
	}
	difference operator-(const Checked_iter& other) const
	{
		return curr - other.curr;
	}
	auto& operator+(const Checked_iter& other) const
	{
		return *new auto(curr + other.curr);
	}
	bool operator<(Checked_iter& other)
	{
		return curr < other.curr;
	}
	bool operator>(Checked_iter& other)
	{
		return curr > other.curr;
	}

private:

	Iter curr;
	Cont* c;

};


template<class C>
class Checked : public C
{
public:
	explicit Checked(size_t n):C(n){}
	Checked():C(){}
	typedef Checked_iter<C> iterator;
	//typedef Checked_iter<C, C::iterator> const_iterator;
	iterator& begin()
	{
		iterator* tmp = new iterator(*this, C::begin());
		return *tmp;
	}
	iterator end()
	{
		return iterator(*this, C::end());
	}
	/*const_iterator begin() const
	{
		return const_iterator(*this, C::begin());
	}
	const_iterator end() const
	{
		return const_iterator(*this, C::end());
	}*/
	typename C::reference operator[](typename C::size_type n)
	{
		return Checked_iter<C>(*this)[n];
	}
	C& base() 
	{
		return this;
	}
};

template<class Cont, class Iter = typename Cont::iterator>
void sort(Checked_iter<Cont>& first, Checked_iter<Cont> last)
{

	for (Checked_iter<Cont> i = (first); i != last - 1; ++i)
	{
		for (Checked_iter<Cont> j = (first); j != last - 1; ++j)
		{
			if (*(j) > *(j + 1))
			{
				auto tmp = j;
				++tmp;
				auto tmpr = *tmp;
				*tmp = *j;
				*j = tmpr;
			}
		}
	}
}


//template<class Cont, class Iter = typename Cont::iterator>
//Checked_iter<Cont>& find(Checked_iter<Cont>& first, Checked_iter<Cont> last, typename Cont::value_type value)
//{
//	Checked_iter<Cont> i = first;
//	for (; i != last; ++i)
//	{
//		if (*i == value)
//		{
//			Checked_iter<Cont>* tmp = new Checked_iter<Cont>(i.cont(), i);
//			return *tmp;
//		}
//		 
//	}
//	Checked_iter<Cont>* tmp = new Checked_iter<Cont>(i.cont(), i);
//	return *tmp;
//}
