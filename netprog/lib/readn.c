/*
 * Read "n" bytes from a descriptor.
 * Use in place of read() when fd is a stream socket.
 */

int
readn(fd, ptr, nbytes)
register int	fd;
register char	*ptr;
register int	nbytes;
{
	int	nleft, nread;

	nleft = nbytes;
	while (nleft > 0) {
		nread = read(fd, ptr, nleft);
		if (nread < 0)
			return(nread);		/* error, return < 0 */
		else if (nread == 0)
			break;			/* EOF */

		nleft -= nread;
		ptr   += nread;
	}
	return(nbytes - nleft);		/* return >= 0 */
}
