# Shell Functions README

This repository contains several C functions that are useful for building a simple shell program. These functions handle tasks such as tokenizing input strings, validating user input, string manipulation, and signal handling.

## Files

1. **shell.h**: Header file containing function declarations and necessary includes.
2. **helper_functions.c**: This code defines a signal handler for Ctrl+C interrupts in a shell program, along with functions for string concatenation and custom memory reallocation.
3. **tokenizers.c**: This code defines two functions, hsh_tokenizer and tokenizer_path, which tokenize input strings based on specific delimiters and return arrays of tokens.
4. **validators.c**: This code comprises two functions, validate_input and validate_spaces, used for input validation in a shell program. The validate_input function checks if specified files exist in the system or in the PATH environment variable, while validate_spaces verifies if an input string contains only whitespace characters. 
5. **README.md**: This README file.
6. **man_1_simple_shell**: This is a manual page.
7. **AUTORS**: This file lists all contributors to the repository.

## Functions

### 1. `hsh_tokenizer`

- **Description**: Tokenizes input strings based on a specific delimiter.
- **Parameters**: 
  - `char *input`: Input string to be tokenized.
- **Return**: Array of tokens.

### 2. `tokenizer_path`

- **Description**: Tokenizes input strings based on a different delimiter than `hsh_tokenizer`.
- **Parameters**: 
  - `char *input`: Input string to be tokenized.
- **Return**: Array of tokens.

### 3. `validate_input`

- **Description**: Validates user input arguments and checks for the existence of specified files.
- **Parameters**: 
  - `char **arguments`: Array of input arguments.
- **Return**: Validated input or error message.

### 4. `validate_spaces`

- **Description**: Checks if a given input string contains only whitespace characters.
- **Parameters**: 
  - `char *input`: Input string to be validated.
- **Return**: Flag indicating presence of spaces.

### 5. `sigintH`

- **Description**: Signal handler for SIGINT (Ctrl+C) that writes a custom prompt after interruption.
- **Parameters**: 
  - `int signum`: Signal number.
- **Return**: None.

### 6. `str_concat`

- **Description**: Concatenates two strings and returns a pointer to the concatenated string.
- **Parameters**: 
  - `char *s1`: First string.
  - `char *s2`: Second string.
- **Return**: Pointer to the concatenated string.

### 7. `_realloc`

- **Description**: Custom memory reallocation function to resize dynamically allocated memory blocks.
- **Parameters**: 
  - `void *ptr`: Pointer to memory block to be reallocated.
  - `unsigned int old_size`: Old size of the memory block.
  - `unsigned int new_size`: New size of the memory block.
- **Return**: Pointer to the reallocated memory.

## Usage

To use these functions in your shell program:

1. Include the `shell.h` header file in your source files.
2. Implement the necessary logic to call these functions as required by your shell program.

## 


