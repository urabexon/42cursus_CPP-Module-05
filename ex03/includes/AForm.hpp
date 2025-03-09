/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:48:27 by hirokiurabe       #+#    #+#             */
/*   Updated: 2025/03/09 21:19:58 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include "Bureaucrat.hpp"

#define MIN_GRADE 150
#define MAX_GRADE 1

class Bureaucrat;

class AForm {
	public:
		AForm(const std::string &name, int signGrade, int _executeGrade); // コンストラクタ
		AForm(const AForm &copy);                                         // コピーコンストラクタ
		AForm &operator=(const AForm &copy);                              // 代入演算子のオーバーロード
		virtual ~AForm();                                                 // デストラクタ

		// アクション定義
		const std::string &getName() const;
		bool	getSigned() const;
		int		getGradeSign() const;
		int		getGradeExec() const;
		void	beSigned(const Bureaucrat &bureaucrat);
		
		// 純粋仮想関数
		virtual void execute(Bureaucrat const &executor) const = 0;

		// 例外クラス定義
		// グレードが低すぎる場合の例外処理用
		class GradeTooLowException : public std::exception {
			const char *what() const throw();
		};

		// グレードが高すぎる場合の例外処理用
		class GradeTooHighException : public std::exception {
			const char *what() const throw();
		};

		// 
		class FormNotSignedException : public std::exception {
			const char *what() const throw();
		};

	protected: // protectedに変更して、派生クラスからアクセス可能にする
		const std::string _name; // 名前
		const int _signGrade;    // 署名に必要なグレード
		const int _executeGrade; // 実行に必要なグレード
		bool _isSigned;          // フォームの署名チェック
		// デフォルトコンストラクタがないと、継承先のコピーコンストラクタでエラーが発生する
		AForm();
};

// 出力演算子のオーバーロード
std::ostream &operator<<(std::ostream &o, const AForm &aform);

#endif
