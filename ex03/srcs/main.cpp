/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:48:45 by hirokiurabe       #+#    #+#             */
/*   Updated: 2025/03/09 22:25:30 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

// フォームの情報を出力して署名・実行する関数
void exe(const Bureaucrat& bureaucrat, AForm& form) {
	std::cout << form;
	bureaucrat.signForm(form);
	bureaucrat.executeForm(form);
}

int	main() {
	Bureaucrat taro("taro", 1);
	Bureaucrat kana("kana", 42);
	std::cout << taro << kana;

	Intern intern;

	try {
		// ShrubberyCreationForm（木のアスキーアート作成）
		{
			std::cout << std::endl << "< shrubbery >"  << std::endl << std::endl;
			AForm* form = NULL;
			try {
				// インターンがフォームを作成
				form = intern.makeForm("shrubbery creation", "sample1");
			} catch (std::exception& e) {
				std::cout << "Error: " << e.what() << std::endl;
			}
			if (form) {
				exe(taro, *form);
				delete form; // 署名＆実行してからメモリ解放
			}
		}
		// RobotomyRequestForm（50%の確率でロボトミー手術する）
		{
			std::cout << std::endl << "< robotomy >"  << std::endl << std::endl;
			AForm* form = NULL;
			try {
				form = intern.makeForm("robotomy request", "sample2");
			} catch (std::exception& e) {
				std::cout << "Error: " << e.what() << std::endl;
			}
			if (form) {
				exe(taro, *form);
				delete form;
			}
		}

		// PresidentialPardonForm（大統領フォーム）
		{
			std::cout << std::endl << "< presidential >"  << std::endl << std::endl;
			AForm* form = NULL;
			try {
				form = intern.makeForm("presidential pardon", "sample3");
			} catch (std::exception& e) {
				std::cout << "Error: " << e.what() << std::endl;
			}
			if (form) {
				exe(taro, *form);
				delete form;
			}
		}
		// 署名されていないフォームの実行（エラー）
		{
			std::cout << std::endl << "< execute unsigned form >"  << std::endl << std::endl;
			AForm* form = NULL;
			try {
				form = intern.makeForm("presidential pardon", "sample4");
			} catch (std::exception& e) {
				std::cout << "Error: " << e.what() << std::endl;
			}
			if (form) {
				std::cout << *form;
				taro.executeForm(*form); // 署名なしのためエラー
				delete form;
			}
		}
		// 低すぎるグレードの官僚がフォームを実行しようとするとエラー
		{
			std::cout << std::endl << "< too low >"  << std::endl << std::endl;
			AForm* form = NULL;
			try {
				form = intern.makeForm("presidential pardon", "sample5");
			} catch (std::exception& e) {
				std::cout << "Error: " << e.what() << std::endl;
			}
			if (form) {
				taro.signForm(*form);    // taro（グレード1）が署名（成功）
				kana.executeForm(*form); // kana（グレード42）が実行（失敗）
				delete form;
			}
		}
		// 存在しないフォームリクエストするとエラー
		{
			std::cout << std::endl << "< not exist form >"  << std::endl << std::endl;
			AForm* form = NULL;
			try {
				form = intern.makeForm("hello", "sample5");
			} catch (std::exception& e) {
				std::cout << "Error: " << e.what() << std::endl;
			}
			if (form) {
				taro.signForm(*form);
				kana.executeForm(*form);
				delete form;
			}
		}
	} catch (std::exception& e) {
		std::cout << "Unexpected error occurred: " << e.what() << std::endl;
	}
	return 0;
}
