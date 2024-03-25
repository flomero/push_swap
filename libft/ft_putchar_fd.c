/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:50:21 by flfische          #+#    #+#             */
/*   Updated: 2024/03/20 12:36:18 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief outputs the character c to the given file descriptor
 * @param c character to output
 * @param fd file descriptor to output to
 * @return number of bytes written
 */
int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
