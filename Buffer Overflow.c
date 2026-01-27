#include <stdio.h>
#include <stdint.h>

struct frame {
    char buf[16];
    volatile int state;
};

void unlock() {
    unsigned char data[] = {
        0x01 ^ 0x53,  // S
        0x01 ^ 0x75,  // u
        0x01 ^ 0x6d,  // m
        0x01 ^ 0x6d,  // m
        0x01 ^ 0x69,  // i
        0x01 ^ 0x74,  // t
        0x01 ^ 0x7b,  // {
        0x01 ^ 0x4f,  // O
        0x01 ^ 0x76,  // v
        0x01 ^ 0x65,  // e
        0x01 ^ 0x72,  // r
        0x01 ^ 0x66,  // f
        0x01 ^ 0x6c,  // l
        0x01 ^ 0x6f,  // o
        0x01 ^ 0x77,  // w
        0x01 ^ 0x34,  // 4
        0x01 ^ 0x74,  // t
        0x01 ^ 0x77,  // w
        0x01 ^ 0x7d,  // }
        0x00
    };

    for (int i = 0; data[i]; i++) {
        putchar(data[i] ^ 0x01);
    }
    putchar('\n');
}

int main() {
    struct frame f;
    f.state = 0;

    puts("=== RANSOMWARE LOCKED ===");
    puts("Enter decryption password:");

    gets(f.buf);   // INTENTIONAL VULNERABILITY

    if (f.state == 1) {
        puts("\nDecryption successful.");
        unlock();
    } else {
        puts("\nDecryption failed.");
    }

    return 0;
}
