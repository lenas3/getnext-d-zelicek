void	*ft_memchr(const void *str, int value, size_t size)
{
	unsigned char	*a;
	size_t			i;

	i = 0;
	a = (unsigned char *)str;
	while (i < size)
	{
		if (a[i] == (unsigned char)value)
			return ((void *)&a[i]);
		i++;
	}
	return (NULL);
}

line = ft_memchr(stack, '\n', )