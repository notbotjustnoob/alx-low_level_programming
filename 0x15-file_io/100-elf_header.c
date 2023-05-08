#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <stdlib.h>

/**
 * error_exit - Prints an error message and exits with a specific code.
 * @code: The exit code.
 * @message: The error message to print.
 */
void error_exit(int code, const char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(code);
}

/**
 * print_magic - Prints the magic number of the ELF file.
 * @e_ident: The ELF identification array.
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", e_ident[i], (i == EI_NIDENT - 1) ? '\n' : ' ');
}

/**
 * print_class - Prints the class of the ELF file.
 * @e_ident: The ELF identification array.
 */
void print_class(unsigned char *e_ident)
{
	printf("  Class:                             ");
	switch (e_ident[EI_CLASS])
	{
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown>\n");
		break;
	}
}

/**
 * print_data - Prints the data encoding of the ELF file.
 * @e_ident: The ELF identification array.
 */
void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");
	switch (e_ident[EI_DATA])
	{
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown>\n");
		break;
	}
}

/**
 * print_version - Prints the version of the ELF file.
 * @e_ident: The ELF identification array.
 */
void print_version(unsigned char *e_ident)
{
	printf("  Version:                           %d (current)\n", e_ident[EI_VERSION]);
}

/**
 * print_osabi - Prints the OS/ABI of the ELF file.
 * @e_ident: The ELF identification array.
 */
void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("UNIX - ARM architecture\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %u>\n", e_ident[EI_OSABI]);
		break;
	}
}

/**
 * print_type - Prints the type of the ELF file.
 * @e_type: The e_type field of the ELF header.
 */
void print_type(unsigned int e_type)
{
	printf("  Type:                              ");
	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (No file type)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %#x>\n", e_type);
		break;
	}
}

/**
 * print_entry - Prints the entry point address of the ELF file.
 * @e_entry: The e_entry field of the ELF header.
 */
void print_entry(Elf64_Addr e_entry)
{
	printf("  Entry point address:               %#lx\n", e_entry);
}

/**
 * elf_header - Displays the information contained in the ELF header of an ELF file.
 * @filename: The name of the ELF file.
 */
void elf_header(const char *filename)
{
	int fd;
	Elf64_Ehdr header;

	/* Open the file */
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_exit(98, "Error: Cannot open file");

	/* Read the ELF header */
	if (read(fd, &header, sizeof(header)) != sizeof(header))
		error_exit(98, "Error: Cannot read ELF header");

	/* Check if it's a valid ELF file */
	if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1 ||
	    header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3)
		error_exit(98, "Error: Not an ELF file");

	/* Print the ELF header information */
	printf("ELF Header:\n");
	print_magic(header.e_ident);
	print_class(header.e_ident);
	print_data(header.e_ident);
	print_version(header.e_ident);
	print_osabi(header.e_ident);
	print_type(header.e_type);
	print_entry(header.e_entry);

	/* Close the file */
	if (close(fd) == -1)
		error_exit(100, "Error: Cannot close file");
}

/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: The command-line arguments
 *
 * Return: 0 on success, otherwise 98.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		return 97;
	}

	elf_header(argv[1]);

	return 0;
}
