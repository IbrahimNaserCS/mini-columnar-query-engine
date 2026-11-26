# Mini Columnar Query Engine

An investigation into the tradeoffs between row-oriented and column-oriented storage. An initial step towards building deeper understanding of database internals as well as the choices that go into designing a database. Written in C++20.

## Current Implementation

Two classes, `RowStore` and `ColumnStore`. The former stores an `std::vector` internally of `Employee` structs, which include all the information needed to describe an employee. The latter stores 3 `std::vector` objects, each containing one column of the data. The three operations are `insert`, `get`, and `size`. 

## Memory Layout Investigation

The size of the `Employee` struct is 16 bytes. Its alignment is 8 bytes, determined by the strictest alignment of the `double` it carries. In the `ColumnStore`, ages are separated by 4 bytes while salaries are spaced by 8 bytes. This contrasts from `RowStore`, where the gap is larger. 

## Design Decisions

The `ColumnStore::insert` function includes a try catch block. This is needed to maintain consistency between the three vectors. If one insertion succeeds, and another fails, the three will be inconsistent which is incoherent. 

## CSV Format

A CSV file must follow the following format:
- A header which matches exactly 'id,age,salary'
- Subsequent rows that match this formatting
- id and age are integers
- salary is a double

## Loader Behavior

The loader parses the CSV, and after validating it, returns an `std::vector<Employee>` containing the employees in the file.

## Building and Testing

To build and test:

```
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
ctest --test-dir build --output-on-failure
```

