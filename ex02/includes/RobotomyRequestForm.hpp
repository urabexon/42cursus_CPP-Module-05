/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:33:38 by hirokiurabe       #+#    #+#             */
/*   Updated: 2025/03/08 21:49:36 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm {
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
		~RobotomyRequestForm();

		void execute(Bureaucrat const &executor) const;

	private:
		const std::string _target;
		RobotomyRequestForm();
};

std::ostream& operator<<(std::ostream &o, const RobotomyRequestForm &aform);

#endif
