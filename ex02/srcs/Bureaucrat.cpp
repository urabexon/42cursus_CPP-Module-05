/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:33:53 by hirokiurabe       #+#    #+#             */
/*   Updated: 2025/03/09 19:06:19 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// コンストラクタ
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
    if (grade > MIN_GRADE)
    	throw GradeTooLowException();
    else if (grade < MAX_GRADE)
    	throw GradeTooHighException();
}

// コピーコンストラクタ
Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade) {}

// 代入演算子のオーバーロード
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
    if (this != &copy)
        this->_grade = copy._grade;
    return *this;
}

// デストラクタ
Bureaucrat::~Bureaucrat() {}

// グレードが低すぎる場合の例外処理用
const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "grade is too low...";
}

// グレードが高すぎる場合の例外処理用
const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return "grade is too high!!!";
}

// 名前取得のためのゲッター
const std::string &Bureaucrat::getName() const {
    return this->_name;
}

// グレード取得のためのゲッター
int Bureaucrat::getGrade() const {
    return this->_grade;
}

// グレードを増やすためのメンバ関数
void Bureaucrat::incrementGrade() {
    if (_grade <= MAX_GRADE)
        throw GradeTooHighException();
    _grade--;
}

// グレードを減らすためのメンバ関数
void Bureaucrat::decrementGrade() {
    if (_grade >= MIN_GRADE)
        throw GradeTooLowException();
    _grade++;
}

// Bureaucratがフォームを署名するためのメンバ関数
void Bureaucrat::signForm(AForm &form) const {
	try {
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << this->_name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

//
void Bureaucrat::executeForm(AForm const & form) const {
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

// 出力演算子のオーバーロード
std::ostream &operator<<(std::ostream &o, const Bureaucrat &bureaucrat) {
    o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
    return o;
}
