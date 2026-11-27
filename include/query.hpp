#pragma once

#include <optional>

#include "storage.hpp"

std::optional<double> average_salary_row(const RowStore& row_store);

std::optional<double> average_salary_col(const ColumnStore& col_store);