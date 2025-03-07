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


int main() {
    try {
            Bureaucrat bob("bob", 5);
            ShrubberyCreationForm shrubberyForm("home");
            RobotomyRequestForm Robo("ro");
            PresidentialPardonForm perp("alex");
            PresidentialPardonForm abc(perp);
            bob.signForm(shrubberyForm);
            bob.signForm(Robo);
            bob.signForm(perp);
            shrubberyForm.execute(bob);
            Robo.execute(bob);
            perp.execute(bob);
            abc.execute(bob);

           Bureaucrat sheetal("Sheetal", 130);
            sheetal.executeForm(shrubberyForm);

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
