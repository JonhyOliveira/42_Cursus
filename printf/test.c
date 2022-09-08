#include "printf.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc > 1)
	{
		t_options	*opts;
		while (--argc > 0)
		{
			opts = parse_format(argv[argc]);
			printf("Opts: %p\n", opts);
			if (opts)
			{
				printf("\tPadding: %ld\n", opts->padding);
				printf("\tPad char: %c\n", opts->padd_char);
				printf("\tConversion: %d\n", opts->conv);
				printf("\tFlags: hash-%d plus-%d minus-%d zero-%d space-%d\n", opts->padding, opts->flags[0], opts->flags[1], opts->flags[2], opts->flags[3], opts->flags[4]);
			}
		}
	}
}
