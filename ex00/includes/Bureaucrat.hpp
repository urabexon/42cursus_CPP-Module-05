/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirokiurabe <hirokiurabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:26:13 by hirokiurabe       #+#    #+#             */
/*   Updated: 2025/03/05 20:47:29 by hirokiurabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_hpp
#define Bureaucrat_hpp

#include <iostream>

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat {
    public:
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        ~Bureaucrat();
        Bureaucrat &operator=(const Bureaucrat &copy);

        const std::string &getName() const;
        int     getGrade() const;
        void    incrementGrade();
        void    decrementGrade();

        class GradeTooLowException : public std::exception {
            const char *what() const throw();
        };

        class GradeTooHighException : public std::exception {
            const char *what() const throw();
        };

    private:
        const std::string _name;
        int _grade;
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &bureaucrat);

#endif
