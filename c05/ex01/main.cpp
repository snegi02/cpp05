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
#include "Form.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 50);
        Form taxForm("Tax Form", 45, 30);

        std::cout << bob << std::endl;
        std::cout << taxForm << std::endl;

        bob.signForm(taxForm);
        if (taxForm.isSigned() == true)
            std::cout << taxForm << std::endl;
        std::cout <<"\n" <<std::endl;
       Bureaucrat alice("Alice", 40);
       alice.signForm(taxForm);
       std::cout << taxForm << std::endl;
        
    } 
    catch (const std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
