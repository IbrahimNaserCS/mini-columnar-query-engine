#include "csv_loader.hpp"
#include <iostream>

int main()
{
    Employee employee = parse_employee("1,25,60000");

    std::cout << "ID: " << employee.id << '\n';
    std::cout << "Age: " << employee.age << '\n';
    std::cout << "Salary: " << employee.salary << '\n';

    return 0;
}