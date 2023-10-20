#include "shell.h"

/**
 * _eputs - Output an input string to stderr.
 * @str: The string to be displayed.
 *
 * Return: Nothing.
 */
void _eputs(char *str) {
    if (!str)
        return;

    while (*str != '\0') {
        _eputchar(*str++);
    }
}

/**
 * _eputchar - Send the character 'c' to stderr.
 * @c: The character to be printed.
 *
 * Return: On success, return 1.
 * On error, return -1, and set errno appropriately.
 */
int _eputchar(char c) {
    static int i;
    static char buffer[WRITE_BUF_SIZE];

    if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE) {
        write(2, buffer, i);
        i = 0;
    }

    if (c != BUF_FLUSH)
        buffer[i++] = c;

    return 1;
}

/**
 * _putfd - Write the character 'c' to the specified file descriptor.
 * @c: The character to be printed.
 * @fd: The file descriptor to write to.
 *
 * Return: On success, return 1.
 * On error, return -1, and set errno appropriately.
 */
int _putfd(char c, int fd) {
    static int i;
    static char buffer[WRITE_BUF_SIZE];

    if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE) {
        write(fd, buffer, i);
        i = 0;
    }

    if (c != BUF_FLUSH)
        buffer[i++] = c;

    return 1;
}

/**
 * _putsfd - Output an input string to the specified file descriptor.
 * @str: The string to be displayed.
 * @fd: The file descriptor to write to.
 *
 * Return: The count of characters written.
 */
int _putsfd(char *str, int fd) {
    int characterCount = 0;

    if (!str)
        return 0;

    while (*str) {
        characterCount += _putfd(*str++, fd);
    }

    return characterCount;
}

