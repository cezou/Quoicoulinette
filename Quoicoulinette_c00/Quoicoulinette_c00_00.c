#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void ft_putchar(char c);

void test_ft_putchar(void)
{
    // Caractères à tester
    char test_chars[] = {'A', 'B', 'C'};
    int num_tests = sizeof(test_chars) / sizeof(test_chars[0]);

    for (int i = 0; i < num_tests; i++)
    {
        // Rediriger la sortie standard vers un tube (pipe)
        int pipe_fds[2];
        pipe(pipe_fds);

        // Créer un nouveau processus pour éviter la lecture bloquante du tube
        pid_t pid = fork();
        if (pid == -1)
        {
            fprintf(stderr, "Erreur lors de la création du processus\n");
            return;
        }
        else if (pid == 0)
        {
            // Fermer l'extrémité de lecture du tube dans le processus fils
            close(pipe_fds[0]);

            // Rediriger la sortie standard vers l'extrémité d'écriture du tube
            dup2(pipe_fds[1], STDOUT_FILENO);

            // Appeler la fonction ft_putchar avec le caractère en cours de test
            ft_putchar(test_chars[i]);

            // Fermer l'extrémité d'écriture du tube dans le processus fils
            close(pipe_fds[1]);

            // Terminer le processus fils
            _exit(0);
        }
        else
        {
            // Fermer l'extrémité d'écriture du tube dans le processus parent
            close(pipe_fds[1]);

            // Lire le contenu du tube (pipe)
            char output_char;
            ssize_t bytes_read = read(pipe_fds[0], &output_char, sizeof(output_char));

            // Fermer l'extrémité de lecture du tube dans le processus parent
            close(pipe_fds[0]);

            // Vérifier si la lecture a réussi
            printf("\n");
            if (bytes_read == sizeof(output_char))
            {
                // Comparer la sortie obtenue avec le caractère attendu
                if (output_char == test_chars[i])
                    printf("Test %d: \033[1;32mApagnan! :)\033[0m\n", i + 1);
                else
                    printf("Test %d: \033[1;31mQUOICOUBEH :O\033[0m\n", i + 1);

                // Afficher le caractère attendu et la sortie obtenue
                printf("Caractère attendu: %c\n", test_chars[i]);
                printf("Sortie obtenue: %c\n", output_char);
                printf("\n");
            }
            else
            {
                printf("Erreur lors de la lecture du tube\n");
            }
        }
    }
}
