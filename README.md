# C_Vector
Simple implementation of Vector in C.<br/>
This project use CLove-Unit for all tests.<br/>[GitHub Repository of CLove-Unit](https://github.com/fdefelici/clove-unit/blob/master/README.md)

# Usage

You could create a dll using `build.bat` (it require clang.exe)

## Command with clang.exe
```
clang -shared -o library/vector.dll -I include src/vector.c
```
N.B.<br>
It requires that the `library` folder exists

## Use it
Copy the content of `library` and `include` folders where you want and use it in your code.

# API

## Functions

<table>
    <thead>
        <tr>
            <th>Function</th>
            <th colspan=2><center>Parametrs</center></th>
            <th colspan=2><center>Return</center></th>
            <th>Explanation</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>vector_create</td>
            <td>double</td>
            <td>The capacity of the vector. It represents the percentage of memory that the data occupies compared to that allocated<br/>It's not mandatory<br/>If present, it must be a number between 0.1 and 1</td>
            <td>vector_t*</td>
            <td>Pointer to created vector or NULL on failure</td>
            <td>Allocate space in memory for vector structure</td>
        </tr>
        <tr>
            <td>vector_free</td>
            <td>vector_t*</td>
            <td>Pointer to vector structure</td>
            <td>void</td>
            <td></td>
            <td>Release all memory allocated</td>
        </tr>
        <tr>
            <td rowspan=2>vector_push</td>
            <td>vector_t*</td>
            <td>Pointer to vector structure</td>
            <td rowspan=2>void*</td>
            <td rowspan=2>Pointer to the pushed item or NULL on failure</td>
            <td rowspan=2>Adds an item to the end of the vector</td>
        </tr>
        <tr>
            <td>void*</td>
            <td>Pointer to the item to be append</td>
        </tr>
        <tr>
            <td rowspan=3>vector_insert</td>
            <td>vector_t*</td>
            <td>Pointer to vector structure</td>
            <td rowspan=3>void*</td>
            <td rowspan=3>Pointer to the pushed item or NULL on failure</td>
            <td rowspan=3>Adds an item to the end of the vector</td>
        </tr>
        <tr>
            <td>void*</td>
            <td>Pointer to the item to be append</td>
        </tr>
        <tr>
            <td>size_t</td>
            <td>Index where the item must be insert</td>
        </tr>
        <tr>
            <td rowspan=2>vector_get_at</td>
            <td>vector_t*</td>
            <td>Pointer to vector structure</td>
            <td rowspan=2>void*</td>
            <td rowspan=2>Pointer to the item or NULL on failure</td>
            <td rowspan=2>Return item at index position or NULL if index is not in valid range</td>
        </tr>
        <tr>
            <td>size_t</td>
            <td>Index of the desired item<br/>Index must be in range [0, vector.count[</td>
        </tr>
        <tr>
            <td>vector_get_first</td>
            <td>vector_t*</td>
            <td>Pointer to vector structure</td>
            <td>void*</td>
            <td>Pointer to the first item or NULL</td>
            <td>Return item at first position of the vector</td>
        </tr>
        <tr>
            <td>vector_get_last</td>
            <td>vector_t*</td>
            <td>Pointer to vector structure</td>
            <td>void*</td>
            <td>Pointer to the last item or NULL</td>
            <td>Return item at last position of the vector</td>
        </tr>
        <tr>
            <td rowspan=2>vector_get_index_of</td>
            <td>vector_t*</td>
            <td>Pointer to vector structure</td>
            <td rowspan=2>size_t</td>
            <td rowspan=2>Index of desired item or NULL on failure</td>
            <td rowspan=2>Return the index of desired item or NULL if item is not in vector</td>
        </tr>
        <tr>
            <td>void*</td>
            <td>The item to search</td>
        </tr>
        <tr>
            <td rowspan=2>vector_remove</td>
            <td>vector_t*</td>
            <td>Pointer to vector structure</td>
            <td rowspan=2>void*</td>
            <td rowspan=2>Pointer to the removed item or NULL on failure</td>
            <td rowspan=2>Removed the given item of the vector and returns it</td>
        </tr>
        <tr>
            <td>void*</td>
            <td>The item to remove</td>
        </tr>
        <tr>
            <td rowspan=2>vector_remove_at</td>
            <td>vector_t*</td>
            <td>Pointer to vector structure</td>
            <td rowspan=2>void*</td>
            <td rowspan=2>Pointer to the removed item or NULL on failure</td>
            <td rowspan=2>Removed the item at the given index and returns it</td>
        </tr>
        <tr>
            <td>size_t</td>
            <td>Index of the item to be removed<br/>Index must be in range [0, vector.count[</td>
        </tr>
    </tbody>
</table>