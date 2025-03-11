/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:48:31 by hirokiurabe       #+#    #+#             */
/*   Updated: 2025/03/11 21:01:47 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Intern_HPP
#define Intern_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Intern {
	public:
		Intern();
		Intern(const Intern &copy);
		Intern &operator=(const Intern &copy);
		~Intern();

    	AForm *makeForm(const std::string &name, const std::string &target);

		class FormNotExistException: public std::exception {
			const char *what() const throw();
		};
	
	private:
		struct FormType {
			const char*	formName;
			AForm* (*createForm)(const std::string&);
		};
		static FormType _FormType[];
};

#endif
