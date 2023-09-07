/*
 * File: 100-elf_header.c
 * Auth: Bundi Victor
 */


#include "main.h"
#include <fcntl.h>
#include <stdio.h>
#include <elf.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * print_elf_header - Display information from the ELF header.
 * @elf_header: A pointer to the ELF header structure.
 */
void display_error(const char *message)
{
    dprintf(STDERR_FILENO, "Error: %s\n", message);
    exit(98);
}

/**Function to display ELF header information**/
void display_elf_header_info(Elf64_Ehdr *header)
{
    printf("Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++)
        printf("%02x ", header->e_ident[i]);
    printf("\n");

    /**You could add comments explaining these constants**/
    printf("Class:                             ");
    switch (header->e_ident[EI_CLASS])
    {
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("Invalid class\n");
            break;
    }

    /**Similar comments can be added for other switch cases**/

    printf("Entry point address:  0x%lx\n", (unsigned long)header->e_entry);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        display_error("Usage: elf_header elf_filename");

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        display_error("Cannot open file");

    Elf64_Ehdr header;
    ssize_t bytes_read = read(fd, &header, sizeof(header));
    if (bytes_read != sizeof(header))
        display_error("Cannot read ELF header");

    /**Instead of exiting immediately, **/
	/**you can print the error and continue if possible**/

    if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3)
    {
        display_error("Not an ELF file");
    }

    display_elf_header_info(&header);

    close(fd);
    return (0);
}
