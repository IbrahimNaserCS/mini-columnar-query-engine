#pragma once

#include "storage.hpp"
#include <string>

Employee parse_employee(const std::string& line);

std::vector<Employee> load_employees(const std::string& filename);