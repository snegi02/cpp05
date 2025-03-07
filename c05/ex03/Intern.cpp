
#include "Intern.hpp"

Intern::Intern(){}

Intern::~Intern(){}

AForm* Intern::ShrubberyCreationForm(const std::string& target)
{
    return new ::ShrubberyCreationForm(target);
}

AForm* Intern::RobotomyRequestForm(const std::string& target)
{
    return new::RobotomyRequestForm(target);
}

AForm* Intern::PresidentialPardonForm(const std::string& target)
{
    return new:: PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
    const std::string formname[] ={ "shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (*formcreator[])(const std::string&) =  {&Intern::ShrubberyCreationForm, &Intern::RobotomyRequestForm,
        &Intern::PresidentialPardonForm};
    for (int i = 0; i < 3; i++)
    {
        if (name == formname[i])
            return formcreator[i](target);
    }
    std::cout << "Error: Form name '" << name << "' is not recognized." << std::endl;
    return NULL;
}
