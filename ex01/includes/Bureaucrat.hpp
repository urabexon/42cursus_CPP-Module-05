/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:29:23 by hirokiurabe       #+#    #+#             */
/*   Updated: 2025/03/07 19:13:43 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <iostream>
#include "Form.hpp"

#define MIN_GRADE 150
#define MAX_GRADE 1

class Form;

class Bureaucrat {
    public:
        Bureaucrat(const std::string &name, int grade); // コンストラクタ
        Bureaucrat(const Bureaucrat &copy);             // コピーコンストラクタ
        Bureaucrat &operator=(const Bureaucrat &copy);  // 代入演算子のオーバーロード
        ~Bureaucrat();                                  // デストラクタ

        // アクション定義
        const std::string &getName() const; // 名前取得のためのゲッター
        int		getGrade() const;           // グレード取得のためのゲッター
        void	incrementGrade();           // グレードを増やすためのメンバ関数
        void	decrementGrade();           // グレードを減らすためのメンバ関数
		void	signForm(Form& form) const; //
		

        // 例外クラス定義
        // グレードが低すぎる場合の例外処理用
        class GradeTooLowException : public std::exception {
            const char *what() const throw(); 
        };

        // グレードが高すぎる場合の例外処理用
        class GradeTooHighException : public std::exception {
            const char *what() const throw();
        };

    private:
        const std::string _name; // 名前
        int _grade;              // グレード
        
};

#endif
