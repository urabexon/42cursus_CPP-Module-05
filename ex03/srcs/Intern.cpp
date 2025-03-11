/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:48:41 by hirokiurabe       #+#    #+#             */
/*   Updated: 2025/03/11 21:13:53 by hurabe           ###   ########.fr       */
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

const char *Intern::FormNotExistException::what() const throw() {
	return "Requested form does not exist.";
}

// 各フォーム生成
static AForm* createShrubbery(const std::string &target) {
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string &target) {
	return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string &target) {
	return new PresidentialPardonForm(target);
}

// フォームの種類と対応する生成関数をまとめる
Intern::FormType Intern::_FormType[] = {
    {"shrubbery creation", &createShrubbery},
    {"robotomy request", &createRobotomy},
    {"presidential pardon", &createPresidential},
    {NULL, NULL}
};

// フォームを作成する
AForm* Intern::makeForm(const std::string &name, const std::string &target) {
	for (int i = 0; _FormType[i].formName != NULL; i++) {
    	if (name == _FormType[i].formName) {
    		std::cout << "Intern creates " << name << std::endl;
    		return _FormType[i].createForm(target);
		}
	}
	// フォームが見つからなかった場合、例外をスロー
	throw FormNotExistException();
}
