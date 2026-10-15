# Minishell

Minishell is a 42 school project that implements a command-line interpreter in C, inspired by Bash. It provides an interactive prompt, reads user input, parses commands, and executes them in one or more processes.

> This project implements a subset of shell features. It is not intended to replace Bash or reproduce its complete syntax.

## Features

- Interactive prompt and command history powered by GNU Readline.
- Input validation and tokenization, with support for single and double quotes.
- Command execution and pipelines using `|`.
- Input redirection (`<`), output redirection (`>`), append redirection (`>>`), and here-documents (`<<`).
- Expansion of environment variables (`$NAME`) and the previous command's exit status (`$?`).
- Built-in commands: `echo`, `cd`, `pwd`, `env`, `export`, `unset`, and `exit`.
- Keyboard signal handling, including `Ctrl-C` and `Ctrl-\\`, with dedicated handling while entering a here-document.

## Requirements

- A Unix/Linux environment with a C compiler (`cc`) and `make`.
- GNU Readline and its development headers (for example, `libreadline-dev` on Debian or Ubuntu).

The `pedro_lib` utility library is included in the repository and built by the Makefile.

## Build and run

From the repository root:

```sh
make
./bin/minishell
```

Minishell runs interactively and does not accept command-line arguments at startup.

Example commands:

```sh
echo "Hello $USER"
pwd
cat README.md | grep Minishell
cat < README.md
echo "output" >> output.txt
cat << EOF
Type some text
EOF
```

## Make targets

| Target | Description |
| --- | --- |
| `make` or `make all` | Builds the project and creates `bin/minishell`. |
| `make clean` | Removes object files. |
| `make fclean` | Removes object files and the generated executable. |
| `make re` | Cleans and rebuilds the project. |

## Project structure

```text
.
├── Includes/                 # Main header and declarations
├── Libraries/pedro_lib/      # Project utility library
├── srcs_mandatory/
│   ├── Builtins/             # Built-in commands
│   ├── Environnement/        # Environment initialization and management
│   ├── Exec/
│   │   ├── the_exec/         # Processes, commands, and redirections
│   │   └── the_parsing/      # Command and redirection preparation
│   ├── Expands/              # Variable expansion and word processing
│   ├── Here_doc/             # Here-document handling
│   ├── Lexer/                # Tokenization
│   ├── Pre_parser/           # Preliminary syntax checks
│   ├── Signals/              # Signal handling
│   └── Zmain_functions/      # Initialization and main loop
└── Makefile                  # Build and cleanup rules
```

## Command processing

Each input line goes through syntax checks, lexical analysis, variable expansion, and command/redirection preparation before execution. Commands connected by pipes are launched with the appropriate file descriptors; built-ins are handled by the shell.

## About

An educational project in the 42 curriculum focused on systems programming in C, including processes, file descriptors, signals, environment management, and command parsing.
