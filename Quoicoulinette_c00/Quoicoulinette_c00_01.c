#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void ft_print_alphabet(void);

void test_ft_print_alphabet(void)
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

        // Appeler la fonction ft_print_alphabet
        ft_print_alphabet();

        // Fermer l'extrémité d'écriture du tube dans le processus fils
        close(pipe_fds[1]);

        // Terminer le processus fils
        exit(0);
    }
    else
    {        
        close(pipe_fds[1]);
        char expected_output[] = "abcdefghijklmnopqrstuvwxyz\n";
        char received_output[27]; // Taille pour stocker les 26 caractères de l'alphabet + le saut de ligne
        ssize_t bytes_read = read(pipe_fds[0], received_output, sizeof(received_output) - 1);

        // Fermer l'extrémité de lecture du tube dans le processus parent
        
        // Vérifier si la lecture a réussi
        printf("\n");
        if (bytes_read == sizeof(received_output) - 1)
        {
            // Comparer la sortie obtenue avec la sortie attendue
            if (memcmp(received_output, expected_output, sizeof(received_output) - 1) == 0)
                printf("Test: \033[1;32mApagnan! :)\033[0m\n");
            else
                printf("Test: \033[1;31mQUOICOUBEH :O\033[0m\n");

            // Afficher la sortie attendue et la sortie obtenue
            printf("Sortie attendue: %s", expected_output);
            printf("Sortie obtenue  : %s", received_output);
            printf("\n");
        }
        else
        {
            printf("Erreur lors de la lecture du tube\n");
        }
        close(pipe_fds[1]);
    }
}

