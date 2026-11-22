#include "storage.hpp"

#include <cassert>
#include <iostream>
#include <stdexcept>

int main()
{
    RowStore rows;
    ColumnStore columns;

    // Test 1: Empty stores
    assert(rows.size() == 0);
    assert(columns.size() == 0);

    // TODO: Test 2 - Insert three employees
    std::vector<Employee> employees;
    Employee employee_one { 1, 25, 60000 };
    Employee employee_two { 2, 32, 85000 };
    Employee employee_three { 3, 41, 110000 };
    employees.push_back(employee_one);
    employees.push_back(employee_two);
    employees.push_back(employee_three);
    rows.insert(employees[0]);
    rows.insert(employees[1]);
    rows.insert(employees[2]);
    columns.insert(employees[0]);
    columns.insert(employees[1]);
    columns.insert(employees[2]);

    // TODO: Test 3 - Check the sizes of both stores
    assert(rows.size() == 3);
    assert(columns.size() == 3);

    // TODO: Test 4 - Retrieve employees and verify their fields
    for (std::size_t i{}; i != employees.size(); ++i)
    {
        auto row = rows.get(i);
        auto col = columns.get(i);
        assert(row.id == employees[i].id);
        assert(row.age == employees[i].age);
        assert(row.salary == employees[i].salary);
        assert(col.id == employees[i].id);
        assert(col.age == employees[i].age);
        assert(col.salary == employees[i].salary);
    }

    // TODO: Test 5 - Verify out-of-range access throws
    auto exception_thrown = false;
    try
    {
        rows.get(3);
        columns.get(3);
    }
    catch(const std::out_of_range&)
    {
        exception_thrown = true;
    }
    assert(exception_thrown);

    std::cout << "All storage tests passed!\n";
}