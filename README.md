# Array Analysis in C

This project implements a function in C that calculates and returns the average, maximum, and minimum values of an array with "n" positions. Additionally, it returns a copy of the input array containing only the even numbers, as well as the size of this new array.

## Table of Contents
- [Features](#features)
- [How to Compile and Run](#how-to-compile-and-run)
- [Usage Examples](#usage-examples)
- [Future Improvements](#future-improvements)

## Features

- **Flexible Input Options:** Choose between manual input or automatic random generation of the array.
- **Statistical Calculations:** Computes the average, maximum, and minimum values.
- **Even Number Filtering:** Creates a new array that contains only the even numbers.
- **Dynamic Memory Management:** Uses efficient memory allocation and reallocation techniques with error handling.

## How to Compile and Run

### Requirements
- A C compiler (e.g., GCC)
- A Linux, macOS, or Windows environment with C compilation support

### Compilation

Compile the project using the following command:

```bash
gcc -Iinclude .\\src\\array_analysis.c .\\src\\main.c -o array_analysis
```

### Execution
```bash
.\\array_analysis
```
Follow the on-screen instructions to either manually enter the array values or generate a random array.

## Usage Examples

### Manual Input

- **Choose the manual input option.**
- **Specify the number of elements and then enter each value when prompted.**

### Automatic Generation

- **Choose the automatic generation option.**
- **Provide the number of elements, along with the minimum and maximum values.**
- **The generated array and the computed results will be displayed.**
