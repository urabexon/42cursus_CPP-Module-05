/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:48:31 by hirokiurabe       #+#    #+#             */
/*   Updated: 2025/03/09 22:12:36 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Intern_HPP
#define Intern_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

#define FORM_SHRUBBERY 0
#define FORM_ROBOTOMY 1
#define FORM_PRESIDENTIAL 2

class Intern {
	public:
		Intern();
		Intern(const Intern &copy);
		Intern &operator=(const Intern &copy);
		~Intern();

		int getFormType(const std::string &name) const;
    	AForm *makeForm(const std::string &name, const std::string &target);

		class FormNotExistException: public std::exception {
			const char *what() const throw();
		};
};

#endif
