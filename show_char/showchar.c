/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   showchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:41:00 by satushi           #+#    #+#             */
/*   Updated: 2022/12/03 20:02:47 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t  obtain_strlen(char *sub)
{
    size_t strlen;

    strlen = 0;
    while (sub[strlen] != '\0')
        strlen++;
    //strlen++;
    return (strlen);
}

void showchar(char *sub)
{
    size_t  char_len;

    char_len = obtain_strlen(sub);
    write(1, sub, char_len);
}

void error_show()
{
    char *error_message;

    error_message = "Error\n";
    write(1, error_message, 7);
}