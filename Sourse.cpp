#include<iostream>

int findMin(int fi, int fn)
{
	int min = 5000;
	if ((fi + fn) < min)
		min = (fi + fn);
	return min;
}

int summ(int n)
{
	int f = n;
	int fi, fn; 
	int min;

	for (int i = 2; i < n / 2+1; i++)
	{ 
		if (f % i != 0)
		{
			f--;
			fi = i;
			fn = f - i;
		}
		else 
		{
			fi = i;
			fn = f - i;
		}
		min = findMin(fi, fn);
		break;
	}
	return min;
}

int multiply(int n)
{
	int f = n;
	int fi, fn;
	int k = 0;
	int min;

	for (int i = 2; i < sqrt(n)+1; i++)
	{
		if (f % i == 0)
		{
			fi = i;
			fn = f/i;
		}
		else 
		{
			f = summ(n);
			fi = i;
			fn = f / i;
			k = n - f;
		}
		min = findMin(fi, fn);
		break;
	}
	return min + k;
}


int main()
{
	setlocale(LC_ALL, "ru");
	int n, k = 0;
	std::cout << "Введите целое число (от 1 до 5000): \n";
	std::cin >> n;

	if (n<1 || n>5000)
	{
		std::cout << "Число больше 5000!";
		return 0;
	}
	std::cout << multiply(n);

	return 0;
}
