#include <stdio.h>
#include <stdint.h>

void unlock(void) {
    unsigned char data[] = {
        0x01 ^ 0x53, 0x01 ^ 0x75, 0x01 ^ 0x6d, 0x01 ^ 0x6d,
        0x01 ^ 0x69, 0x01 ^ 0x74, 0x01 ^ 0x7b,
        0x01 ^ 0x4f, 0x01 ^ 0x76, 0x01 ^ 0x65,
        0x01 ^ 0x72, 0x01 ^ 0x66, 0x01 ^ 0x6c,
        0x01 ^ 0x6f, 0x01 ^ 0x77, 0x01 ^ 0x34,
        0x01 ^ 0x74, 0x01 ^ 0x77, 0x01 ^ 0x7d,
        0x00
    };

    for (int i = 0; data[i]; i++) {
        putchar(data[i] ^ 0x01);
    }
    putchar('\n');
}

void check_password(void) {
    char buf[64];
    volatile uint32_t auth = 0;  // Auth flag on stack
    
    puts("=== RANSOMWARE LOCKED ===");
    puts("Enter decryption password:");
    
    gets(buf);  // INTENTIONAL VULNERABILITY
    
    // Method 1: Overflow to overwrite 'auth'
    if (auth == 0xDEADBEEF) {
        puts("\n[Method 1] Auth flag overwritten!");
        unlock();
        return;
    }
    
    puts("\nDecryption failed.");
    // Method 2: Students can overwrite return address to jump to unlock()
}

int main(void) {
    check_password();
    return 0;
}

// example output to produce the flag: python3 -c "print('A'*16 + '\x01\x00\x00\x00')" | ./ransomware 
// Above is not the code reveal
