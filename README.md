# ft_printf
The goal of this project is to recreate part of libc function printf. Why? Because students of 42 Network usualy can use only their own libraries and functions. However, it's a great way to learn C. 

# Project description
- You have to manage the following conversions:`c` `s` `p`
- You have to manage the following conversions:`d` `i` `o` `u` `x` `X` with the following flags:`hh`,`h`, `l` and `ll`
- You have to manage the following conversion: `f` with the following flags:`l` and `L`
- You must manage `%%`
- You must manage the flags `#` `0` `-` `+` and `space`
- You must manage the minimum `field-width`
- You must manage the `precision`<br>
Allowed functions are `write`, `malloc`, `free`, `exit` and the functions of man 3 stdarg. Everything else is forbidden.

# Test!
Run `make && make clean`, this will compile libftprintf.a. Include `inc/ft_printf.h`  to your project and use just like printf. <br>Also you can run `./printf.test` for quik view.
