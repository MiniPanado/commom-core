#include "ft_printf_bonus.h"

static char	*ft_pad_left_zeros(char *body, size_t target_len)
{
	char	*res;
	size_t	len;
	size_t	pad;
	size_t	i;

	len = ft_strlen(body);
	if (target_len <= len)
		return (body);
	pad = target_len - len;
	res = malloc((target_len + 1) * sizeof(char));
	if (!res)
		return (body);
	i = 0;
	while (i < pad)
		res[i++] = '0';
	while (*body)
		res[i++] = *body++;
	res[i] = '\0';
	return (res);
}

static void	ft_apply_precision_numeric_bonus(t_conv *conv, t_flags *flags)
{
	char	*new_body;

	if (!flags->has_precision)
		return ;
	if (flags->precision == 0 && ft_strlen(conv->body) == 1
		&& conv->body[0] == '0')
	{
		free(conv->body);
		conv->body = ft_strndup("", 0);
		return ;
	}
	new_body = ft_pad_left_zeros(conv->body, flags->precision);
	if (new_body != conv->body)
	{
		free(conv->body);
		conv->body = new_body;
	}
}

static void	ft_apply_precision_string(t_conv *conv, t_flags *flags)
{
	char	*truncated;

	if (!flags->has_precision)
		return ;
	if (flags->precision >= ft_strlen(conv->body))
		return ;
	truncated = ft_strndup(conv->body, flags->precision);
	free(conv->body);
	conv->body = truncated;
}

void	ft_apply_precision_bonus(t_conv *conv, t_flags *flags, char converter)
{
	if (converter == 's')
		ft_apply_precision_string(conv, flags);
	else if (conv->numeric)
		ft_apply_precision_numeric_bonus(conv, flags);
}
