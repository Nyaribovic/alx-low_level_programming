/*
 * File: 100-elf_header.c
 * Auth: Bundi Victor
 */


#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <elf.h>

void display_error(const char *message)
{
    dprintf(STDERR_FILENO, "%s\n", message);
    exit(98);
}

void display_elf_header_info(Elf64_Ehdr *header)
{
    printf("Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++)
        printf("%02x ", header->e_ident[i]);
    printf("\n");

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

    printf("Data:                              ");
    switch (header->e_ident[EI_DATA])
    {
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("Invalid data encoding\n");
            break;
    }

    printf("Version:                           %d\n", header->e_ident[EI_VERSION]);

    printf("OS/ABI:                            ");
    switch (header->e_ident[EI_OSABI])
    {
        case ELFOSABI_SYSV:
            printf("UNIX System V ABI\n");
            break;
        case ELFOSABI_LINUX:
            printf("GNU/Linux ABI\n");
            break;
        default:
            printf("Unknown OS/ABI\n");
            break;
    }

    printf("ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);

    printf("Type:                              ");
    switch (header->e_type)
    {
        case ET_REL:
            printf("Relocatable\n");
            break;
        case ET_EXEC:
            printf("Executable\n");
            break;
        case ET_DYN:
            printf("Shared object\n");
            break;
        default:
            printf("Unknown type\n");
            break;
    }

    printf("Entry point address:               0x%lx\n", (unsigned long)header->e_entry);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        display_error("Usage: elf_header elf_filename");

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        display_error("Error: Cannot open file");

    Elf64_Ehdr header;
    ssize_t bytes_read = read(fd, &header, sizeof(header));
    if (bytes_read != sizeof(header))
        display_error("Error: Cannot read ELF header");

    if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3)
        display_error("Error: Not an ELF file");

    display_elf_header_info(&header);

    close(fd);
    return (0);
}
