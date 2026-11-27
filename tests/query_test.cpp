
#include "query.hpp"
#include "storage.hpp"

#include <cassert>
#include <initializer_list>
#include <optional>

void test_query(
    std::initializer_list<Employee> employees,
    std::optional<double> expected)
{
    RowStore rs;
    ColumnStore cs;

    for (const Employee& employee : employees)
    {
        rs.insert(employee);
        cs.insert(employee);
    }

    auto row_result = average_salary_row(rs);
    auto col_result = average_salary_col(cs);

    assert(row_result == expected);
    assert(col_result == expected);
    assert(row_result == col_result);
}

int main()
{
    // Multiple qualifying employees
    test_query({
        {1, 25, 60000},
        {2, 32, 85000},
        {3, 41, 110000}
    }, 97500.0);

    // No qualifying employees
    test_query({
        {1, 20, 60000},
        {2, 25, 85000}
    }, std::nullopt);

    // Empty stores
    test_query({}, std::nullopt);

    // Age 30 must be excluded
    test_query({
        {1, 30, 60000},
        {2, 31, 85000}
    }, 85000.0);

    // Exactly one qualifying employee
    test_query({
        {1, 22, 60000},
        {2, 45, 110000}
    }, 110000.0);

    return 0;
}