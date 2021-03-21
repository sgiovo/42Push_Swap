/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_algo_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonegiovo <simonegiovo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 17:13:03 by simonegiovo       #+#    #+#             */
/*   Updated: 2021/03/21 17:55:45 by simonegiovo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"



void    lis(t_lis *lis, t_stack *s)
{
    int i;
    int j;
    
    // DA MODIFICARE
    for (int i = 0; i < lis->len; i++)
        lis->arr[i] = 1;

    lis->max = 0;
    i = 1;
    while(i < lis->len)
    {
        j = 0;
        while(j < i)
        {
            if(s->indexed[i] > s->indexed[j] && lis->arr[i] < lis->arr[j] + 1)
                lis->arr[i] = lis->arr[j] + 1;
            j++;
        }
        i++;
    }
    i = 0;
    while(i < lis->len)
    {
        lis->max = lis->max > lis->arr[i] ? lis->max : lis->arr[i];
        i++;
    }
}

void    lis_select(t_lis *lis)
{
    int i;

    i = lis->len;
    while (--i >= 0)
    {
        if (lis->arr[i] == lis->max && lis->max > 0)
        {
            lis->max--;
            continue;
        }
        lis->arr[i] = 0;
    }
}

int     calc_dir(t_stack *s, int n)
{
    int i;

    i = 0;
    while (i < s->len)
    {
        if (s->indexed[i] == n)
            if (i > s->len / 2)
                return (2);
            return (1);
        i++;
    }
}

int     calc_dist(t_stack *s, int n)
{
    int i;

    i = 0;
    while (i < s->len)
    {
        if (s->indexed[i] == n)
            if (i > s->len / 2)
                return (s->len - i);
            return (i);
        i++;
    }
}
