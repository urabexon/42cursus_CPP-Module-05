/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:29:27 by hirokiurabe       #+#    #+#             */
/*   Updated: 2025/03/07 19:53:04 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Form_HPP
#define Form_HPP

#include <iostream>
#include "Bureaucrat.hpp"

#define MIN_GRADE 150
#define MAX_GRADE 1

class Bureaucrat;

class Form {
	public:
		Form(const std::string &name, int signGrade, int _executeGrade);
		Form(const Form &copy);
		Form &operator=(const Form &copy);
		~Form();

		// アクション定義
		const std::string&	getName() const;
		bool	getSigned() const;
		int		getGradeSign() const;
		int		getGradeExec() const;
		void	beSigned(const Bureaucrat& bureaucrat);

		// 例外クラス定義
		class GradeTooLowException : public std::exception {
			const char *what() const throw();
		};

		class GradeTooHighException : public std::exception {
			const char *what() const throw();
		};
		
	private:
		const std::string _name;
		const int _signGrade;
		const int _executeGrade;
		bool _is_signed;
};

// 出力演算子のオーバーロード
std::ostream &operator<<(std::ostream &o, const Form& Form);

#endif
