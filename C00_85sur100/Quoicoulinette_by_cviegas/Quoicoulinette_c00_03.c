#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

void ft_print_numbers(void);

void test_ft_print_numbers(void)
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

        // Appeler la fonction ft_print_numbers
        ft_print_numbers();

        // Fermer l'extrémité d'écriture du tube dans le processus fils
        close(pipe_fds[1]);

        // Terminer le processus fils
        exit(0);
    }
    else
    {
        // Fermer l'extrémité d'écriture du tube dans le processus parent
        close(pipe_fds[1]);

        char expected_output[] = "0123456789";
        char received_output[11]; // Taille pour stocker les 10 chiffres + le caractère nul
        ssize_t total_bytes_read = 0;
        ssize_t bytes_read;

        // Lire la sortie du tube par blocs jusqu'à la fin
        while ((bytes_read = read(pipe_fds[0], received_output + total_bytes_read, sizeof(received_output) - total_bytes_read - 1)) > 0)
        {
            total_bytes_read += bytes_read;
        }

        // Fermer l'extrémité de lecture du tube dans le processus parent
        close(pipe_fds[0]);

        // Vérifier si la lecture a réussi
        printf("\n");
        if (bytes_read >= 0)
        {
            received_output[total_bytes_read] = '\0'; // Ajouter le caractère nul à la fin de la chaîne

            // Comparer la sortie obtenue avec la sortie attendue
            if (strcmp(received_output, expected_output) == 0)
                printf("Test: \033[1;32mApagnan! :)\033[0m\n");
            else
                printf("Test: \033[1;31mQUOICOUBEH :O\033[0m\n");

            // Afficher la sortie attendue et la sortie obtenue
            printf("Sortie attendue: %s\n", expected_output);
            printf("Sortie obtenue  : %s\n", received_output);
        }
        else
        {
            printf("Erreur lors de la lecture du tube\n");
        }
    }
}
