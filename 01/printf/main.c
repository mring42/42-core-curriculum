
// int	main(void)
// {
// 	// you know how to use printf.
// 	// Use your brain and get that ft_printf going.
// 	// Expected: "Hex (lower) with #: 0x2a"
// 	printf("or: Hex (lower) with #:                 %4.x\n", 42);
// 	ft_printf("ft: Hex (lower) with #:                 %4.x\n", 42);
// 	// Expected: "Hex (upper) with #: 0X2A"
// 	printf("or: Hex (upper) with #:                 %#X\n", 42);
// 	ft_printf("ft: Hex (upper) with #:                 %#X\n", 42);
// 	// Expected: "Space flag:  42" // works as standalone
// 	printf("or: Space flag:                         % d\n", 42);
// 	ft_printf("ft: Space flag:                         % d\n", 42);
// 	// Expected: "Negative with space: -42"
// 	printf("or: Negative with space:                % d\n", -42);
// 	ft_printf("ft: Negative with space:                % d\n", -42);
// 	// Expected: "Plus sign: +42"
// 	printf("or: Plus sign:                          %+d\n", 42);
// 	ft_printf("ft: Plus sign:                          %+d\n", 42);
// 	// Expected: "Negative with plus: -42" // + is ignored
// 	printf("or: Negative with plus:                 %+d\n", -42);
// 	ft_printf("ft: Negative with plus:                 %+d\n", -42);
// 	// Expected: "Hex with + and #: 0x2a" // ignores + in hex
// 	printf("or: Hex with + and #:                   %#x\n", 42);
// 	ft_printf("ft: Hex with + and #:                   %#x\n", 42);
// 	// + unnecessary
// 	// Expected: "Hex with space and #: 0x2a" // ignores space in hex
// 	printf("or: Hex with space and #:               %# 10x\n", 42);
// 	ft_printf("ft: Hex with space and #:               %# 10x\n", 42);
// 	// Expected: "Space and plus: +42" // + overwrites space
// 	printf("or: Space and plus:                     % +d\n", 42);
// 	ft_printf("ft: Space and plus:                     % +d\n", 42);
// 	// space unnecessary
// 	// Expected: "Pointer with: 0x2a" // can ignore #
// 	printf("or: Pointer with #:                     %p\n", (void *)42);
// 	ft_printf("ft: Pointer with #:                     %p\n", (void *)42);
// 	//
// 	// Testing #, 0, and - in combination with %x and %X
// 	// Expected: "Hex with #:        0x2a"
// 	printf("or: Hex with #:                         %#x\n", 42);
// 	ft_printf("ft: Hex with #:                         %#x\n", 42);
// 	// Expected: "Hex with 0 and #: 0x0000002a"
// 	printf("or: Hex with 0 and #:                   %#010x\n", 42);
// 	ft_printf("ft: Hex with 0 and #:                   %#010x\n", 42);
// 	// Expected: "Hex left-aligned #: 0x2a      "
// 	printf("or: Hex left-aligned #:                 %-#10x\n", 42);
// 	ft_printf("ft: Hex left-aligned #:                 %-#10x\n", 42);
// 	//
// 	// Testing +, space, -, and 0 with signed integers
// 	// Expected: "With space and width:      42"
// 	printf("or: With space and width:               % 10d\n", 42);
// 	ft_printf("ft: With space and width:               % 10d\n", 42);
// 	// Expected: "Plus with width:        +42"
// 	printf("or: Plus with width:                    %+10d\n", 42);
// 	ft_printf("ft: Plus with width:                    %+10d\n", 42);
// 	// Expected: "Left-aligned plus: +42      "
// 	printf("or: Left-aligned plus:                  %-+10d\n", 42);
// 	ft_printf("ft: Left-aligned plus:                  %-+10d\n", 42);
// 	// Expected: "Zero-padded plus: +00000042"
// 	printf("or: Zero-padded plus:                   %+010d\n", 42);
// 	ft_printf("ft: Zero-padded plus:                   %+010d\n", 42);
// 	// Expected: "Negative with  zero: -00000042"
// 	printf("or: Negative with zero:                 %010d\n", -42);
// 	ft_printf("ft: Negative with zero:                 %010d\n", -42);
// 	//
// 	// Testing precision (.) with +, space, and #
// 	// Expected: "With precision: +0042"
// 	printf("or: With precision:                     %+05.4d\n", 42);
// 	ft_printf("ft: With precision:                     %+05.4d\n", 42);
// 	// Expected: "With space and precision:   0042"
// 	printf("or: With space and precision:           % .4d\n", 42);
// 	ft_printf("ft: With space and precision:           % .4d\n", 42);
// 	// Testing # and precision with hex and integer
// 	// Expected: "Hex with precision #: 0x00002a"
// 	printf("or: Hex with precision #:               %#.8x\n", 42);
// 	ft_printf("ft: Hex with precision #:               %#.8x\n", 42);
// 	// Expected: "Integer precision with 0 and width: 00000042"
// 	printf("or: Integer precision with 0 and width: %010.8d\n", 42);
// 	ft_printf("ft: Integer precision with 0 and width: %010.8d\n", 42);
// 	// Testing precision and width with -
// 	// Expected: "Left-aligned, precision: 0042      "
// 	printf("or: Left-aligned, precision:            %-10.4d\n", 42);
// 	ft_printf("ft: Left-aligned, precision:            %-10.4d\n", 42);
// 	// Expected: "Pointer with precision: 0x0000002a"
// 	printf("or: Pointer with precision:             %7.5p\n", (void *)4242);
// 	ft_printf("ft: Pointer with precision:             %7.5p\n", (void *)4242);
// 	// that prints, starting from and including 0x,
// 	// X amount of 0. 8? 0x000000. 2? 0x. 4? 0x00.
// 	// the number before the . is the padding for the entire strlen
// 	// if the min length is above the number its ignored
// 	// if the number is > len, it prints spaces to the left.
// 	// Outputs "    %" with four spaces padding the % on the left.
// 	printf("or: |%5%\n");
// 	ft_printf("ft: |%5%\n");
// 	// Outputs "%    " with four spaces padding on the right due to the left alignment.
// 	printf("or: %-5%|\n");
// 	ft_printf("ft: %-5%|\n");
// }

// Chapter I
// Introduction
// You will discover a popular and versatile C function: printf().
// You will discover variadic functions in C.
// The key to a successful ft_printf is a well-structured and extensible code.
// Once this assignment passed, you will be allowed to add your
// ft_printf() to your libft so you can use it in your school C projects.
// 2
// Chapter II
// Common Instructions
// • Your project must be written in C.
// • Your project must be written in accordance with the Norm. If you have bonus
// files/functions,
// 	they are included in the norm check and you will receive a 0 if there
// is a norm error inside.
// • Your functions should not quit unexpectedly apart from undefined behaviors.
// • All heap allocated memory space must be properly freed when necessary.
// No leaks will be tolerated.

// • If your project allows you to use your libft,
// 	you must copy its sources and its
// associated Makefile in a libft folder with its associated Makefile. Your project’s
// Makefile must compile the library by using its Makefile then compile the project.

// Program name libftprintf.a
// Turn in files Makefile, *.h, * .h, *.c, * *.c
//  Makefile NAME, all, clean, fclean, re
//  External functs.
//  malloc, free, write, va_start, va_arg, va_copy, va_end
//  Libft authorized Yes
//  Description Write a library that contains ft_printf(), a
//  function that will mimic the original	printf(void)
//  You have to recode the printf() function from libc.
//  The prototype of ft_printf() is:
//  int										ft_printf(const char *, ...);
//  Here are the requirements:
//  • Don’t implement the buffer management of the original printf().
//  • Your function has to handle the following conversions: cspdiuxX%
//  • Your function will be compared against the original printf().
//  • You must use the command ar to create your library.
//  Using the libtool command is forbidden.
//  • Your libftprintf.a has to be created at the root of your repository.
//  5
//  ft_printf Because ft_putnbr() and ft_putstr() aren’t enough
//  You have to implement the following conversions:
//  • %c Prints a single character.
//  • %s Prints a string (as defined by the common C convention).
//  • %p The void * pointer argument has to be printed in hexadecimal format.
//  • %d Prints a decimal (base 10) number.
//  ��� %i Prints an integer in base 10.
//  • %u Prints an unsigned decimal (base 10) number.
//  • %x Prints a number in hexadecimal (base 16) lowercase format.
//  • %X Prints a number in hexadecimal (base 16) uppercase format.
//  �� %% Prints a percent sign.

//  Bonus:
//  • Manage any combination of the following flags: ’-0.’ and the field minimum width
//  under all conversions.
//  • Manage all the following flags: ’# +’ (Yes, one of them is a space)

//  If you plan to complete the bonus part, think about the
//  implementation of your extra features from the start. This way,
//  you will avoid the pitfalls of a naive approach.
