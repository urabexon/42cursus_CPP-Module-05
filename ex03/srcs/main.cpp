/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:48:45 by hirokiurabe       #+#    #+#             */
/*   Updated: 2025/03/11 21:25:35 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

// フォームの情報を出力して署名・実行する関数
void exeForm(Bureaucrat& bureaucrat, AForm* form) {
    if (!form)
		return;
    std::cout << *form;
    bureaucrat.signForm(*form);
    bureaucrat.executeForm(*form);
    delete form;
}

int main() {
    Bureaucrat taro("taro", 1);
    Bureaucrat kana("kana", 42);
    std::cout << taro << kana;

    Intern intern;

    try {
        std::cout << std::endl << "< ----- Shrubbery Form Test ----- >" << std::endl;
        AForm* shrubberyForm = NULL;
        try {
            shrubberyForm = intern.makeForm("shrubbery creation", "garden");
            exeForm(taro, shrubberyForm);
        } catch (std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

        std::cout << std::endl << "< ----- Robotomy Form Test ----- >" << std::endl;
        AForm* robotomyForm = NULL;
        try {
            robotomyForm = intern.makeForm("robotomy request", "patient");
            exeForm(taro, robotomyForm);
        } catch (std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

        std::cout << std::endl << "< ----- Presidential Pardon Form Test ----- >" << std::endl;
        AForm* pardonForm = NULL;
        try {
            pardonForm = intern.makeForm("presidential pardon", "criminal");
            exeForm(taro, pardonForm);
        } catch (std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

        std::cout << std::endl << "< ----- Non-existent Form Test ----- >" << std::endl;
        try {
            AForm* invalidForm = intern.makeForm("unknown request", "target");
            exeForm(taro, invalidForm);
        } catch (std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    } catch (std::exception& e) {
        std::cout << "Unexpected error occurred: " << e.what() << std::endl;
    }
    return 0;
}
