#:include <fcntl.h>
#include <stdio.h>
#include <elf.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * print_elf_header - Display information from the ELF header.
 * @elf_header: A pointer to the ELF header structure.
 */
void print_elf_header(Elf64_Ehdr *elf_header)
{
	char *magic = elf_header->e_ident;

	printf("Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", magic[i], i == EI_NIDENT - 1 ? '\n' : ' ');

	printf("Class:                             %s\n",
	       magic[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");
	printf("Data:                              %s\n",
	       magic[EI_DATA] == ELFDATA2LSB ? "2's complement, endian" : "unknown");
	printf("Version:                         %d (current)\n", magic[EI_VERSION]);
	printf("OS/ABI:                            %s\n",
	       magic[EI_OSABI] == ELFOSABI_SYSV ? "UNIX System V ABI" : "unknown");
	printf("ABI Version:                       %d\n", magic[EI_ABIVERSION]);
	printf("Type:                              %s\n",
	       elf_header->e_type == ET_EXEC ? "EXEC (Executable file)" : "unknown");
	printf("Entry point address:   0x%lx\n", (unsigned long)elf_header->e_entry);
}

int main(int argc, char *argv[]) 
{
	int fd;
	Elf64_Ehdr elf_header;

	if (argc != 2)
       	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		return (EXIT_FAILURE);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
       	{
		dprintf(STDERR_FILENO, "Error: Cannot open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
       	{
		dprintf(STDERR_FILENO, "Error: Cannot read ELF header %s\n", argv[1]);
		close(fd);
		return(EXIT_FAILURE);
	}

	if (lseek(fd, 0, SEEK_SET) == -1) 
	{
		dprintf(STDERR_FILENO, "Error:Cannot seek start of file %s\n", argv[1]);
		close(fd);
		return (EXIT_FAILURE);
	}

	if (memcmp(elf_header.e_ident, ELFMAG, SELFMAG) != 0)
       	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file: %s\n", argv[1]);
		close(fd);
		return(EXIT_FAILURE);
	}

	print_elf_header(&elf_header);
	close(fd);
	return(EXIT_SUCCESS);
}
