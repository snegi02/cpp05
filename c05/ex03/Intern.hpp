
#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

class ShrubberyCreationForm;
class Intern
{
    private:
        static AForm* ShrubberyCreationForm(const std::string& target);
        static AForm* RobotomyRequestForm(const std::string& target);
        static AForm* PresidentialPardonForm(const std::string& target);
        
    public:
        Intern();
        ~Intern();
        AForm* makeForm(const std::string& name, const std::string& target);
};

#endif
