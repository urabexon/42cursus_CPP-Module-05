/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:33:25 by hirokiurabe       #+#    #+#             */
/*   Updated: 2025/03/08 21:47:33 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <iostream>
#include "AForm.hpp"

#define MIN_GRADE 150
#define MAX_GRADE 1

class AForm;

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
		void	signForm(Form &form) const; // Bureaucratがフォームを署名するためのメンバ関数

		// 
		void	executeForm(AForm const &form) const;

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
        Bureaucrat();			 // デフォルトコンストラクタ(課題要件のため記載)
};

// 出力演算子のオーバーロード
std::ostream &operator<<(std::ostream &o, const Bureaucrat &bureaucrat);

#endif
