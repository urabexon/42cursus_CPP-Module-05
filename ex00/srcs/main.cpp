/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirokiurabe <hirokiurabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:26:19 by hirokiurabe       #+#    #+#             */
/*   Updated: 2025/03/05 20:23:31 by hirokiurabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 1);
        std::cout << bob;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        Bureaucrat hima("hima", 150);
        std::cout << hima;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}
