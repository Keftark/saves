/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:03:56 by cpothin           #+#    #+#             */
/*   Updated: 2024/01/24 15:05:01 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Colors.hpp"

class Bureaucrat
{
	protected:
	private:
		const std::string name;
		int grade;
		Bureaucrat();
	public:
		Bureaucrat(const std::string &newName, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &a);
    	Bureaucrat &operator=(const Bureaucrat &a);
		void addGrade();
		void subGrade();
		std::string getName() const;
		int getGrade() const;
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* msg() const throw() { return "Grade is too high"; }
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* msg() const throw() { return "Grade is too low"; }
		};
};
std::ostream &operator<<(std::ostream &o, const Bureaucrat &a);

#endif