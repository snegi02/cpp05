/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snegi <snegi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:28:51 by snegi             #+#    #+#             */
/*   Updated: 2024/08/29 13:28:52 by snegi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    :AForm("RobotomyRequestForm", 72, 45), target(target){}

RobotomyRequestForm::~RobotomyRequestForm(){}

const std::string& RobotomyRequestForm::getTarget() const
{
    return target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    checkExecution(executor);
    std::cout << "Drilling noises..." << std::endl;
    if (rand() % 2)
        std::cout << getTarget() << " has been robotomized successfully." << std::endl;
    else
        std::cout<< "The robotomy on " << getTarget() << " failed." << std::endl;
}
