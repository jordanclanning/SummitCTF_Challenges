#include <stdio.h>
#include <stdint.h>

void decrypt_runtime() {

    // Encrypted bytes for: Summit{runtime_memory_only}
    unsigned char enc[] = {
        56, 16, 20, 92, 91, 71, 16, 23, 12,
        95, 70, 90, 6, 0, 38, 92, 87, 94,
        4, 23, 0, 110, 93, 93, 7, 28, 4
    };

    unsigned char key[] = { 'k', 'e', 'y', '1', '2', '3' };

    // +1 for NULL terminator (important for student usability)
    unsigned char buf[sizeof(enc) + 1];

    for (int i = 0; i < sizeof(enc); i++) {
        buf[i] = enc[i] ^ key[i % sizeof(key)];
    }

    // Make it a valid C string at runtime only
    buf[sizeof(enc)] = '\0';

    // Flag exists ONLY here, on the stack, at runtime
    // It is never printed, returned, or stored globally
}

int main() {
    decrypt_runtime();
    puts("Access Granted");
    return 0;
}

// (gdb) info registers
// (gdb) break *decrypt_runtime+166
// (gbd) run
// (gdb)x/64bx $rbp-0x50

// Loop to find the break point
// (gbd) si
// (gdb) x/64bx $rbp-0x50

// memory stopped at:
//    0x00000000004011dc
