# corewar

Corewar is a codding game from 1984
<br><img src="corewar-animation.gif" alt="corewar-animation" width="1195"/>

Current implementation according according to school "42" corewar specifications.</br>

Players are programmed using the assembler style language inspired by the <a href="http://vyznev.net/corewar/guide.html"> original redcode</a>.</br>

Usage:</br>
1. Create program using set of instruction below. file must have following structure:</br>
   *.name "player_name"*</br>
   *.comment "comments to the player"*</br>
   *\<Set of instructions\>*</br>
   *Comments can be placed anywhere and must be followed by the number sign '#'*</br>
   *file name must end with .s*
 2. Compile program using ./asm <filename.s>
 3. Execute program using ./corewar [options] <filename.cor> 

For detailed usage execute binaries without argument.

## Instruction specifications
| instructions | op codes | arguments                | purpose                                                                                                                                                                                                                       | cycles | modify carry | pre-load opcode |
|--------------|:----------:|:--------------------------:|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|:--------:|:--------------:|:-----------------:|
| `live`       | `0x01`   | player name over 4 bytes | say that the player is alive                                                                                                                                                                                                  |     10 | ✗            | ✓               |
| `ld`         | `0x02`   | 1 address + 1 register   | load =REG_SIZE= bytes from address to register                                                                                                                                                                                |      5 | ✓            | ✓               |
| `st`         | `0x03`   | 1 register + 1 address   | store =REG_SIZE= bytes from register to address                                                                                                                                                                               |      5 | ✗            | ✓               |
| `add`        | `0x04`   | 3 registers              | adds the contents of the 2 first and stores the result in the third                                                                                                                                                           |     10 | ✓            | ✓               |
| `sub`        | `0x05`   | 3 registers              | substracts the contents of the 2 first and stores the result in the third                                                                                                                                                     |     10 | ✓            | ✓               |
| `and`        | `0x06`   | 2 values + 1 register    | does a logic AND with the 2 firsts values and stores it in the register                                                                                                                                                       |      6 | ✓            | ✓               |
| `or`         | `0x07`   | 2 values + 1 register    | does a logic OR with the 2 firsts values and stores it in the register                                                                                                                                                        |      6 | ✓            | ✓               |
| `xor`        | `0x08`   | 2 values + 1 register    | does a logic XOR with the 2 firsts values and stores it in the register                                                                                                                                                       |      6 | ✓            | ✓               |
| `zjump`      | `0x09`   | 1 index                  | if carry == 1, store (PC + (arg % IDX_MOD)) in PC                                                                                                                                                                             |     20 | ✗            | ✓               |
| `ldi`        | `0x0a`   | 2 indexes + 1 register   | ldi 3,%4,r1 reads IND_SIZE bytes at address: (PC + (3 % IDX_MOD)), adds 4 to this value. We will name this sum S. Read REG_SIZE bytes at address (PC + (S % IDX_MOD)), which are copied to r1. Parameters 1 and 2 are indexes |     25 | ✗            | ✓               |
| `sti`        | `0x0b`   |                          |                                                                                                                                                                                                                               |     25 | ✗            | ✓               |
| `fork`       | `0x0c`   |                          |                                                                                                                                                                                                                               |    800 | ✗            | ✓               |
| `lld`        | `0x0d`   |                          |                                                                                                                                                                                                                               |     10 | ✗            | ✓               |
| `lldi`       | `0x0e`   |                          |                                                                                                                                                                                                                               |     50 | ✗            | ✓               |
| `lfork`      | `0x0f`   |                          |                                                                                                                                                                                                                               |   1000 | ✗            | ✓               |
| `aff`        | `0x10`   |                          |                                                                                                                                                                                                                               |      2 | ✓            | ✓ 	           |
