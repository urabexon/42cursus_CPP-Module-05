/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:33:42 by hirokiurabe       #+#    #+#             */
/*   Updated: 2025/03/09 20:21:21 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _signGrade(1), _executeGrade(1), _isSigned(false) {}

// コンストラクタ
AForm::AForm(const std::string &name, int signGrade, int executeGrade) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade), _isSigned(false) {
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
AForm::AForm(const AForm &copy) : _name(copy._name), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade), _isSigned(copy._isSigned) {}

// 代入演算子のオーバーロード
AForm &AForm::operator=(const AForm &copy) {
	if (this != &copy)
		this->_isSigned = copy._isSigned;
	return *this;
}

// デストラクタ
AForm::~AForm() {}

// グレードが低すぎる場合の例外処理用
const char*	AForm::GradeTooLowException::what() const throw() {
	return "Form: grade is too low...";
}

// グレードが高すぎる場合の例外処理用
const char*	AForm::GradeTooHighException::what() const throw() {
	return "Form: grade is too high!!!";
}

//
const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!!!";
}

// フォームの名前を取得する関数
const std::string &AForm::getName() const {
	return this->_name;
}

// フォームの署名状態を取得する関数
bool AForm::getSigned() const {
	return _isSigned;
}

// フォームを署名するのに必要なグレードを取得する関数
int	AForm::getGradeSign() const {
	return _signGrade;
}

// フォームを実行するのに必要なグレードを取得する関数
int	AForm::getGradeExec() const {
	return _executeGrade;
}

// Bureaucratによる署名処理
void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (this->_signGrade < bureaucrat.getGrade())
		throw GradeTooLowException();
	this->_isSigned = true;
}

//
void AForm::execute(Bureaucrat const &executor) const {
	(void)executor;
}

// 出力演算子のオーバーロード
std::ostream &operator<<(std::ostream &o, const AForm &form) {
	o << "Name: " << form.getName() << ", is Signed: " << form.getSigned() << ", grade required to sign: " << form.getGradeSign() << ", grade required to execute: " << form.getGradeExec() << std::endl;
	return o;
}
