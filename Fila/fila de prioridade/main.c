#include <stdio.h>
#include "fpa.h"

int main()
{
    fpa f;
    fpa_init(&f);
    gerar_aleatorio(&f);
    return 0;
}
