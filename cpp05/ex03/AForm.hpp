/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:49:23 by cpothin           #+#    #+#             */
/*   Updated: 2024/01/25 16:06:31 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool isSigned;
		const int requiredGradeToSign;
		const int requiredGradeToExecute;
	public:
		AForm(const std::string& newName, int newGradeToSign, int newGradeToExecute);
		virtual ~AForm();
		AForm(const AForm &a);
    	AForm &operator=(const AForm &a);
		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(Bureaucrat &bureaucrat);
    	virtual void execute(const Bureaucrat &bureaucrat) const = 0;
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {return "Form grade is too high";}
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {return "Form grade is too low";}
		};
		class NotSignedException : public std::exception {
        	public:
            	virtual const char* what() const throw() { return "Form not signed";}
    	};
};
std::ostream &operator<<(std::ostream &o, const AForm &a);

#endif