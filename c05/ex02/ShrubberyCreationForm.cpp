/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snegi <snegi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:28:36 by snegi             #+#    #+#             */
/*   Updated: 2024/08/29 13:28:38 by snegi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    :AForm("ShrubberyCreationForm", 145, 137), target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):AForm(other), target(other.target)
{}
    
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    checkExecution(executor);
    std::ofstream outfile((getTarget() + "_shrubbery").c_str());
    if(!outfile)
    {
        std::cerr << "Could not open the file." << std::endl;
        return;
    }
     outfile << "   /\\\n"
            << "  /  \\\n"
            << " /    \\\n"
            << "/______\\\n"
            << "  ||||  \n";
    outfile.close();
}

const std::string& ShrubberyCreationForm::getTarget() const
{
    return target;
}
