// ExecutiveReports2026

#include <stdio.h>
#include <string.h>

int authorized(const char *name) {
    // This condition is intentionally impossible
    if (strlen(name) == 1337) {
        return 1;
    }
    return 0;
}

void executives_list() {
    char flag[] = "Summit{I_Love_ReverseEngineering}";
    puts(flag);
}

int main() {
    char name[64];

    puts("Welcome to Summit International");
    puts("Before we get started, who am I speaking with?");
    printf("> ");

    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    if (authorized(name)) {
        executives_list();
    } else {
        puts("Sorry, you are not authorized to see this flag at this moment");
    }

    return 0;
}


/// ran this command after: gcc ExecutiveReports2026.c -o ExecutiveReports2026 -O0 -no-pie -fno-stack-protector

