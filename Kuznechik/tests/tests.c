#include <stdio.h>
#include <stdbool.h>
#include "enc_for_test.c"

void vec_tests(){
    bool assert = true;
    char* a;

/////////vec(32)///////////////////
    a = vec(1);
    char b1[16] = {'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'};
    for(int i = 0; i < 16; i++)
        if(b1[i] != *(a + i)){
            assert = false;
            break;
        }
    if(assert == true)
        printf("%s\n", "SUCCESS: vec(1)");
    else{
        printf("%s\n", "FAIL: vec(1)");
        assert = true;
    }
//////////////////////////////////////

///////////vec(32)///////////////////
    a = vec(32);
    char b2[16] = {'0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0'};
    for(int i = 0; i < 16; i++)
        if(b2[i] != *(a + i)){
            assert = false;
            break;
        }
    if(assert == true)
        printf("%s\n", "SUCCESS: vec(32)");
    else{
        printf("%s\n", "FAIL: vec(32)");
        assert = true;
    }
///////////vec(32)///////////////////

///////////vec(15)///////////////////
    a = vec(15);
    char b3[16] = {'0','0','0','0','0','0','0','0','0','0','0','0','1','1','1','1'};
    for(int i = 0; i < 16; i++)
        if(b3[i] != *(a + i)){
            assert = false;
            break;
        }
    if(assert == true)
        printf("%s\n", "SUCCESS: vec(15)");
    else{
        printf("%s\n", "FAIL: vec(15)");
        assert = true;
    }
///////////vec(15)///////////////////
}

int main(){
    printf("%s\n","Testing is started");
    vec_tests();
    printf("%s\n","Testing is finished");
}



