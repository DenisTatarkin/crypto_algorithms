/*
 * This file is just copy of enc.c without main function.
 * This file is provided for unit testing.
 */

#include <stdio.h>

const unsigned key_length = 32; // 256 bits
const unsigned key_round_length = 16; // 128 bits
const unsigned block_length = 16; // 128 bits
const unsigned rounds_amount = 9;

const u_int8_t Pi[256] = {252, 238, 221, 17, 207, 110, 49, 22, 251, 196, 250, 218, 35, 197, 4, 77, 233, 119, 240, 219,
                          147, 46, 153, 186, 23, 54, 241, 187, 20, 205, 95, 193, 249, 24, 101, 90, 226, 92, 239, 33,
                          129, 28, 60, 66, 139, 1, 142, 79, 5, 132, 2, 174, 227, 106, 143, 160, 6, 11, 237, 152, 127,
                          212, 211, 31, 235, 52, 44, 81, 234, 200, 72, 171, 242, 42, 104, 162, 253, 58, 206, 204, 181,
                          112, 14, 86, 8, 12, 118, 18, 191, 114, 19, 71, 156, 183, 93, 135, 21, 161, 150, 41, 16, 123,
                          154, 199, 243, 145, 120, 111, 157, 158, 178, 177, 50, 117, 25, 61, 255, 53, 138, 126, 109,
                          84, 198, 128, 195, 189, 13, 87, 223, 245, 36, 169, 62, 168, 67, 201, 215, 121, 214, 246, 124,
                          34, 185, 3, 224, 15, 236, 222, 122, 148, 176, 188, 220, 232, 40, 80, 78, 51, 10, 74, 167, 151,
                          96, 115, 30, 0, 98, 68, 26, 184, 56, 130, 100, 159, 38, 65, 173, 69, 70, 146, 39, 94, 85, 47,
                          140, 163, 165, 125, 105, 213, 149, 59, 7, 88, 179, 64, 134, 172, 29, 247, 48, 55, 107, 228,
                          136, 217, 231, 137, 225, 27, 131, 73, 76, 63, 248, 254, 141, 83, 170, 144, 202, 216, 133, 97,
                          32, 113, 103, 164, 45, 43, 9, 91, 203, 155, 37, 208, 190, 229, 108, 82, 89, 166, 116, 210,
                          230, 244, 180, 192, 209, 102, 175, 194, 57, 75, 99, 182};

struct key_round{
    char key[key_round_length];
};

void expand_keys(struct key_round round_keys[], char key[]);
char* F(char c[], char key1[], char key2[]);
void X(char key[], char block[]);
void S(char block[]);
void L(char block[]);
char lambda16(char block[]);
char* vec(int num);

void expand_keys(struct key_round round_keys[], char key[]){
    //todo implement only by constants
    char* c[32];
    for(int i = 1; i <= 32; i++){
        c[i-1] = vec(i);
        L(c[i-1]);

        for(int i = 31; i > 15; i--)
            round_keys[0].key[31 - i] = key[i];
        for(int i = 15; i >= 0; i--)
            round_keys[1].key[15 - i] = key[i];

        for(int i = 1; i <= 4; i++){
            //  round_keys[2*i + 1] =
        }
    }


}

char* F(char c[], char key1[], char key2[]){
    char new_keys[key_round_length * 2];
    for(int i = 0; i < key_round_length; i++)
        new_keys[i] = key2[i];
    for(int i = key_round_length; i < key_round_length * 2; i++)
        new_keys[i] = key1[i - key_round_length];

}

void X(char key[], char block[]) {
    for(int i = 0; i < block_length; i++)
        block[i] = block[i] | key[i];
}

void S(char block[]){
    for(int i = 0; i < block_length; i++)
        block[i] = Pi[block[i]];
}

void L(char block[]){
    char lambda;
    for(int i = 0; i < block_length; i++) {
        for(int j = 0; j < block_length - 1; i++)
            block[j] = block[j + 1];
        block[block_length - 1] = lambda16(block);
    }
}

char lambda16(char block[]){
    if(sizeof(block) != 16) // 16 bytes
        //todo error returning

        return (148*block[15] + 32*block[14] + 133*block[13] + 16*block[12] + 194*block[11] + 192*block[10]
                + block[9] + 251*block[8] + block[7] + 192*block[6] + 194*block[5] + 16*block[4] + 133*block[3]
                + 32*block[2] + 148*block[1] + block[0]) % 256;
}

char* vec(int num){
    //todo in constants
    int k = 0;
    char vector[16] = {'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
    while (num >= 1)
    {
        vector[k++] = (num % 2) + '0';
        num = num / 2;
    }

    char tmp;
    for (int i = 0; i < 16 / 2; i++)
    {
        tmp = vector[i];
        vector[i] = vector[16 - 1 - i];
        vector[16 - 1 - i] = tmp;
    }

    return vector;
}
