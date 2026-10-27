#include "ft_printf_bonus.h"

static size_t	ft_content_len_bonus(t_conv *conv)
{
	size_t	len;

	len = (conv->sign != '\0');
	len += ft_strlen(conv->body);
	if (conv->prefix)
	{
		len += ft_strlen(conv->prefix);
	}
	return (len);
}

static size_t	ft_fill_sign_prefix_bonus(char *res, t_conv *conv, size_t i)
{
	size_t	j;

	j = 0;
	if (conv->sign)
	{
		res[i++] = conv->sign;
	}
	if (conv->prefix)
	{
		while (conv->prefix[j] != '\0')
		{
			res[i++] = conv->prefix[j++];
		}
	}
	return (i);
}

static size_t	ft_fill_padding_bonus(char *res, size_t i, int pad, char c)
{
	while (pad-- > 0)
		res[i++] = c;
	return (i);
}

static size_t	ft_fill_body_bonus(char *res, char *body, size_t i)
{
	while (*body)
		res[i++] = *body++;
	return (i);
}

char	*ft_assemble_bonus(t_conv *conv, t_flags *flags, char converter)
{
	size_t	content_len;
	size_t	padding_len;
	size_t	total_len;
	size_t	i;
	char	*res;

	if (converter == '%')
		return (ft_strndup(conv->body, ft_strlen(conv->body)));
	content_len = ft_content_len_bonus(conv);
	padding_len = 0;
	if (flags->width > content_len)
		padding_len = (size_t)flags->width - content_len;
	total_len = content_len + padding_len;
	res = (char *)malloc((total_len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	if (!flags->minus && !ft_zero_padding_applies_bonus(conv, flags))
		i = ft_fill_padding_bonus(res, i, padding_len, ' ');
	i = ft_fill_sign_prefix_bonus(res, conv, i);
	if (ft_zero_padding_applies_bonus(conv, flags))
		i = ft_fill_padding_bonus(res, i, padding_len, '0');
	i = ft_fill_body_bonus(res, conv->body, i);
	if (flags->minus)
		i = ft_fill_padding_bonus(res, i, padding_len, ' ');
	res[i] = '\0';
	return (res);
}
