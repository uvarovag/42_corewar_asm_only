/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 15:48:00 by vsanta            #+#    #+#             */
/*   Updated: 2019/11/20 19:37:18 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	put_error(t_asm *asemb, int err_n, int row, int col)
{
	if (err_n == ERR_LEX)
		ft_printf("Lexical error at [%03i:%03i]\n", row, col);
	else if (err_n == ERR_LEX_NL)
		ft_printf("Lexical error - unexpected end of input"\
			" (Perhaps you forgot to end with a newline ?\n");
	else if (err_n == ERR_SYNTX)
		ft_printf("Syntax error at [%03u:%03i]\n", row, col);
	else if (err_n == ERR_LONG_NAME)
		ft_printf("Champion name too long (Max length %u)\n", PROG_NAME_LENGTH);
	else if (err_n == ERR_LONG_COM)
		ft_printf("Champion comment too long"\
			" (Max length %u)\n", COMMENT_LENGTH);
	else
		ft_printf("System error - %i\n", err_n);
	exit(free_asm(asemb, err_n));
}

void	put_error_inst(t_asm *asemb, int row, int arg_i, char *op_name)
{
	ft_printf("Invalid parameter %i type indirect"\
		" for instruction \"%s\" in line %i\n", arg_i, op_name, row);
	exit(free_asm(asemb, ERR_INVALID_PARAM));
}

void	put_error_label(t_asm *asemb, int row, char *label)
{
	ft_printf("Undeclared label \"%s\" in line %i\n", label, row);
	exit(free_asm(asemb, 6));
}
