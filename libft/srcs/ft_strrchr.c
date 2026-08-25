char	*ft_strrchr(const char *s, int c)
{
	const unsigned char	*current;
	unsigned char		target;
	char				*last_pos;

	current = (const unsigned char *)s;
	target = (unsigned char)c;
	last_pos = (char *)0;
	while (*current)
	{
		if (*current == target)
		{
			last_pos = (char *)current;
		}
		current++;
	}
	if (*current == target)
	{
		last_pos = (char *)current;
	}
	return (last_pos);
}
