/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:26:19 by hirokiurabe       #+#    #+#             */
/*   Updated: 2025/03/07 18:42:39 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    // Case1
    try {
		Bureaucrat john("john", 1);
		std::cout << john;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
    
    // Case2
    try {
		Bureaucrat alice("alice", 150);
		std::cout << alice;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

    // Case3 (例外パターン)
    try {
    	Bureaucrat bob("Bob", 151);
    	std::cout << bob;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

    return 0;
}
