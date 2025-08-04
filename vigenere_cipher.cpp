#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main() {
    char msg[15];
    char key[15];

    printf("Enter the message (less than 16 characters):\n");
    gets(msg);

    printf("Enter the key:\n");
    gets(key);

    int msgLen = strlen(msg), keyLen = strlen(key), i, j;

    for (i = 0; msg[i] != '\0'; i++) {
        msg[i] = toupper(msg[i]);
    }

    for (i = 0; key[i] != '\0'; i++) {
        key[i] = toupper(key[i]);
    }

    char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen];

    for (i = 0, j = 0; i < msgLen; ++i, ++j) {
        if (j == keyLen)
            j = 0;
        newKey[i] = key[j];
    }
    newKey[i] = '\0';

    for (i = 0; i < msgLen; ++i) {
        encryptedMsg[i] = ((msg[i] - 'A' + newKey[i] - 'A') % 26) + 'A';
    }
    encryptedMsg[i] = '\0';

    for (i = 0; i < msgLen; ++i) {
        decryptedMsg[i] = (((encryptedMsg[i] - 'A') - (newKey[i] - 'A') + 26) % 26) + 'A';
    }
    decryptedMsg[i] = '\0';

    printf("Original Message: %s", msg);
    printf("\nKey: %s", key);
    printf("\nNew Generated Key: %s", newKey);
    printf("\nEncrypted Message: %s", encryptedMsg);
    printf("\nDecrypted Message: %s", decryptedMsg);

    return 0;
}
