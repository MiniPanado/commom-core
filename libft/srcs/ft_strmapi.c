#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*mapped;
	unsigned int	i;

	if (!s)
		return (NULL);
	mapped = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!mapped)
		return (NULL);
	i = 0;
	while (s[i])
	{
		mapped[i] = f(i, s[i]);
		i++;
	}
	mapped[i] = '\0';
	return (mapped);
}
