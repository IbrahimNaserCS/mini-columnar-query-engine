#include "query.hpp"

std::optional<double> average_salary_row(const RowStore& row_store)
{
    double total_salaries{};
    std::size_t over_30{};
    for (std::size_t i{}; i != row_store.size(); ++i)
    {
        auto employee = row_store.get(i);
        if (employee.age > 30)
        {
            total_salaries += employee.salary;
            over_30++;
        }
    }
    if (over_30) return total_salaries / over_30;
    return std::nullopt;
}

std::optional<double> average_salary_col(const ColumnStore& col_store)
{
    double total_salaries{};
    std::size_t over_30{};
    for (std::size_t i{}; i != col_store.size(); ++i)
    {
        if (col_store.get_age(i) > 30)
        {
            total_salaries += col_store.get_salary(i);
            over_30++;
        }
    }
    if (over_30) return total_salaries / over_30;
    return std::nullopt;
}