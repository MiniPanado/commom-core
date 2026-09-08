#include "ft_printf_bonus.h"

static int	ft_content_len_bonus(t_conv *conv)
{
	int	len;
 
	len = (conv->sign != '\0');
	len += ft_strlen_bonus(conv->body);
	if (conv->prefix)
		len += ft_strlen_bonus(conv->prefix);
	return (len);
}

char	*ft_assemble_bonus(t_conv *conv, t_flags *flags, char converter)
{
	int		content_len;
	int		total_len;
	char	*res;
	int		i;

	content_len = ft_content_len_bonus(conv);
	total_len = content_len;
	if (flags->width > content_len)
		total_len = flags->width;
	res = (char *)malloc((total_len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
}
