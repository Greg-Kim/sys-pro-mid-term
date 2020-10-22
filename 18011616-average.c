#include <stdio.h>
  
int main(void)
{
        int system, algorithm, network;
        double average; // needs to be double, not int ( code auditing )

        printf("Input the system programming, algortihm, and network score:");
        scanf("%d%d%d", &system, &algorithm, &network);

        average = (system + algorithm + network) / 3; // logical error ( code auditing )

        printf("The average of the three subjects is %.2f\n", average);
        // format string must be %.2f, not %d

        return 0;

}

