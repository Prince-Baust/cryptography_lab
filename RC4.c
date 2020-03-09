#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 256

void swap(unsigned char *a, unsigned char *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int KSA(char *key, unsigned char *S)
{

    int len = strlen(key);
    int j = 0;

    int i;
    for( i = 0; i < N; i++)
        S[i] = i;

    for( i = 0; i < N; i++) {
        j = (j + S[i] + key[i % len]) % N;

        swap(&S[i], &S[j]);
    }

    return 0;
}

int PRGA(unsigned char *S, char *plaintext, unsigned char *ciphertext)
{

    int i = 0;
    int j = 0;
    int n;
    for( n = 0; n < strlen(plaintext); n++) {
        i = (i + 1) % N;
        j = (j + S[i]) % N;

        swap(&S[i], &S[j]);
        int rnd = S[(S[i] + S[j]) % N];

        ciphertext[n] = rnd ^ plaintext[n];
    }

    return 0;
}

int RC4(char *key, char *plaintext, unsigned char *ciphertext)
{

    unsigned char S[N];
    KSA(key, S);

    PRGA(S, plaintext, ciphertext);

    return 0;
}

int main()
{
    char key[100] = "123", pt[100] = "Nawab";
    unsigned char *ciphertext = malloc(sizeof(int) * strlen(pt));

    RC4(key, pt, ciphertext);
    int i;
    for(i = 0; i < strlen(pt); i++)
        printf("%02hhX", ciphertext[i]);

    return 0;
}
