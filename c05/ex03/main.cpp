/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snegi <snegi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:48:07 by snegi             #+#    #+#             */
/*   Updated: 2024/08/28 10:48:10 by snegi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    try {
            Intern someRandomIntern;
            AForm* form;
            Bureaucrat bob("bob", 5);
            form = someRandomIntern.makeForm("robotomy request", "Bender");
            form->beSigned(bob);
            bob.executeForm(*form);
            delete form;
            form = someRandomIntern.makeForm("presidential pardon", "Zaphod");
            delete form;
            form = someRandomIntern.makeForm("shrubbery creation", "home");
            delete form;
            form = someRandomIntern.makeForm("unknown form", "test");
            delete form;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
