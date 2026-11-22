#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

struct Employee
{
    int32_t id;
    int32_t age;
    double salary;
};

class RowStore
{
public:
    void insert(const Employee &employee);
    Employee get(std::size_t index) const;
    size_t size() const;

private:
    std::vector<Employee> employees;
};

class ColumnStore
{
public:
    void insert(const Employee &employee);
    Employee get(size_t index) const;
    std::size_t size() const;
    void diagnostic() const;

private:
    std::vector<int32_t> ids;
    std::vector<int32_t> ages;
    std::vector<double> salaries;
};