/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:29:32 by hirokiurabe       #+#    #+#             */
/*   Updated: 2025/03/08 19:40:22 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	printError(std::exception& e) {
	std::cout << "Error: " << e.what() << std::endl;
}

int	main() {
	Bureaucrat taro("taro", 42);
	std::cout << taro;

	// Case1(高すぎる、低すぎる範囲外のため例外発生)
	try {
		Form sample("sample", 1000, 1);
	} catch (std::exception& e) {
		printError(e);
	}
	try {
		Form sample("sample", 42, 0);
	} catch (std::exception& e) {
		printError(e);
	}

	// Case2(署名する)
	try {
		Form sample1("sample1", 42, 42);
		Form sample2("sample2", 1, 1);
		// 作成したフォームの情報を出力する
		std::cout << std::endl << sample1 << sample2;
		// taroがsample1 (署名グレード42)に署名
		taro.signForm(sample1);
		// sample1の署名状態を確認する
		std::cout << sample1;
		// 既に署名されたsample1に再度署名してもエラーにならない
		taro.signForm(sample1);
		// taroがsample2(署名グレード1)に署名する場合、グレード不足のため例外が発生する
		taro.signForm(sample2);
	} catch (std::exception& e) {
		printError(e);
	}

	return 0;
}
