/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:55:08 by cpothin           #+#    #+#             */
/*   Updated: 2024/02/03 15:26:29 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
	private:
		T *array;
		unsigned int size;
	public:
		~Array();
		Array();
		Array(unsigned int n) : array(new T[n]), size(n) {};
		Array(const Array &a);
		Array<T> &operator=(Array<T> const &a);
		T &operator[](unsigned int i);
		unsigned int Size() const;
		void display(std::ostream &s) const;

	class WrongIndex : public std::exception
	{
		public:
			virtual const char* what() const throw() {return "The chosen index is wrong!";}
	};
};
template <class T>
std::ostream &operator<<(std::ostream &s, Array<T>const &a);

template <class T>
unsigned int Array<T>::Size() const {return (this->size);};

template <class T>
Array<T>::Array(const Array &a)
{
	this->array = NULL;
	this->array(new T[a.Size()]);
	this->size(a.Size());
};

template <class T>
Array<T>::Array()
{
	new T[0];
	this->size = 0;
}

template <class T>
Array<T>::~Array()
{
	if (this->Size() > 0)
		delete [] (this->array);
}

template <class T>
Array<T> &Array<T>::operator=(Array<T> const &a)
{
	if (this->array != NULL)
		delete [] (this->array);
	this->size = a.size;
	this->array = new T[this->size];
	for (unsigned int i = 0; i < this->size; i++)
		this->array[i] = a.array[i];
	return (*this);
}

template <class T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= size)
		throw (Array::WrongIndex());
	return (this->array[i]);
};

template <class T>
std::ostream &operator<<(std::ostream &s, Array<T>const &a)
{
	a.display(s);
	return (s);
}

template <class T>
void Array<T>::display(std::ostream &s) const
{
	unsigned int i;
	if (this->size == 0)
	{
		s << RGB(Colors::RoyalBlue) << "No content." << RESET;
		return ;
	}
	s << RGB(Colors::NightBlue) << "Array content: " << std::endl;
	for (i = 0; i < this->size - 1; i++)
		s << RGB(Colors::RoyalBlue) << this->array[i] << RESET << ", ";
	s << RGB(Colors::RoyalBlue) << this->array[i] << RESET;
}

#endif