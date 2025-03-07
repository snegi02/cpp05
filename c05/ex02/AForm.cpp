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

#include "AForm.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute): name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    checkGrade(gradeToSign);
    checkGrade(gradeToExecute);
}

AForm::~AForm(){}

const std::string& AForm::getName() const
{
    return name;
}

const std::string& AForm::getTarget() const
{
    return target;
}

bool AForm::isSigned() const
{
    return signedStatus;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if(bureaucrat.getGrade() > gradeToSign)
        throw AForm::GradeTooLowException();
    signedStatus = true;
}

void AForm::beExecute(const Bureaucrat& bureaucrat) const
{
    if(bureaucrat.getGrade() > gradeToExecute)
        throw AForm::GradeTooLowException();
}

void AForm::checkExecution(const Bureaucrat& executor)const
{
    if(!isSigned())
        throw AForm::FormNotSignedException();
    if(executor.getGrade() > gradeToExecute)
        throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char* AForm::GradeTooLowException:: what() const throw()
{
    return "Grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed!";
}

void AForm::checkGrade(int grade) const
{
    if(grade < 1)
        throw::AForm::GradeTooHighException();
    else if (grade > 150)
        throw::AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
    out<<"Form Name: " << form.getName() << "\nsigned status: " << form.isSigned()
    << "\nGrade To Sign: " << form.getGradeToSign() << "\nGrade to Execute: " << form.getGradeToExecute();
    return out;
}
