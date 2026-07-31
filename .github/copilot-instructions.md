# C++ Coding Guidelines

## Language Standard

* Use C++20.
* Prefer standard library solutions.
* Do not introduce third-party dependencies unless explicitly requested.
* Keep code portable across Windows and Linux.

## Naming Convention

* Types, classes, and structs use PascalCase.

Example:

```cpp
class MeshLoader
{
};
```

* Functions use camelCase.

Example:

```cpp
bool loadMesh();
```

* Local variables and function parameters use snake_case.

Example:

```cpp
int vertex_count = 0;

bool loadMesh(const std::string& file_path);
```

* Private member variables must use snake_case with a trailing underscore.

Example:

```cpp
class Mesh
{
private:
    std::string file_path_;
    int vertex_count_;
};
```

## Comments and Documentation

* Public interfaces must use Doxygen-style comments.
* Use `/** @brief ... */` format.

Example:

```cpp
/**
 * @brief Loads mesh data from a file.
 *
 * @param file_path Path to the mesh file.
 * @return true if loading succeeds.
 */
bool loadMesh(const std::filesystem::path& file_path);
```

* Comments should explain design intent, constraints, and non-obvious logic.
* Do not add comments that only restate the code.

## Code Quality

* Prefer RAII.
* Avoid raw owning pointers.
* Use `std::span` for non-owning contiguous data access.
* Use `constexpr` where appropriate.
* Use `noexcept` when correctness allows.
* Consider thread safety when shared state is involved.

## API Design

* Do not change existing public APIs unless explicitly requested.
* Preserve existing interfaces and behavior.
* Avoid unnecessary abstractions.
* Prefer simple, maintainable designs.

## File Modification Safety

Before editing any file:

1. Check the latest file contents from the workspace.
2. Do not rely on previously generated code if the file may have changed.
3. Preserve user modifications.
4. Never silently overwrite user changes.
5. If generated changes conflict with user edits, explain the conflict before replacing code.

## Code Generation Rules

When generating code:

* Provide complete compilable implementations.
* Do not provide pseudo-code unless explicitly requested.
* Include required headers.
* Match the existing project style.

## Review Rules

When reviewing code, check:

* Correctness.
* Undefined behavior.
* Memory safety.
* Exception safety.
* Performance issues.
* Thread safety.
* API consistency.
* Naming and style compliance.
