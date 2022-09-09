#include "printf.h"
#include <stdio.h>

char	*bval(bool b)
{
	return (b == true ? "true" : "false");
}

int	main(int argc, char *argv[])
{
	if (argc > 1)
	{
		t_options	*opts;
		while (--argc > 0)
		{
			opts = parse_format(argv[argc], 0);
			printf("Opts: %p\n", opts);
			if (opts)
			{
				printf("\tPadding: %ld\n", opts->padding);
				printf("\tPad char: \'%c\'\n", opts->padd_char);
				printf("\tConversion: %d\n", opts->conv);
				printf("\tIndex: %ld\n", opts->arg_i);
				printf("\tFlags: hash-%s plus-%s minus-%s zero-%s space-%s\n", bval(opts->flags[0]), bval(opts->flags[1]), bval(opts->flags[2]), bval(opts->flags[3]), bval(opts->flags[4]));
			}
		}
	}
}
