/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:29:27 by hirokiurabe       #+#    #+#             */
/*   Updated: 2025/03/08 20:25:41 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Form_HPP
#define Form_HPP

#include <iostream>
#include "Bureaucrat.hpp"

#define MIN_GRADE 150
#define MAX_GRADE 1

class Bureaucrat; // Bureaucratクラスを参照する

class Form {
	public:
		Form(const std::string &name, int signGrade, int _executeGrade); // コンストラクタ
		Form(const Form &copy);                                          // コピーコンストラクタ
		Form &operator=(const Form &copy);                               // 代入演算子のオーバーロード
		~Form();                                                         // デストラクタ

		// アクション定義
		const std::string &getName() const;             // フォームの名前を取得する
		bool	getSigned() const;                      // フォームの署名状態を取得する(署名済みはtrue,未署名false)
		int		getGradeSign() const;                   // フォームを署名するのに必要なグレードを取得する
		int		getGradeExec() const;                   // フォームを実行するのに必要なグレードを取得する
		void	beSigned(const Bureaucrat& bureaucrat); // Bureaucratによる署名処理

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
		const int _signGrade;    // 署名に必要なグレード
		const int _executeGrade; // 実行に必要なグレード
		bool _isSigned;          // フォームの署名チェック
		Form();                  // デフォルトコンストラクタ(課題要件のため記載)
};

// 出力演算子のオーバーロード
std::ostream &operator<<(std::ostream &o, const Form& Form);

#endif
