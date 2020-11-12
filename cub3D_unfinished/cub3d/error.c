static void	inv_file(void)
{
	write(2, "INVALID FILE\n", 13);
	exit(0);
}