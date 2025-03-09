/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:48:41 by hirokiurabe       #+#    #+#             */
/*   Updated: 2025/03/09 22:18:44 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &copy) {
	(void)copy;
}

Intern &Intern::operator=(const Intern &copy) {
	if (this != &copy) {
		// メンバ変数を持たないため、何もしない
	}
	return *this;
}

Intern::~Intern() {}

int Intern::getFormType(const std::string &name) const {
	if (name == "shrubbery creation")
		return FORM_SHRUBBERY;
	else if (name == "robotomy request")
		return FORM_ROBOTOMY;
	else if (name == "presidential pardon")
		return FORM_PRESIDENTIAL;
	return -1;
}

const char *Intern::FormNotExistException::what() const throw() {
	return "Requested form does not exist.";
}

AForm* Intern::makeForm(const std::string &name, const std::string &target) {
	AForm* form = NULL; // nullptrは++98では使用できないため
	switch (getFormType(name)) {
	case FORM_SHRUBBERY:
		form = new ShrubberyCreationForm(target);
		std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
   		break;
	case FORM_ROBOTOMY:
 		form = new RobotomyRequestForm(target);
		std::cout << "Intern creates RobotomyRequestForm" << std::endl;
		break;
	case FORM_PRESIDENTIAL:
		form = new PresidentialPardonForm(target);
		std::cout << "Intern creates PresidentialPardonForm" << std::endl;
  		break;
	default:
		throw FormNotExistException();
	}
	return form;
}
