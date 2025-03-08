/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:33:57 by hirokiurabe       #+#    #+#             */
/*   Updated: 2025/03/08 20:04:33 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void exe(const Bureaucrat& bureaucrat, AForm& form) {
	std::cout << form;
	bureaucrat.signForm(form);
	bureaucrat.executeForm(form);
}

int	main() {
	Bureaucrat taro("taro", 1);
	Bureaucrat kana("kana", 42);
	std::cout << taro << kana;
	
	try {
		{
			std::cout << std::endl << "< shrubbery >"  << std::endl << std::endl;
			ShrubberyCreationForm form("sample1");
			exe(taro, form);
		}
		{
			std::cout << std::endl << "< robotomy >"  << std::endl << std::endl;
			RobotomyRequestForm form("sample2");
			exe(taro, form);
		}
		{
			std::cout << std::endl << "< presidential >"  << std::endl << std::endl;
			PresidentialPardonForm form("sample3");
			exe(taro, form);
		}
		PresidentialPardonForm form("sample4");
		{
			std::cout << std::endl << "< execute unsigned form >"  << std::endl << std::endl;
			std::cout << form;
			taro.executeForm(form);
		}
		{
			std::cout << std::endl << "< too low >"  << std::endl << std::endl;
			taro.signForm(form);
			kana.executeForm(form);
		}
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;	
}
