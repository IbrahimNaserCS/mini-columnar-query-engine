#include "csv_loader.hpp"
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

Employee parse_employee(const std::string &line)
{
    auto target = ',';
    auto count = std::count(line.begin(), line.end(), target);
    if (count != 2)
    {
        throw std::runtime_error("Too many / too few commas");
    }
    std::istringstream iss(line);
    std::string header{};
    std::string id_string{};
    std::getline(iss, id_string, ',');
    std::string age_string{};
    std::getline(iss, age_string, ',');
    std::string salary_string{};
    std::getline(iss, salary_string, ',');
    if (id_string.empty() or age_string.empty() or salary_string.empty())
    {
        throw std::runtime_error("Missing one or more fields");
    }
    std::size_t pos;
    auto id = std::stoi(id_string, &pos);
    if (pos != id_string.size())
    {
        throw std::invalid_argument("Non-numeric characters in id");
    }
    auto age = std::stoi(age_string, &pos);
    if (pos != age_string.size())
    {
        throw std::invalid_argument("Non-numeric characters in age");
    }
    auto salary = std::stod(salary_string, &pos);
    if (pos != salary_string.size())
    {
        throw std::invalid_argument("Non-numeric characters in salary");
    }
    if (!std::isfinite(salary))
    {
        throw std::out_of_range("Salary is not finite");
    }
    return Employee{id, age, salary};
}

std::vector<Employee> load_employees(const std::string &filename)
{
    std::vector<Employee> employees;
    std::ifstream inf{filename};
    if (!inf)
    {
        throw std::runtime_error("Failed to open file");
    }
    std::string str_input{};
    std::getline(inf, str_input);
    if (str_input != "id,age,salary")
    {
        throw std::runtime_error("Improper header");
    }
    while (std::getline(inf, str_input))
    {
        employees.push_back(parse_employee(str_input));
    }
    return employees;
}