#include <stdio.h>

// Déclarations des fonctions de test
void test_ft_putchar(void);
void test_ft_print_alphabet(void);
void test_ft_print_reverse_alphabet(void);
void test_ft_print_numbers(void);
void test_ft_is_negative(void);
void test_ft_print_comb(void);
void test_ft_print_comb2(void);


int main(int argc, char **argv)
{
    if (argc == 2)
    {
        if (argv[1][0] == '0' && argv[1][1] == '0')
            test_ft_putchar();
        else if (argv[1][0] == '0' && argv[1][1] == '1')
            test_ft_print_alphabet();
        else if (argv[1][0] == '0' && argv[1][1] == '2')
            test_ft_print_reverse_alphabet();
        else if (argv[1][0] == '0' && argv[1][1] == '3')
            test_ft_print_numbers();
        else if (argv[1][0] == '0' && argv[1][1] == '4')
            test_ft_is_negative();
        else if (argv[1][0] == '0' && argv[1][1] == '5')
            test_ft_print_comb();
        else if (argv[1][0] == '0' && argv[1][1] == '6')
            test_ft_print_comb2();
        else
            printf("Mauvais argument\n");
    }
    else
    {
        printf("Mauvais argument\n");
    }

    return 0;
}
