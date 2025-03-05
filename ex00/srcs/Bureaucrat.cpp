/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirokiurabe <hirokiurabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:26:16 by hirokiurabe       #+#    #+#             */
/*   Updated: 2025/03/05 20:47:07 by hirokiurabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
    if (grade > MIN_GRADE)
        throw GradeTooLowException();
    else if (grade < MAX_GRADE)
        throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
    *this = copy;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
    if (this != &copy)
        this->_grade = copy._grade;
    return *this;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low.";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "GRADE is too high.";
}

const std::string &Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

void    Bureaucrat::incrementGrade() {
    if (_grade - 1 < MAX_GRADE)
        throw GradeTooHighException();
    _grade -= 1;
}

void    Bureaucrat::decrementGrade() {
    if (_grade + 1 > MIN_GRADE)
        throw GradeTooLowException();
    _grade += 1;
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &bureaucrat) {
    o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
    return o;
}
