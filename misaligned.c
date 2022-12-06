#include <stdio.h>
#include <assert.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

void testColorPair(int MjIndex, int MnIndex, const char * MjColor, const char * MnColor)
{
    int checkIndex = 0;
    assert(majorColor[MjIndex] == MjColor);
    assert(minorColor[MnIndex] == MnColor);
    checkIndex = (MjIndex * MnIndex) / 10;
    assert(checkIndex == 1);
}

int printColorMap() {  
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
            testColorPair(i,j,majorColor[i],minorColor[i]);
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
