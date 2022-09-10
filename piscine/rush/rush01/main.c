#include <unistd.h>
#include <stdio.h>

void	print_(char *matrice, int dim);
void	print_row(char *matrice, int index, int dim);
int	inserisci_combs(char *matrice, int dim);
int	inserisci_combn(char *matrice, int dim, int index);
int	inserisci_comb1(char *matrice, int dim, int index);
int	inserisci_comb2(char *matrice, int dim, int index);
int	respective_start(int index, int dim);
int	respective_increment(int index, int dim);
int	inserisci(char *matrice, int index, char input);

int	main(void)
{
	char	matrice[] =	{
				'0','0','0','0',
				'0','0','0','0',
				'0','0','0','0',
				'0','0','0','0',
				// colup
				'2','1','4','2',
				// coldown
				'2','3','1','3',
				// rowleft
				'2','3','1','2',
				// rowright
				'2','1','3','2'
				};

	print_(matrice, 4);
	if (!inserisci_combs(matrice, 4))
		write(1, "INPUT ERROR\n", 12);
	else
		print_(matrice, 4);
}

void	print_(char *matrice, int dim)
{
	int	index;

	write(1, "\t", 1);
	print_row(matrice, dim, dim);
	write(1, "\n\n\n", 3);
	index = 0;
	while (index < dim)
	{
		write(1, &matrice[dim * (dim + 2) + index], 1);
		write(1, "\t", 1);
		print_row(matrice, index, dim);
		write(1, &matrice[dim * (dim + 2) + 4 + index], 1);
		write(1, "\n", 1);
		index++;
	}
	write(1, "\n\n\t", 3);
	print_row(matrice, dim + 1, dim);
	write(1, "\n\n", 2);
}

void	print_row(char *matrice, int index, int dim)
{
	int	start;
	int	counter;

	start = dim * index;
	counter = 0;
	while (counter < dim)
	{
		write(1, &matrice[start + counter], 1);
		write(1, "\t", 1);
		counter++;
	}
}

int	inserisci_combs(char *matrice, int dim)
{
	char	*cella;
	char	*opposta;
	int	i;

	i = 0;
	cella = &matrice[dim * dim];
	opposta = cella + dim;
	while (i < 4*dim)
	{
		if ((*cella == '0' + dim) && (!inserisci_combn(matrice, dim, i)))
			return 0;
		else if ((*cella == '1') && (!inserisci_comb1(matrice, dim, i)))
			return 0;
		else if ((*cella == '2' && *opposta == '0' + dim - 1) && (!inserisci_comb2(matrice, dim, i)))
			return 0;
		cella++;
		if ((++i / 4) % 2 == 0)
			opposta = cella + dim;
		else
			opposta = cella - dim;
	}
	return 1;
}

int	inserisci_combn(char *matrice, int dim, int index)
{
	int	start;
	int	incremento;
	int	i;

	i = 0;
	start = respective_start(index, dim);
	incremento = respective_increment(index, dim);
	while (i < dim)
	{
		if (!inserisci(matrice, start + incremento * i, '1' + i))
			return 0;
		i++;
	}
	return 1;
}

int	inserisci_comb1(char *matrice, int dim, int index)
{
	int	start;

	start = respective_start(index, dim);
	return inserisci(matrice, start, '4');
}

int	inserisci_comb2(char *matrice, int dim, int index)
{
	int	start;
	int	incremento;

	start = respective_start(index, dim);
	incremento = respective_increment(index, dim);
	return inserisci(matrice, start + incremento, '4');
}

int	respective_start(int index, int dim)
{
	int start = index % dim;

	if (index / dim == 0)
		return start;
	else if (index / dim == 1)
		return start + dim * (dim - 1);
	else if (index / dim == 2)
		return start * dim;
	else
		return start * dim + (dim - 1);
}

int	respective_increment(int index, int dim)
{
	if (index / dim == 0)
		return dim;
	else if (index / dim == 1)
		return -dim; 
	else if (index / dim == 2)
		return 1;
	else
		return -1;	
}

int	inserisci(char *matrice, int index, char input)
{
	if (matrice[index] == '0')
		matrice[index] = input;
	else if (matrice[index] != input)
		return 0;
	return 1;
	print_(matrice, 4);
}
