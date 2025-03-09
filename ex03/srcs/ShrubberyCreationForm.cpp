/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:48:50 by hirokiurabe       #+#    #+#             */
/*   Updated: 2025/03/09 21:59:35 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target) {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
	if (this != &copy) {
		// メンバ変数を持たないため、何もしない
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > this->getGradeExec())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getSigned() == false)
		throw (AForm::FormNotSignedException());
	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file)
		throw std::runtime_error("Error: Unable to open the file " + _target + "_shrubbery");
	if (file.is_open()) {
		file << "     *\n";
		file << "    ***\n";
        file << "   *****\n";
        file << "  *******\n";
        file << " *********\n";
        file << "    |||\n\n\n";
        file << "     *\n";
        file << "    ***\n";
        file << "   *****\n";
        file << "  *******\n";
        file << " *********\n";
        file << "    |||\n";
        file.close();
	} else {
		std::cerr << "Unable to open file." << std::endl;
	}
}

std::ostream& operator<<(std::ostream &o, const ShrubberyCreationForm& aform) {
	o << "Name: " << aform.getName() << ", is Signed: " << aform.getSigned() << ", grade required to sign: " << aform.getGradeSign() << ", grade required to execute: " << aform.getGradeExec() << std::endl;
	return o;
}
