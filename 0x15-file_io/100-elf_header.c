#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <string.h>

#define BUFSIZE 64

void print_magic(unsigned char *magic) {
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", magic[i], i == EI_NIDENT - 1 ? '\n' : ' ');
}

void print_class(unsigned char class) {
	printf("  Class:                             ");
	switch (class) {
		case ELFCLASSNONE: printf("none\n"); break;
		case ELFCLASS32: printf("ELF32\n"); break;
		case ELFCLASS64: printf("ELF64\n"); break;
		default: printf("<unknown: %x>\n", class);
	}
}

void print_data(unsigned char data) {
	printf("  Data:                              ");
	switch (data) {
		case ELFDATANONE: printf("none\n"); break;
		case ELFDATA2LSB: printf("2's complement, little endian\n"); break;
		case ELFDATA2MSB: printf("2's complement, big endian\n"); break;
		default: printf("<unknown: %x>\n", data);
	}
}

void print_version(unsigned char version) {
	printf("  Version:                           %d (current)\n", version);
}

void print_osabi(unsigned char osabi) {
	printf("  OS/ABI:                            ");
	switch (osabi) {
		case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
		case ELFOSABI_HPUX: printf("UNIX - HP-UX\n"); break;
		case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
		case ELFOSABI_LINUX: printf("UNIX - Linux\n"); break;
		case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
		case ELFOSABI_AIX: printf("UNIX - AIX\n"); break;
		case ELFOSABI_IRIX: printf("UNIX - IRIX\n"); break;
		case ELFOSABI_FREEBSD: printf("UNIX - FreeBSD\n"); break;
		case ELFOSABI_TRU64: printf("UNIX - TRU64\n"); break;
		case ELFOSABI_MODESTO: printf("Novell - Modesto\n"); break;
		case ELFOSABI_OPENBSD: printf("UNIX - OpenBSD\n"); break;
		case ELFOSABI_ARM_AEABI: printf("ARM EABI\n"); break;
		case ELFOSABI_ARM: printf("ARM\n"); break;
		case ELFOSABI_STANDALONE: printf("Standalone App\n"); break;
		default: printf("<unknown: %x>\n", osabi);
	}
}

void print_abiversion(unsigned char abiversion) {
	printf("  ABI Version:                       %d\n", abiversion);
}

void print_type(unsigned short type) {
	printf("  Type:                              ");
	switch (type) {
		case ET_NONE: printf("NONE (None)\n"); break;
		case ET_REL: printf("REL (Relocatable file)\n"); break;
		case ET_EXEC: printf("EXEC (Executable file)\n"); break;
		case ET_DYN: printf("DYN (Shared object file)\n"); break;
		case ET_CORE: printf("CORE (Core file)\n"); break;
		default: printf("<unknown: %x>\n", type);
	}
}

void print_entry(unsigned long entry) {
	printf("  Entry point address:               0x%lx\n", entry);
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	int fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
		exit(98);
	}

	Elf64_Ehdr header;
	if (read(fd, &header, sizeof(header)) != sizeof(header)) {
		fprintf(stderr, "Error: Cannot read ELF header\n");
		close(fd);
		exit(98);
	}

	// Verify ELF magic number
	unsigned char elf_magic[EI_NIDENT] = {0x7f, 'E', 'L', 'F'};
	if (memcmp(header.e_ident, elf_magic, EI_NIDENT) != 0) {
		fprintf(stderr, "Error: File %s is not an ELF file\n", argv[1]);
		close(fd);
		exit(98);
	}

	// Print ELF header information
	printf("ELF Header:\n");
	print_magic(header.e_ident);
	print_class(header.e_ident[EI_CLASS]);
	print_data(header.e_ident[EI_DATA]);
	print_version(header.e_ident[EI_VERSION]);
	print_osabi(header.e_ident[EI_OSABI]);
	print_abiversion(header.e_ident[EI_ABIVERSION]);
	print_type(header.e_type);
	print_entry(header.e_entry);

	close(fd);
	return 0;
}
