# get_next_line

## Overview

The `get_next_line` project is designed to create a function that reads a line from a file descriptor, returning it one line at a time. This function handles reading from various file descriptors, including standard input, files, and more, without memory leaks.

## Objectives

- Create a function `get_next_line` that reads a line from a given file descriptor.
- Handle multiple file descriptors simultaneously.
- Ensure no memory leaks occur during the process.

## Features

- Read a line from any file descriptor.
- Manage multiple file descriptors concurrently.
- Handle large files efficiently.
- No memory leaks.

## Requirements

- Only the allowed functions: `read`, `malloc`, `free`.
- Handle both `BUFFER_SIZE` (defined during compilation) and standard input.
- Compatible with both Linux and macOS.

## Installation

Clone the repository:

```bash
git clone https://github.com/yourusername/get_next_line.git
cd get_next_line
