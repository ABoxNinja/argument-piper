#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools/check.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("\e[0;31mERROR\e[0m: no program path given");
    }
    else
    {
        if (argv[1])
        {
            int input = 123;
            int status;

            FILE *pipe = popen(argv[1],"w");
            if (!pipe)
            {
                perror("popen");
                return EXIT_FAILURE;
            }

            fprintf(pipe, "%d\n", input);
            status = pclose(pipe);

            if (status == 0)
            {
                printf("\n%s -> \e[0;32m[OK]\e[0m\n",argv[1]);
                printf("\e[0;30m\tinput: %d\e[0m\n",input);
                if (IS_INTEGER(input))
                {
                    printf("\e[0;30m\tinput type: integer\e[0m");
                }
                else if (IS_CHAR(input))
                {
                    printf("\e[0;30m\tinput type: string/character\e[0m");
                }
                else if (IS_FLOAT(input))
                {
                    printf("\e[0;30m\tinput type: float\e[0m");
                }
                else
                {
                    printf("\e[0;30m\tinput type: could not get input type\e[0m");
                }
            }
            else
            {
                
            }

            if (status == -1)
            {
                perror("pclose");
                return EXIT_FAILURE;
            } 


            return EXIT_SUCCESS;
        }
    }
}