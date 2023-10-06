/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   banner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 03:30:48 by amait-ou          #+#    #+#             */
/*   Updated: 2023/10/06 15:59:47 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	__banner(void)
{
	ft_printf("\x1b[31m");
	ft_printf("   ____                  _____ ____  \n");
	ft_printf("\x1b[32m");
	ft_printf("  / ___|__ _ ___  __ _  |___ /|  _ \\ \n");
	ft_printf(" | |   / _` / __|/ _` |   |_ \\| | | |\n");
	ft_printf(" | |__| (_| \\__ \\ (_| |  ___) | |_| |\n");
	ft_printf("\x1b[0m");
	ft_printf("\x1b[31m");
	ft_printf("  \\____\\__,_|___/\\__,_| |____/|____/ \n\n");
	ft_printf("\x1b[90m");
	ft_printf("Credits: Amine Ait Ouazghour & Youssef Khalil\n\n");
	ft_printf("\x1b[0m");
}
