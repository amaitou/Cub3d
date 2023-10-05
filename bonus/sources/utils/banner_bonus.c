/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   banner_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 03:30:48 by amait-ou          #+#    #+#             */
/*   Updated: 2023/10/05 18:11:48 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	__banner(void)
{
	printf("\x1b[31m");
	printf("   ____                  _____ ____  \n");
	printf("\x1b[32m");
	printf("  / ___|__ _ ___  __ _  |___ /|  _ \\ \n");
	printf(" | |   / _` / __|/ _` |   |_ \\| | | |\n");
	printf(" | |__| (_| \\__ \\ (_| |  ___) | |_| |\n");
	printf("\x1b[0m");
	printf("\x1b[31m");
	printf("  \\____\\__,_|___/\\__,_| |____/|____/ \n\n");
	printf("\x1b[90m");
	printf("Credits: Amine Ait Ouazghour & Youssef Khalil\n\n");
	printf("\x1b[0m");
}
