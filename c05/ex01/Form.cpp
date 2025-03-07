/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snegi <snegi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:47:18 by snegi             #+#    #+#             */
/*   Updated: 2024/08/28 14:47:19 by snegi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute): name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    checkGrade(gradeToSign);
    checkGrade(gradeToExecute);
}

Form::~Form(){}

const std::string& Form::getName() const
{
    return name;
}

bool Form::isSigned() const
{
    return signedStatus;
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

int Form::getGradeToExecute() const
{
    return gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if(bureaucrat.getGrade() > gradeToSign)
    {
        throw Form::GradeTooLowException();
    }
    signedStatus = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char* Form::GradeTooLowException:: what() const throw()
{
    return "Grade too low!";
}

void Form::checkGrade(int grade) const
{
    if(grade < 1)
        throw::Form::GradeTooHighException();
    else if (grade > 150)
        throw::Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
    out<<"Form Name: " << form.getName() << "\nsigned status: " << form.isSigned()
    << "\nGrade To Sign: " << form.getGradeToSign() << "\nGrade to Execute: " << form.getGradeToExecute();
    return out;
}
