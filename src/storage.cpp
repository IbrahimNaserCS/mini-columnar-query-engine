#include "storage.hpp"
#include <iostream>

void RowStore::insert(const Employee &employee)
{
    employees.push_back(employee);
}

Employee RowStore::get(std::size_t index) const
{
    return employees.at(index);
}

std::size_t RowStore::size() const
{
    return employees.size();
}

void ColumnStore::insert(const Employee &employee)
{
    const auto original_size = ids.size();
    try
    {
        ids.push_back(employee.id);
        ages.push_back(employee.age);
        salaries.push_back(employee.salary);
    }
    catch (...)
    {
        if (ids.size() > original_size)
            ids.pop_back();
        if (ages.size() > original_size)
            ages.pop_back();
        if (salaries.size() > original_size)
            salaries.pop_back();
        throw;
    }
}

Employee ColumnStore::get(std::size_t index) const
{
    return Employee{ids.at(index), ages.at(index), salaries.at(index)};
}

std::size_t ColumnStore::size() const
{
    return ids.size();
}

void ColumnStore::diagnostic() const
{
    for (std::size_t i{}; i != ids.size(); ++i)
    {
        std::cout << "ID at index " << i << "'s address is: " << &ids.at(i) << std::endl;
        std::cout << "Age at index " << i << "'s address is: " << &ages.at(i) << std::endl;
        std::cout << "Salary at index " << i << "'s address is: " << &salaries.at(i) << std::endl;
    }
}