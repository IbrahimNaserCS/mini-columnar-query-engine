#include "storage.hpp"

int main()
{
    ColumnStore columns;

    columns.insert(Employee{1, 25, 60000});
    columns.insert(Employee{2, 32, 85000});
    columns.insert(Employee{3, 41, 110000});

    columns.diagnostic();

    return 0;
}