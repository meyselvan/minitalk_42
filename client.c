/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relvan <relvan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:54:04 by relvan            #+#    #+#             */
/*   Updated: 2023/12/23 19:50:33 by relvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

int	ft_atoi_pid(char *str)
{
	int	number;
	int	i;

	number = 0;
	i = 0;
	if (str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		number = number * 10 + (str[i] - 48);
		i++;
	}
	return (number);
}

int	ft_checkerrror_pid(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] <= '9' && str[i] >= '0')
			i++;
		else
			return (0);
	}
	return (1);
}

void	ft_send_signal(int pid, char c)
{
	int	bin;
	int	i;

	bin = (int)c;
	i = 7;
	while (i >= 0)
	{
		bin = c >> i--;
		if ((bin & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3 && ft_checkerrror_pid(argv[1]))
	{
		pid = ft_atoi_pid(argv[1]);
		while (argv[2] && argv[2][i])
			ft_send_signal(pid, argv[2][i++]);
		ft_send_signal(pid, '\n');
	}
	else if (argc < 3)
		write(1, "This program cannot accept less than three arguments.\n", 54);
	else if (argc > 3)
		write(1, "This program cannot accept more than three arguments.\n", 54);
	else
		write(1, "The PID is in the wrong format, please double-check.\n", 63);
	return (0);
}
