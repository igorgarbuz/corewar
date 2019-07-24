/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_automaton.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 10:13:09 by jfleury           #+#    #+#             */
/*   Updated: 2019/07/02 17:22:36 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		g_nb_line = 0;

int		g_nb_char = 0;

int		g_nb_token = 0;

int		g_matrice_automaton[30][17] =
{
	{23, 23, -1, 24, 26, 17, 19, 9, 29, -1, 12, 21, 21, 22, 0, 0, -1},
	{-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2},
	{-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2},
	{-3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3},
	{-3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3},
	{-3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3},
	{-3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3},
	{-3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3},
	{-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2},
	{-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2},
	{-3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3},
	{-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2},
	{12, 12, -1, 12, -1, 1, -1, -1, -1, -1, 12, -1, -1, -1, -1, 1, -1},
	{13, 13, -1, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 2, 2, -1},
	{-1, -1, -1, 14, -1, -1, -1, 3, -1, -1, -1, 3, 3, -1, 3, 3, -1},
	{15, 15, -1, 15, -1, -1, -1, 4, -1, -1, 15, 4, 4, -1, 4, 4, -1},
	{-1, -1, -1, 16, -1, -1, -1, 5, -1, -1, -1, 5, 5, -1, 5, 5, -1},
	{17, 17, -1, 17, -1, -1, -1, 6, -1, -1, 17, 6, 6, -1, 6, 6, -1},
	{-1, -1, -1, 18, -1, -1, -1, 7, -1, -1, -1, 7, 7, -1, 7, 7, -1},
	{19, 19, 19, 19, 19, 19, 8, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19},
	{-1, -1, -1, -1, -1, -1, -1, 9, -1, -1, -1, -1, -1, -1, 9, 9, -1},
	{21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 10, 21},
	{22, 22, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 11, 11, -1},
	{23, 23, -1, 25, -1, 1, -1, -1, -1, -1, 12, -1, -1, -1, 2, 2, -1},
	{12, 12, -1, 24, -1, 1, -1, 5, -1, -1, 12, -1, -1, -1, 5, 5, -1},
	{12, 12, -1, 25, -1, 1, -1, 7, -1, -1, 12, 7, 7, -1, 7, 7, -1},
	{-1, -1, -1, 14, -1, 15, -1, -1, 14, -1, -1, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, 16, -1, 17, -1, -1, 16, -1, -1, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, 28, -1, -1, -1, 6, -1, -1, -1, 6, 6, -1, 6, 6, -1},
	{-1, -1, -1, 16, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}
};

char	*g_string_automaton[16] =
{
	"r",
	"abcdefghijklmnopqstuvwxyz",
	"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
	"0123456789",
	"%",
	":",
	"\"",
	",",
	"-",
	"+",
	"_",
	"#",
	";",
	".",
	"\t\f ",
	"\n"
};