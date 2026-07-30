# Lightweight ELF Parser in C

A minimalist C utility that inspects 64-bit **ELF (Executable and Linkable Format)** binary headers and section tables on Linux systems. It parses binary metadata directly from disk without executing the target file, operating similarly to a lightweight clone of the system command `readelf -h -S`.

---

## Features

* **Magic Byte Verification:** Ensures the target file is a valid ELF binary (`0x7F 'E' 'L' 'F'`).
* **Header Inspection:** Reads and decodes high-level binary architecture details:
  * **Class & Endianness:** Checks bit size (ELF32/ELF64) and byte ordering (Little vs. Big Endian).
  * **Target Machine & ABI:** Identifies the target CPU (x86-64, ARM, Intel 80386) and OS ABI.
  * **Binary Purpose:** Differentiates between executables (`ET_EXEC`), shared objects (`ET_DYN`), relocatables (`ET_REL`), and core dumps (`ET_CORE`).
  * **Memory Layout Offsets:** Displays the program entry point address, program header offset, and section table offsets.
* **Section Table Extraction:** Parses the Section Headers (`Elf64_Shdr`) and dynamic string table (`.shstrtab`) to output section names (`.text`, `.data`, `.rodata`), types, memory addresses, file offsets, and byte sizes.

---

## Prerequisites

* A Linux-based operating system.
* A C compiler (e.g., `gcc` or `clang`).
* Standard C libraries (`<stdio.h>`, `<stdlib.h>`, `<string.h>`, `<elf.h>`).

---

## Compilation

Compile the source file using `gcc`:

```bash
gcc -o e1 e1.c