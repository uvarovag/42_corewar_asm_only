/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 16:28:42 by vsanta            #+#    #+#             */
/*   Updated: 2019/11/02 18:08:36 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "asm.h"

int is_command(char *line, char *command)
{
	int cmd_len;
	int space_after;

	cmd_len = ft_strlen(command);
	if (ft_strncmp(line, command, cmd_len) != 0)
		return (0);
	space_after = ft_skip_chars_i(&(line[cmd_len]), SPACE_CHARS);
	if (line[cmd_len + space_after] != BRACKET_CHAR)
		return (0);
	return (1);
}

int is_label(char *line)
{
	int label_char_i;

	if ((label_char_i = ft_get_char_i(line, LABEL_CHAR)) == -1 || label_char_i == 0)
		return (0);
	return (ft_in_line_symbols_only(line, label_char_i, LABEL_CHARS) ? label_char_i : 0);
}

int is_instruclion(char *line)
{
	return (get_instruction_i_in_op(line) == -1 ? 0 : 1);
}

int get_line_type(char *line)
{
	int skip_space_i;

	skip_space_i = ft_skip_chars_i(line, SPACE_CHARS);
	if (ft_strlen(line) == skip_space_i)
		return (EMPTY_LINE);
	if (line[skip_space_i] == COMMENT_CHAR ||
		line[skip_space_i] == COMMENT_CHAR_ALT)
		return (COMMENT_LINE);
	if (is_command(&(line[skip_space_i]), NAME_CMD_STRING))
		return (CMD_NAME_START);
	if (is_command(&(line[skip_space_i]), COMMENT_CMD_STRING))
		return (CMD_COMMENT_START);
	if (is_label(&(line[skip_space_i])))
		return (IS_LABEL);
	if (is_instruclion(&(line[skip_space_i])))
		return (IS_INSTRUCTION);
	return (0);
}
