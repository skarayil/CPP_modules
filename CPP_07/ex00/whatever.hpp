/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 16:19:33 by skarayil          #+#    #+#             */
/*   Updated: 2026/10/10 16:19:35 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T> void swap(T &a, T &b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename T> T const &min(T const &a, T const &b)
{
	return ((b < a) ? b : a);
}

template <typename T> T const &max(T const &a, T const &b)
{
	return ((b > a) ? b : a);
}

#endif
