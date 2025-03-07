/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snegi <snegi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:47:23 by snegi             #+#    #+#             */
/*   Updated: 2024/08/28 14:47:25 by snegi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool signedStatus;
        const int gradeToSign;
        const int gradeToExecute;
        const std::string target;
        void checkGrade(int grade) const;

    protected:
        void checkExecution(const Bureaucrat& executor) const;

    public:
        AForm(const std::string& name, int gradeToSign, int gradeToExecute);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();
        const std::string& getName() const;
        virtual const std::string& getTarget() const;
        bool isSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(const Bureaucrat& bureaucrat);
        void beExecute(const Bureaucrat& bureaucrat) const;
        virtual void execute(Bureaucrat const &  bureaucrat) const = 0;
    class GradeTooHighException : public std::exception
    {
        public:
            const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw();
    };
    class FormNotSignedException:public std::exception
    {
        public:
            const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream &out, const AForm &form);

#endif
