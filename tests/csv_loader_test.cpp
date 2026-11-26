#include "csv_loader.hpp"

#include <cassert>

int main()
{
    Employee parsed_employee = parse_employee("1,25,60000");
    assert(parsed_employee.id == 1);
    assert(parsed_employee.age == 25);
    assert(parsed_employee.salary == 60'000);
    auto exception_thrown = false;
    try
    {
        parse_employee("1,,60000");
    }
    catch(...)
    {
        exception_thrown = true;
    }
    assert(exception_thrown);
    exception_thrown = false;
    try
    {
        parse_employee("1,25");
    }
    catch(...)
    {
        exception_thrown = true;
    }
    assert(exception_thrown);
    exception_thrown = false;
    try
    {
        parse_employee("1,25,60000,extra");
    }
    catch(...)
    {
        exception_thrown = true;
    }
    assert(exception_thrown);
    exception_thrown = false;
    try
    {
        parse_employee("1,25,60000,");
    }
    catch(...)
    {
        exception_thrown = true;
    }
    assert(exception_thrown);
    exception_thrown = false;
    try
    {
        parse_employee("1,25,nan");
    }
    catch(...)
    {
        exception_thrown = true;
    }
    assert(exception_thrown);
    exception_thrown = false;
    std::vector<Employee> employees = load_employees("data/employees.csv");
    assert(employees.size() == 3);
    assert(employees.at(0).id == 1);
    assert(employees.at(0).age == 25);
    assert(employees.at(0).salary == 60'000);
    assert(employees.at(1).id == 2);
    assert(employees.at(1).age == 32);
    assert(employees.at(1).salary == 85'000);
    assert(employees.at(2).id == 3);
    assert(employees.at(2).age == 41);
    assert(employees.at(2).salary == 110'000);
    try
    {
        load_employees("hello");
    }
    catch(...)
    {
        exception_thrown = true;
    }
    assert(exception_thrown);
    exception_thrown = false;
    try
    {
        load_employees("data/malformed.csv");
    }
    catch(...)
    {
        exception_thrown = true;
    }
    assert(exception_thrown);
    exception_thrown = false;
    RowStore rs{};
    ColumnStore cs{};
    for (const auto& employee: employees)
    {
        rs.insert(employee);
        cs.insert(employee);
    }
    assert(rs.size() == 3);
    assert(cs.size() == 3);
    for (std::size_t i{}; i < employees.size(); ++i)
    {
        const Employee& expected = employees[i];

        Employee row = rs.get(i);
        Employee col = cs.get(i);

        assert(row.id == expected.id);
        assert(row.age == expected.age);
        assert(row.salary == expected.salary);

        assert(col.id == expected.id);
        assert(col.age == expected.age);
        assert(col.salary == expected.salary);
    }
}