/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:29:31 by hirokiurabe       #+#    #+#             */
/*   Updated: 2025/03/08 19:31:23 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// コンストラクタ
Form::Form(const std::string &name, int signGrade, int executeGrade) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade), _isSigned(false) {
	if (signGrade > MIN_GRADE)
		throw GradeTooLowException();
	else if (signGrade < MAX_GRADE)
		throw GradeTooHighException();
	if (executeGrade > MIN_GRADE)
		throw GradeTooLowException();
	else if (executeGrade < MAX_GRADE)
		throw GradeTooHighException();
}

// コピーコンストラクタ
Form::Form(const Form &copy) : _name(copy._name), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade), _isSigned(copy._isSigned) {}

// 代入演算子のオーバーロード
Form &Form::operator=(const Form &copy) {
	if (this != &copy) {}
	return *this;
}

// デストラクタ
Form::~Form() {}

// グレードが低すぎる場合の例外処理用
const char*	Form::GradeTooLowException::what() const throw() {
	return "Form: grade is too low...";
}

// グレードが高すぎる場合の例外処理用
const char*	Form::GradeTooHighException::what() const throw() {
	return "Form: grade is too high!!!";
}

// フォームの名前を取得する関数
const std::string &Form::getName() const {
	return this->_name;
}

// フォームの署名状態を取得する関数
bool Form::getSigned() const {
	return _isSigned;
}

// フォームを署名するのに必要なグレードを取得する関数
int	Form::getGradeSign() const {
	return _signGrade;
}

// フォームを実行するのに必要なグレードを取得する関数
int	Form::getGradeExec() const {
	return _executeGrade;
}

// Bureaucratによる署名処理
void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (this->_signGrade < bureaucrat.getGrade())
		throw GradeTooLowException();
	this->_isSigned = true;
}

// 出力演算子のオーバーロード
std::ostream &operator<<(std::ostream &o, const Form &form) {
	o << "Name: " << form.getName() << ", is Signed: " << form.getSigned() << ", grade required to sign: " << form.getGradeSign() << ", grade required to execute: " << form.getGradeExec() << std::endl;
	return o;
}
