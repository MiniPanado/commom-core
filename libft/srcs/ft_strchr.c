char	*ft_strchr(const char *s, int c)
{
	const unsigned char	*current;
	unsigned char		target;

	current = (const unsigned char *)s;
	target = (unsigned char)c;
	while (*current)
	{
		if (*current == target)
		{
			return ((char *)current);
		}
		current++;
	}
	if (*current == target)
		return ((char *)current);
	return ((char *)0);
}
