#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void ft_print_comb2(void);

void test_ft_print_comb2(void)
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

        // Appeler la fonction ft_print_comb2
        ft_print_comb2();

        // Fermer l'extrémité d'écriture du tube dans le processus fils
        close(pipe_fds[1]);

        // Terminer le processus fils
        exit(0);
    }
    else
    {
        close(pipe_fds[1]);
        // Chaine Attendue
        printf("// Chaine Attendue\n");

        // Fermer l'extrémité de lecture du tube dans le processus parent

        // Lire la sortie du tube
        char expected_output[34649] = "00 01, 00 02, 00 03, 00 04, 00 05, 00 06, 00 07, 00 08, 00 09, 00 10, 00 11, 00 12, 00 13, 00 14, 00 15, 00 16, 00 17, 00 18, 00 19, 00 20, 00 21, 00 22, 00 23, 00 24, 00 25, 00 26, 00 27, 00 28, 00 29, 00 30, 00 31, 00 32, 00 33, 00 34, 00 35, 00 36, 00 37, 00 38, 00 39, 00 40, 00 41, 00 42, 00 43, 00 44, 00 45, 00 46, 00 47, 00 48, 00 49, 00 50, 00 51, 00 52, 00 53, 00 54, 00 55, 00 56, 00 57, 00 58, 00 59, 00 60, 00 61, 00 62, 00 63, 00 64, 00 65, 00 66, 00 67, 00 68, 00 69, 00 70, 00 71, 00 72, 00 73, 00 74, 00 75, 00 76, 00 77, 00 78, 00 79, 00 80, 00 81, 00 82, 00 83, 00 84, 00 85, 00 86, 00 87, 00 88, 00 89, 00 90, 00 91, 00 92, 00 93, 00 94, 00 95, 00 96, 00 97, 00 98, 00 99, 01 02, 01 03, 01 04, 01 05, 01 06, 01 07, 01 08, 01 09, 01 10, 01 11, 01 12, 01 13, 01 14, 01 15, 01 16, 01 17, 01 18, 01 19, 01 20, 01 21, 01 22, 01 23, 01 24, 01 25, 01 26, 01 27, 01 28, 01 29, 01 30, 01 31, 01 32, 01 33, 01 34, 01 35, 01 36, 01 37, 01 38, 01 39, 01 40, 01 41, 01 42, 01 43, 01 44, 01 45, 01 46, 01 47, 01 48, 01 49, 01 50, 01 51, 01 52, 01 53, 01 54, 01 55, 01 56, 01 57, 01 58, 01 59, 01 60, 01 61, 01 62, 01 63, 01 64, 01 65, 01 66, 01 67, 01 68, 01 69, 01 70, 01 71, 01 72, 01 73, 01 74, 01 75, 01 76, 01 77, 01 78, 01 79, 01 80, 01 81, 01 82, 01 83, 01 84, 01 85, 01 86, 01 87, 01 88, 01 89, 01 90, 01 91, 01 92, 01 93, 01 94, 01 95, 01 96, 01 97, 01 98, 01 99, 02 03, 02 04, 02 05, 02 06, 02 07, 02 08, 02 09, 02 10, 02 11, 02 12, 02 13, 02 14, 02 15, 02 16, 02 17, 02 18, 02 19, 02 20, 02 21, 02 22, 02 23, 02 24, 02 25, 02 26, 02 27, 02 28, 02 29, 02 30, 02 31, 02 32, 02 33, 02 34, 02 35, 02 36, 02 37, 02 38, 02 39, 02 40, 02 41, 02 42, 02 43, 02 44, 02 45, 02 46, 02 47, 02 48, 02 49, 02 50, 02 51, 02 52, 02 53, 02 54, 02 55, 02 56, 02 57, 02 58, 02 59, 02 60, 02 61, 02 62, 02 63, 02 64, 02 65, 02 66, 02 67, 02 68, 02 69, 02 70, 02 71, 02 72, 02 73, 02 74, 02 75, 02 76, 02 77, 02 78, 02 79, 02 80, 02 81, 02 82, 02 83, 02 84, 02 85, 02 86, 02 87, 02 88, 02 89, 02 90, 02 91, 02 92, 02 93, 02 94, 02 95, 02 96, 02 97, 02 98, 02 99, 03 04, 03 05, 03 06, 03 07, 03 08, 03 09, 03 10, 03 11, 03 12, 03 13, 03 14, 03 15, 03 16, 03 17, 03 18, 03 19, 03 20, 03 21, 03 22, 03 23, 03 24, 03 25, 03 26, 03 27, 03 28, 03 29, 03 30, 03 31, 03 32, 03 33, 03 34, 03 35, 03 36, 03 37, 03 38, 03 39, 03 40, 03 41, 03 42, 03 43, 03 44, 03 45, 03 46, 03 47, 03 48, 03 49, 03 50, 03 51, 03 52, 03 53, 03 54, 03 55, 03 56, 03 57, 03 58, 03 59, 03 60, 03 61, 03 62, 03 63, 03 64, 03 65, 03 66, 03 67, 03 68, 03 69, 03 70, 03 71, 03 72, 03 73, 03 74, 03 75, 03 76, 03 77, 03 78, 03 79, 03 80, 03 81, 03 82, 03 83, 03 84, 03 85, 03 86, 03 87, 03 88, 03 89, 03 90, 03 91, 03 92, 03 93, 03 94, 03 95, 03 96, 03 97, 03 98, 03 99, 04 05, 04 06, 04 07, 04 08, 04 09, 04 10, 04 11, 04 12, 04 13, 04 14, 04 15, 04 16, 04 17, 04 18, 04 19, 04 20, 04 21, 04 22, 04 23, 04 24, 04 25, 04 26, 04 27, 04 28, 04 29, 04 30, 04 31, 04 32, 04 33, 04 34, 04 35, 04 36, 04 37, 04 38, 04 39, 04 40, 04 41, 04 42, 04 43, 04 44, 04 45, 04 46, 04 47, 04 48, 04 49, 04 50, 04 51, 04 52, 04 53, 04 54, 04 55, 04 56, 04 57, 04 58, 04 59, 04 60, 04 61, 04 62, 04 63, 04 64, 04 65, 04 66, 04 67, 04 68, 04 69, 04 70, 04 71, 04 72, 04 73, 04 74, 04 75, 04 76, 04 77, 04 78, 04 79, 04 80, 04 81, 04 82, 04 83, 04 84, 04 85, 04 86, 04 87, 04 88, 04 89, 04 90, 04 91, 04 92, 04 93, 04 94, 04 95, 04 96, 04 97, 04 98, 04 99, 05 06, 05 07, 05 08, 05 09, 05 10, 05 11, 05 12, 05 13, 05 14, 05 15, 05 16, 05 17, 05 18, 05 19, 05 20, 05 21, 05 22, 05 23, 05 24, 05 25, 05 26, 05 27, 05 28, 05 29, 05 30, 05 31, 05 32, 05 33, 05 34, 05 35, 05 36, 05 37, 05 38, 05 39, 05 40, 05 41, 05 42, 05 43, 05 44, 05 45, 05 46, 05 47, 05 48, 05 49, 05 50, 05 51, 05 52, 05 53, 05 54, 05 55, 05 56, 05 57, 05 58, 05 59, 05 60, 05 61, 05 62, 05 63, 05 64, 05 65, 05 66, 05 67, 05 68, 05 69, 05 70, 05 71, 05 72, 05 73, 05 74, 05 75, 05 76, 05 77, 05 78, 05 79, 05 80, 05 81, 05 82, 05 83, 05 84, 05 85, 05 86, 05 87, 05 88, 05 89, 05 90, 05 91, 05 92, 05 93, 05 94, 05 95, 05 96, 05 97, 05 98, 05 99, 06 07, 06 08, 06 09, 06 10, 06 11, 06 12, 06 13, 06 14, 06 15, 06 16, 06 17, 06 18, 06 19, 06 20, 06 21, 06 22, 06 23, 06 24, 06 25, 06 26, 06 27, 06 28, 06 29, 06 30, 06 31, 06 32, 06 33, 06 34, 06 35, 06 36, 06 37, 06 38, 06 39, 06 40, 06 41, 06 42, 06 43, 06 44, 06 45, 06 46, 06 47, 06 48, 06 49, 06 50, 06 51, 06 52, 06 53, 06 54, 06 55, 06 56, 06 57, 06 58, 06 59, 06 60, 06 61, 06 62, 06 63, 06 64, 06 65, 06 66, 06 67, 06 68, 06 69, 06 70, 06 71, 06 72, 06 73, 06 74, 06 75, 06 76, 06 77, 06 78, 06 79, 06 80, 06 81, 06 82, 06 83, 06 84, 06 85, 06 86, 06 87, 06 88, 06 89, 06 90, 06 91, 06 92, 06 93, 06 94, 06 95, 06 96, 06 97, 06 98, 06 99, 07 08, 07 09, 07 10, 07 11, 07 12, 07 13, 07 14, 07 15, 07 16, 07 17, 07 18, 07 19, 07 20, 07 21, 07 22, 07 23, 07 24, 07 25, 07 26, 07 27, 07 28, 07 29, 07 30, 07 31, 07 32, 07 33, 07 34, 07 35, 07 36, 07 37, 07 38, 07 39, 07 40, 07 41, 07 42, 07 43, 07 44, 07 45, 07 46, 07 47, 07 48, 07 49, 07 50, 07 51, 07 52, 07 53, 07 54, 07 55, 07 56, 07 57, 07 58, 07 59, 07 60, 07 61, 07 62, 07 63, 07 64, 07 65, 07 66, 07 67, 07 68, 07 69, 07 70, 07 71, 07 72, 07 73, 07 74, 07 75, 07 76, 07 77, 07 78, 07 79, 07 80, 07 81, 07 82, 07 83, 07 84, 07 85, 07 86, 07 87, 07 88, 07 89, 07 90, 07 91, 07 92, 07 93, 07 94, 07 95, 07 96, 07 97, 07 98, 07 99, 08 09, 08 10, 08 11, 08 12, 08 13, 08 14, 08 15, 08 16, 08 17, 08 18, 08 19, 08 20, 08 21, 08 22, 08 23, 08 24, 08 25, 08 26, 08 27, 08 28, 08 29, 08 30, 08 31, 08 32, 08 33, 08 34, 08 35, 08 36, 08 37, 08 38, 08 39, 08 40, 08 41, 08 42, 08 43, 08 44, 08 45, 08 46, 08 47, 08 48, 08 49, 08 50, 08 51, 08 52, 08 53, 08 54, 08 55, 08 56, 08 57, 08 58, 08 59, 08 60, 08 61, 08 62, 08 63, 08 64, 08 65, 08 66, 08 67, 08 68, 08 69, 08 70, 08 71, 08 72, 08 73, 08 74, 08 75, 08 76, 08 77, 08 78, 08 79, 08 80, 08 81, 08 82, 08 83, 08 84, 08 85, 08 86, 08 87, 08 88, 08 89, 08 90, 08 91, 08 92, 08 93, 08 94, 08 95, 08 96, 08 97, 08 98, 08 99, 09 10, 09 11, 09 12, 09 13, 09 14, 09 15, 09 16, 09 17, 09 18, 09 19, 09 20, 09 21, 09 22, 09 23, 09 24, 09 25, 09 26, 09 27, 09 28, 09 29, 09 30, 09 31, 09 32, 09 33, 09 34, 09 35, 09 36, 09 37, 09 38, 09 39, 09 40, 09 41, 09 42, 09 43, 09 44, 09 45, 09 46, 09 47, 09 48, 09 49, 09 50, 09 51, 09 52, 09 53, 09 54, 09 55, 09 56, 09 57, 09 58, 09 59, 09 60, 09 61, 09 62, 09 63, 09 64, 09 65, 09 66, 09 67, 09 68, 09 69, 09 70, 09 71, 09 72, 09 73, 09 74, 09 75, 09 76, 09 77, 09 78, 09 79, 09 80, 09 81, 09 82, 09 83, 09 84, 09 85, 09 86, 09 87, 09 88, 09 89, 09 90, 09 91, 09 92, 09 93, 09 94, 09 95, 09 96, 09 97, 09 98, 09 99, 10 11, 10 12, 10 13, 10 14, 10 15, 10 16, 10 17, 10 18, 10 19, 10 20, 10 21, 10 22, 10 23, 10 24, 10 25, 10 26, 10 27, 10 28, 10 29, 10 30, 10 31, 10 32, 10 33, 10 34, 10 35, 10 36, 10 37, 10 38, 10 39, 10 40, 10 41, 10 42, 10 43, 10 44, 10 45, 10 46, 10 47, 10 48, 10 49, 10 50, 10 51, 10 52, 10 53, 10 54, 10 55, 10 56, 10 57, 10 58, 10 59, 10 60, 10 61, 10 62, 10 63, 10 64, 10 65, 10 66, 10 67, 10 68, 10 69, 10 70, 10 71, 10 72, 10 73, 10 74, 10 75, 10 76, 10 77, 10 78, 10 79, 10 80, 10 81, 10 82, 10 83, 10 84, 10 85, 10 86, 10 87, 10 88, 10 89, 10 90, 10 91, 10 92, 10 93, 10 94, 10 95, 10 96, 10 97, 10 98, 10 99, 11 12, 11 13, 11 14, 11 15, 11 16, 11 17, 11 18, 11 19, 11 20, 11 21, 11 22, 11 23, 11 24, 11 25, 11 26, 11 27, 11 28, 11 29, 11 30, 11 31, 11 32, 11 33, 11 34, 11 35, 11 36, 11 37, 11 38, 11 39, 11 40, 11 41, 11 42, 11 43, 11 44, 11 45, 11 46, 11 47, 11 48, 11 49, 11 50, 11 51, 11 52, 11 53, 11 54, 11 55, 11 56, 11 57, 11 58, 11 59, 11 60, 11 61, 11 62, 11 63, 11 64, 11 65, 11 66, 11 67, 11 68, 11 69, 11 70, 11 71, 11 72, 11 73, 11 74, 11 75, 11 76, 11 77, 11 78, 11 79, 11 80, 11 81, 11 82, 11 83, 11 84, 11 85, 11 86, 11 87, 11 88, 11 89, 11 90, 11 91, 11 92, 11 93, 11 94, 11 95, 11 96, 11 97, 11 98, 11 99, 12 13, 12 14, 12 15, 12 16, 12 17, 12 18, 12 19, 12 20, 12 21, 12 22, 12 23, 12 24, 12 25, 12 26, 12 27, 12 28, 12 29, 12 30, 12 31, 12 32, 12 33, 12 34, 12 35, 12 36, 12 37, 12 38, 12 39, 12 40, 12 41, 12 42, 12 43, 12 44, 12 45, 12 46, 12 47, 12 48, 12 49, 12 50, 12 51, 12 52, 12 53, 12 54, 12 55, 12 56, 12 57, 12 58, 12 59, 12 60, 12 61, 12 62, 12 63, 12 64, 12 65, 12 66, 12 67, 12 68, 12 69, 12 70, 12 71, 12 72, 12 73, 12 74, 12 75, 12 76, 12 77, 12 78, 12 79, 12 80, 12 81, 12 82, 12 83, 12 84, 12 85, 12 86, 12 87, 12 88, 12 89, 12 90, 12 91, 12 92, 12 93, 12 94, 12 95, 12 96, 12 97, 12 98, 12 99, 13 14, 13 15, 13 16, 13 17, 13 18, 13 19, 13 20, 13 21, 13 22, 13 23, 13 24, 13 25, 13 26, 13 27, 13 28, 13 29, 13 30, 13 31, 13 32, 13 33, 13 34, 13 35, 13 36, 13 37, 13 38, 13 39, 13 40, 13 41, 13 42, 13 43, 13 44, 13 45, 13 46, 13 47, 13 48, 13 49, 13 50, 13 51, 13 52, 13 53, 13 54, 13 55, 13 56, 13 57, 13 58, 13 59, 13 60, 13 61, 13 62, 13 63, 13 64, 13 65, 13 66, 13 67, 13 68, 13 69, 13 70, 13 71, 13 72, 13 73, 13 74, 13 75, 13 76, 13 77, 13 78, 13 79, 13 80, 13 81, 13 82, 13 83, 13 84, 13 85, 13 86, 13 87, 13 88, 13 89, 13 90, 13 91, 13 92, 13 93, 13 94, 13 95, 13 96, 13 97, 13 98, 13 99, 14 15, 14 16, 14 17, 14 18, 14 19, 14 20, 14 21, 14 22, 14 23, 14 24, 14 25, 14 26, 14 27, 14 28, 14 29, 14 30, 14 31, 14 32, 14 33, 14 34, 14 35, 14 36, 14 37, 14 38, 14 39, 14 40, 14 41, 14 42, 14 43, 14 44, 14 45, 14 46, 14 47, 14 48, 14 49, 14 50, 14 51, 14 52, 14 53, 14 54, 14 55, 14 56, 14 57, 14 58, 14 59, 14 60, 14 61, 14 62, 14 63, 14 64, 14 65, 14 66, 14 67, 14 68, 14 69, 14 70, 14 71, 14 72, 14 73, 14 74, 14 75, 14 76, 14 77, 14 78, 14 79, 14 80, 14 81, 14 82, 14 83, 14 84, 14 85, 14 86, 14 87, 14 88, 14 89, 14 90, 14 91, 14 92, 14 93, 14 94, 14 95, 14 96, 14 97, 14 98, 14 99, 15 16, 15 17, 15 18, 15 19, 15 20, 15 21, 15 22, 15 23, 15 24, 15 25, 15 26, 15 27, 15 28, 15 29, 15 30, 15 31, 15 32, 15 33, 15 34, 15 35, 15 36, 15 37, 15 38, 15 39, 15 40, 15 41, 15 42, 15 43, 15 44, 15 45, 15 46, 15 47, 15 48, 15 49, 15 50, 15 51, 15 52, 15 53, 15 54, 15 55, 15 56, 15 57, 15 58, 15 59, 15 60, 15 61, 15 62, 15 63, 15 64, 15 65, 15 66, 15 67, 15 68, 15 69, 15 70, 15 71, 15 72, 15 73, 15 74, 15 75, 15 76, 15 77, 15 78, 15 79, 15 80, 15 81, 15 82, 15 83, 15 84, 15 85, 15 86, 15 87, 15 88, 15 89, 15 90, 15 91, 15 92, 15 93, 15 94, 15 95, 15 96, 15 97, 15 98, 15 99, 16 17, 16 18, 16 19, 16 20, 16 21, 16 22, 16 23, 16 24, 16 25, 16 26, 16 27, 16 28, 16 29, 16 30, 16 31, 16 32, 16 33, 16 34, 16 35, 16 36, 16 37, 16 38, 16 39, 16 40, 16 41, 16 42, 16 43, 16 44, 16 45, 16 46, 16 47, 16 48, 16 49, 16 50, 16 51, 16 52, 16 53, 16 54, 16 55, 16 56, 16 57, 16 58, 16 59, 16 60, 16 61, 16 62, 16 63, 16 64, 16 65, 16 66, 16 67, 16 68, 16 69, 16 70, 16 71, 16 72, 16 73, 16 74, 16 75, 16 76, 16 77, 16 78, 16 79, 16 80, 16 81, 16 82, 16 83, 16 84, 16 85, 16 86, 16 87, 16 88, 16 89, 16 90, 16 91, 16 92, 16 93, 16 94, 16 95, 16 96, 16 97, 16 98, 16 99, 17 18, 17 19, 17 20, 17 21, 17 22, 17 23, 17 24, 17 25, 17 26, 17 27, 17 28, 17 29, 17 30, 17 31, 17 32, 17 33, 17 34, 17 35, 17 36, 17 37, 17 38, 17 39, 17 40, 17 41, 17 42, 17 43, 17 44, 17 45, 17 46, 17 47, 17 48, 17 49, 17 50, 17 51, 17 52, 17 53, 17 54, 17 55, 17 56, 17 57, 17 58, 17 59, 17 60, 17 61, 17 62, 17 63, 17 64, 17 65, 17 66, 17 67, 17 68, 17 69, 17 70, 17 71, 17 72, 17 73, 17 74, 17 75, 17 76, 17 77, 17 78, 17 79, 17 80, 17 81, 17 82, 17 83, 17 84, 17 85, 17 86, 17 87, 17 88, 17 89, 17 90, 17 91, 17 92, 17 93, 17 94, 17 95, 17 96, 17 97, 17 98, 17 99, 18 19, 18 20, 18 21, 18 22, 18 23, 18 24, 18 25, 18 26, 18 27, 18 28, 18 29, 18 30, 18 31, 18 32, 18 33, 18 34, 18 35, 18 36, 18 37, 18 38, 18 39, 18 40, 18 41, 18 42, 18 43, 18 44, 18 45, 18 46, 18 47, 18 48, 18 49, 18 50, 18 51, 18 52, 18 53, 18 54, 18 55, 18 56, 18 57, 18 58, 18 59, 18 60, 18 61, 18 62, 18 63, 18 64, 18 65, 18 66, 18 67, 18 68, 18 69, 18 70, 18 71, 18 72, 18 73, 18 74, 18 75, 18 76, 18 77, 18 78, 18 79, 18 80, 18 81, 18 82, 18 83, 18 84, 18 85, 18 86, 18 87, 18 88, 18 89, 18 90, 18 91, 18 92, 18 93, 18 94, 18 95, 18 96, 18 97, 18 98, 18 99, 19 20, 19 21, 19 22, 19 23, 19 24, 19 25, 19 26, 19 27, 19 28, 19 29, 19 30, 19 31, 19 32, 19 33, 19 34, 19 35, 19 36, 19 37, 19 38, 19 39, 19 40, 19 41, 19 42, 19 43, 19 44, 19 45, 19 46, 19 47, 19 48, 19 49, 19 50, 19 51, 19 52, 19 53, 19 54, 19 55, 19 56, 19 57, 19 58, 19 59, 19 60, 19 61, 19 62, 19 63, 19 64, 19 65, 19 66, 19 67, 19 68, 19 69, 19 70, 19 71, 19 72, 19 73, 19 74, 19 75, 19 76, 19 77, 19 78, 19 79, 19 80, 19 81, 19 82, 19 83, 19 84, 19 85, 19 86, 19 87, 19 88, 19 89, 19 90, 19 91, 19 92, 19 93, 19 94, 19 95, 19 96, 19 97, 19 98, 19 99, 20 21, 20 22, 20 23, 20 24, 20 25, 20 26, 20 27, 20 28, 20 29, 20 30, 20 31, 20 32, 20 33, 20 34, 20 35, 20 36, 20 37, 20 38, 20 39, 20 40, 20 41, 20 42, 20 43, 20 44, 20 45, 20 46, 20 47, 20 48, 20 49, 20 50, 20 51, 20 52, 20 53, 20 54, 20 55, 20 56, 20 57, 20 58, 20 59, 20 60, 20 61, 20 62, 20 63, 20 64, 20 65, 20 66, 20 67, 20 68, 20 69, 20 70, 20 71, 20 72, 20 73, 20 74, 20 75, 20 76, 20 77, 20 78, 20 79, 20 80, 20 81, 20 82, 20 83, 20 84, 20 85, 20 86, 20 87, 20 88, 20 89, 20 90, 20 91, 20 92, 20 93, 20 94, 20 95, 20 96, 20 97, 20 98, 20 99, 21 22, 21 23, 21 24, 21 25, 21 26, 21 27, 21 28, 21 29, 21 30, 21 31, 21 32, 21 33, 21 34, 21 35, 21 36, 21 37, 21 38, 21 39, 21 40, 21 41, 21 42, 21 43, 21 44, 21 45, 21 46, 21 47, 21 48, 21 49, 21 50, 21 51, 21 52, 21 53, 21 54, 21 55, 21 56, 21 57, 21 58, 21 59, 21 60, 21 61, 21 62, 21 63, 21 64, 21 65, 21 66, 21 67, 21 68, 21 69, 21 70, 21 71, 21 72, 21 73, 21 74, 21 75, 21 76, 21 77, 21 78, 21 79, 21 80, 21 81, 21 82, 21 83, 21 84, 21 85, 21 86, 21 87, 21 88, 21 89, 21 90, 21 91, 21 92, 21 93, 21 94, 21 95, 21 96, 21 97, 21 98, 21 99, 22 23, 22 24, 22 25, 22 26, 22 27, 22 28, 22 29, 22 30, 22 31, 22 32, 22 33, 22 34, 22 35, 22 36, 22 37, 22 38, 22 39, 22 40, 22 41, 22 42, 22 43, 22 44, 22 45, 22 46, 22 47, 22 48, 22 49, 22 50, 22 51, 22 52, 22 53, 22 54, 22 55, 22 56, 22 57, 22 58, 22 59, 22 60, 22 61, 22 62, 22 63, 22 64, 22 65, 22 66, 22 67, 22 68, 22 69, 22 70, 22 71, 22 72, 22 73, 22 74, 22 75, 22 76, 22 77, 22 78, 22 79, 22 80, 22 81, 22 82, 22 83, 22 84, 22 85, 22 86, 22 87, 22 88, 22 89, 22 90, 22 91, 22 92, 22 93, 22 94, 22 95, 22 96, 22 97, 22 98, 22 99, 23 24, 23 25, 23 26, 23 27, 23 28, 23 29, 23 30, 23 31, 23 32, 23 33, 23 34, 23 35, 23 36, 23 37, 23 38, 23 39, 23 40, 23 41, 23 42, 23 43, 23 44, 23 45, 23 46, 23 47, 23 48, 23 49, 23 50, 23 51, 23 52, 23 53, 23 54, 23 55, 23 56, 23 57, 23 58, 23 59, 23 60, 23 61, 23 62, 23 63, 23 64, 23 65, 23 66, 23 67, 23 68, 23 69, 23 70, 23 71, 23 72, 23 73, 23 74, 23 75, 23 76, 23 77, 23 78, 23 79, 23 80, 23 81, 23 82, 23 83, 23 84, 23 85, 23 86, 23 87, 23 88, 23 89, 23 90, 23 91, 23 92, 23 93, 23 94, 23 95, 23 96, 23 97, 23 98, 23 99, 24 25, 24 26, 24 27, 24 28, 24 29, 24 30, 24 31, 24 32, 24 33, 24 34, 24 35, 24 36, 24 37, 24 38, 24 39, 24 40, 24 41, 24 42, 24 43, 24 44, 24 45, 24 46, 24 47, 24 48, 24 49, 24 50, 24 51, 24 52, 24 53, 24 54, 24 55, 24 56, 24 57, 24 58, 24 59, 24 60, 24 61, 24 62, 24 63, 24 64, 24 65, 24 66, 24 67, 24 68, 24 69, 24 70, 24 71, 24 72, 24 73, 24 74, 24 75, 24 76, 24 77, 24 78, 24 79, 24 80, 24 81, 24 82, 24 83, 24 84, 24 85, 24 86, 24 87, 24 88, 24 89, 24 90, 24 91, 24 92, 24 93, 24 94, 24 95, 24 96, 24 97, 24 98, 24 99, 25 26, 25 27, 25 28, 25 29, 25 30, 25 31, 25 32, 25 33, 25 34, 25 35, 25 36, 25 37, 25 38, 25 39, 25 40, 25 41, 25 42, 25 43, 25 44, 25 45, 25 46, 25 47, 25 48, 25 49, 25 50, 25 51, 25 52, 25 53, 25 54, 25 55, 25 56, 25 57, 25 58, 25 59, 25 60, 25 61, 25 62, 25 63, 25 64, 25 65, 25 66, 25 67, 25 68, 25 69, 25 70, 25 71, 25 72, 25 73, 25 74, 25 75, 25 76, 25 77, 25 78, 25 79, 25 80, 25 81, 25 82, 25 83, 25 84, 25 85, 25 86, 25 87, 25 88, 25 89, 25 90, 25 91, 25 92, 25 93, 25 94, 25 95, 25 96, 25 97, 25 98, 25 99, 26 27, 26 28, 26 29, 26 30, 26 31, 26 32, 26 33, 26 34, 26 35, 26 36, 26 37, 26 38, 26 39, 26 40, 26 41, 26 42, 26 43, 26 44, 26 45, 26 46, 26 47, 26 48, 26 49, 26 50, 26 51, 26 52, 26 53, 26 54, 26 55, 26 56, 26 57, 26 58, 26 59, 26 60, 26 61, 26 62, 26 63, 26 64, 26 65, 26 66, 26 67, 26 68, 26 69, 26 70, 26 71, 26 72, 26 73, 26 74, 26 75, 26 76, 26 77, 26 78, 26 79, 26 80, 26 81, 26 82, 26 83, 26 84, 26 85, 26 86, 26 87, 26 88, 26 89, 26 90, 26 91, 26 92, 26 93, 26 94, 26 95, 26 96, 26 97, 26 98, 26 99, 27 28, 27 29, 27 30, 27 31, 27 32, 27 33, 27 34, 27 35, 27 36, 27 37, 27 38, 27 39, 27 40, 27 41, 27 42, 27 43, 27 44, 27 45, 27 46, 27 47, 27 48, 27 49, 27 50, 27 51, 27 52, 27 53, 27 54, 27 55, 27 56, 27 57, 27 58, 27 59, 27 60, 27 61, 27 62, 27 63, 27 64, 27 65, 27 66, 27 67, 27 68, 27 69, 27 70, 27 71, 27 72, 27 73, 27 74, 27 75, 27 76, 27 77, 27 78, 27 79, 27 80, 27 81, 27 82, 27 83, 27 84, 27 85, 27 86, 27 87, 27 88, 27 89, 27 90, 27 91, 27 92, 27 93, 27 94, 27 95, 27 96, 27 97, 27 98, 27 99, 28 29, 28 30, 28 31, 28 32, 28 33, 28 34, 28 35, 28 36, 28 37, 28 38, 28 39, 28 40, 28 41, 28 42, 28 43, 28 44, 28 45, 28 46, 28 47, 28 48, 28 49, 28 50, 28 51, 28 52, 28 53, 28 54, 28 55, 28 56, 28 57, 28 58, 28 59, 28 60, 28 61, 28 62, 28 63, 28 64, 28 65, 28 66, 28 67, 28 68, 28 69, 28 70, 28 71, 28 72, 28 73, 28 74, 28 75, 28 76, 28 77, 28 78, 28 79, 28 80, 28 81, 28 82, 28 83, 28 84, 28 85, 28 86, 28 87, 28 88, 28 89, 28 90, 28 91, 28 92, 28 93, 28 94, 28 95, 28 96, 28 97, 28 98, 28 99, 29 30, 29 31, 29 32, 29 33, 29 34, 29 35, 29 36, 29 37, 29 38, 29 39, 29 40, 29 41, 29 42, 29 43, 29 44, 29 45, 29 46, 29 47, 29 48, 29 49, 29 50, 29 51, 29 52, 29 53, 29 54, 29 55, 29 56, 29 57, 29 58, 29 59, 29 60, 29 61, 29 62, 29 63, 29 64, 29 65, 29 66, 29 67, 29 68, 29 69, 29 70, 29 71, 29 72, 29 73, 29 74, 29 75, 29 76, 29 77, 29 78, 29 79, 29 80, 29 81, 29 82, 29 83, 29 84, 29 85, 29 86, 29 87, 29 88, 29 89, 29 90, 29 91, 29 92, 29 93, 29 94, 29 95, 29 96, 29 97, 29 98, 29 99, 30 31, 30 32, 30 33, 30 34, 30 35, 30 36, 30 37, 30 38, 30 39, 30 40, 30 41, 30 42, 30 43, 30 44, 30 45, 30 46, 30 47, 30 48, 30 49, 30 50, 30 51, 30 52, 30 53, 30 54, 30 55, 30 56, 30 57, 30 58, 30 59, 30 60, 30 61, 30 62, 30 63, 30 64, 30 65, 30 66, 30 67, 30 68, 30 69, 30 70, 30 71, 30 72, 30 73, 30 74, 30 75, 30 76, 30 77, 30 78, 30 79, 30 80, 30 81, 30 82, 30 83, 30 84, 30 85, 30 86, 30 87, 30 88, 30 89, 30 90, 30 91, 30 92, 30 93, 30 94, 30 95, 30 96, 30 97, 30 98, 30 99, 31 32, 31 33, 31 34, 31 35, 31 36, 31 37, 31 38, 31 39, 31 40, 31 41, 31 42, 31 43, 31 44, 31 45, 31 46, 31 47, 31 48, 31 49, 31 50, 31 51, 31 52, 31 53, 31 54, 31 55, 31 56, 31 57, 31 58, 31 59, 31 60, 31 61, 31 62, 31 63, 31 64, 31 65, 31 66, 31 67, 31 68, 31 69, 31 70, 31 71, 31 72, 31 73, 31 74, 31 75, 31 76, 31 77, 31 78, 31 79, 31 80, 31 81, 31 82, 31 83, 31 84, 31 85, 31 86, 31 87, 31 88, 31 89, 31 90, 31 91, 31 92, 31 93, 31 94, 31 95, 31 96, 31 97, 31 98, 31 99, 32 33, 32 34, 32 35, 32 36, 32 37, 32 38, 32 39, 32 40, 32 41, 32 42, 32 43, 32 44, 32 45, 32 46, 32 47, 32 48, 32 49, 32 50, 32 51, 32 52, 32 53, 32 54, 32 55, 32 56, 32 57, 32 58, 32 59, 32 60, 32 61, 32 62, 32 63, 32 64, 32 65, 32 66, 32 67, 32 68, 32 69, 32 70, 32 71, 32 72, 32 73, 32 74, 32 75, 32 76, 32 77, 32 78, 32 79, 32 80, 32 81, 32 82, 32 83, 32 84, 32 85, 32 86, 32 87, 32 88, 32 89, 32 90, 32 91, 32 92, 32 93, 32 94, 32 95, 32 96, 32 97, 32 98, 32 99, 33 34, 33 35, 33 36, 33 37, 33 38, 33 39, 33 40, 33 41, 33 42, 33 43, 33 44, 33 45, 33 46, 33 47, 33 48, 33 49, 33 50, 33 51, 33 52, 33 53, 33 54, 33 55, 33 56, 33 57, 33 58, 33 59, 33 60, 33 61, 33 62, 33 63, 33 64, 33 65, 33 66, 33 67, 33 68, 33 69, 33 70, 33 71, 33 72, 33 73, 33 74, 33 75, 33 76, 33 77, 33 78, 33 79, 33 80, 33 81, 33 82, 33 83, 33 84, 33 85, 33 86, 33 87, 33 88, 33 89, 33 90, 33 91, 33 92, 33 93, 33 94, 33 95, 33 96, 33 97, 33 98, 33 99, 34 35, 34 36, 34 37, 34 38, 34 39, 34 40, 34 41, 34 42, 34 43, 34 44, 34 45, 34 46, 34 47, 34 48, 34 49, 34 50, 34 51, 34 52, 34 53, 34 54, 34 55, 34 56, 34 57, 34 58, 34 59, 34 60, 34 61, 34 62, 34 63, 34 64, 34 65, 34 66, 34 67, 34 68, 34 69, 34 70, 34 71, 34 72, 34 73, 34 74, 34 75, 34 76, 34 77, 34 78, 34 79, 34 80, 34 81, 34 82, 34 83, 34 84, 34 85, 34 86, 34 87, 34 88, 34 89, 34 90, 34 91, 34 92, 34 93, 34 94, 34 95, 34 96, 34 97, 34 98, 34 99, 35 36, 35 37, 35 38, 35 39, 35 40, 35 41, 35 42, 35 43, 35 44, 35 45, 35 46, 35 47, 35 48, 35 49, 35 50, 35 51, 35 52, 35 53, 35 54, 35 55, 35 56, 35 57, 35 58, 35 59, 35 60, 35 61, 35 62, 35 63, 35 64, 35 65, 35 66, 35 67, 35 68, 35 69, 35 70, 35 71, 35 72, 35 73, 35 74, 35 75, 35 76, 35 77, 35 78, 35 79, 35 80, 35 81, 35 82, 35 83, 35 84, 35 85, 35 86, 35 87, 35 88, 35 89, 35 90, 35 91, 35 92, 35 93, 35 94, 35 95, 35 96, 35 97, 35 98, 35 99, 36 37, 36 38, 36 39, 36 40, 36 41, 36 42, 36 43, 36 44, 36 45, 36 46, 36 47, 36 48, 36 49, 36 50, 36 51, 36 52, 36 53, 36 54, 36 55, 36 56, 36 57, 36 58, 36 59, 36 60, 36 61, 36 62, 36 63, 36 64, 36 65, 36 66, 36 67, 36 68, 36 69, 36 70, 36 71, 36 72, 36 73, 36 74, 36 75, 36 76, 36 77, 36 78, 36 79, 36 80, 36 81, 36 82, 36 83, 36 84, 36 85, 36 86, 36 87, 36 88, 36 89, 36 90, 36 91, 36 92, 36 93, 36 94, 36 95, 36 96, 36 97, 36 98, 36 99, 37 38, 37 39, 37 40, 37 41, 37 42, 37 43, 37 44, 37 45, 37 46, 37 47, 37 48, 37 49, 37 50, 37 51, 37 52, 37 53, 37 54, 37 55, 37 56, 37 57, 37 58, 37 59, 37 60, 37 61, 37 62, 37 63, 37 64, 37 65, 37 66, 37 67, 37 68, 37 69, 37 70, 37 71, 37 72, 37 73, 37 74, 37 75, 37 76, 37 77, 37 78, 37 79, 37 80, 37 81, 37 82, 37 83, 37 84, 37 85, 37 86, 37 87, 37 88, 37 89, 37 90, 37 91, 37 92, 37 93, 37 94, 37 95, 37 96, 37 97, 37 98, 37 99, 38 39, 38 40, 38 41, 38 42, 38 43, 38 44, 38 45, 38 46, 38 47, 38 48, 38 49, 38 50, 38 51, 38 52, 38 53, 38 54, 38 55, 38 56, 38 57, 38 58, 38 59, 38 60, 38 61, 38 62, 38 63, 38 64, 38 65, 38 66, 38 67, 38 68, 38 69, 38 70, 38 71, 38 72, 38 73, 38 74, 38 75, 38 76, 38 77, 38 78, 38 79, 38 80, 38 81, 38 82, 38 83, 38 84, 38 85, 38 86, 38 87, 38 88, 38 89, 38 90, 38 91, 38 92, 38 93, 38 94, 38 95, 38 96, 38 97, 38 98, 38 99, 39 40, 39 41, 39 42, 39 43, 39 44, 39 45, 39 46, 39 47, 39 48, 39 49, 39 50, 39 51, 39 52, 39 53, 39 54, 39 55, 39 56, 39 57, 39 58, 39 59, 39 60, 39 61, 39 62, 39 63, 39 64, 39 65, 39 66, 39 67, 39 68, 39 69, 39 70, 39 71, 39 72, 39 73, 39 74, 39 75, 39 76, 39 77, 39 78, 39 79, 39 80, 39 81, 39 82, 39 83, 39 84, 39 85, 39 86, 39 87, 39 88, 39 89, 39 90, 39 91, 39 92, 39 93, 39 94, 39 95, 39 96, 39 97, 39 98, 39 99, 40 41, 40 42, 40 43, 40 44, 40 45, 40 46, 40 47, 40 48, 40 49, 40 50, 40 51, 40 52, 40 53, 40 54, 40 55, 40 56, 40 57, 40 58, 40 59, 40 60, 40 61, 40 62, 40 63, 40 64, 40 65, 40 66, 40 67, 40 68, 40 69, 40 70, 40 71, 40 72, 40 73, 40 74, 40 75, 40 76, 40 77, 40 78, 40 79, 40 80, 40 81, 40 82, 40 83, 40 84, 40 85, 40 86, 40 87, 40 88, 40 89, 40 90, 40 91, 40 92, 40 93, 40 94, 40 95, 40 96, 40 97, 40 98, 40 99, 41 42, 41 43, 41 44, 41 45, 41 46, 41 47, 41 48, 41 49, 41 50, 41 51, 41 52, 41 53, 41 54, 41 55, 41 56, 41 57, 41 58, 41 59, 41 60, 41 61, 41 62, 41 63, 41 64, 41 65, 41 66, 41 67, 41 68, 41 69, 41 70, 41 71, 41 72, 41 73, 41 74, 41 75, 41 76, 41 77, 41 78, 41 79, 41 80, 41 81, 41 82, 41 83, 41 84, 41 85, 41 86, 41 87, 41 88, 41 89, 41 90, 41 91, 41 92, 41 93, 41 94, 41 95, 41 96, 41 97, 41 98, 41 99, 42 43, 42 44, 42 45, 42 46, 42 47, 42 48, 42 49, 42 50, 42 51, 42 52, 42 53, 42 54, 42 55, 42 56, 42 57, 42 58, 42 59, 42 60, 42 61, 42 62, 42 63, 42 64, 42 65, 42 66, 42 67, 42 68, 42 69, 42 70, 42 71, 42 72, 42 73, 42 74, 42 75, 42 76, 42 77, 42 78, 42 79, 42 80, 42 81, 42 82, 42 83, 42 84, 42 85, 42 86, 42 87, 42 88, 42 89, 42 90, 42 91, 42 92, 42 93, 42 94, 42 95, 42 96, 42 97, 42 98, 42 99, 43 44, 43 45, 43 46, 43 47, 43 48, 43 49, 43 50, 43 51, 43 52, 43 53, 43 54, 43 55, 43 56, 43 57, 43 58, 43 59, 43 60, 43 61, 43 62, 43 63, 43 64, 43 65, 43 66, 43 67, 43 68, 43 69, 43 70, 43 71, 43 72, 43 73, 43 74, 43 75, 43 76, 43 77, 43 78, 43 79, 43 80, 43 81, 43 82, 43 83, 43 84, 43 85, 43 86, 43 87, 43 88, 43 89, 43 90, 43 91, 43 92, 43 93, 43 94, 43 95, 43 96, 43 97, 43 98, 43 99, 44 45, 44 46, 44 47, 44 48, 44 49, 44 50, 44 51, 44 52, 44 53, 44 54, 44 55, 44 56, 44 57, 44 58, 44 59, 44 60, 44 61, 44 62, 44 63, 44 64, 44 65, 44 66, 44 67, 44 68, 44 69, 44 70, 44 71, 44 72, 44 73, 44 74, 44 75, 44 76, 44 77, 44 78, 44 79, 44 80, 44 81, 44 82, 44 83, 44 84, 44 85, 44 86, 44 87, 44 88, 44 89, 44 90, 44 91, 44 92, 44 93, 44 94, 44 95, 44 96, 44 97, 44 98, 44 99, 45 46, 45 47, 45 48, 45 49, 45 50, 45 51, 45 52, 45 53, 45 54, 45 55, 45 56, 45 57, 45 58, 45 59, 45 60, 45 61, 45 62, 45 63, 45 64, 45 65, 45 66, 45 67, 45 68, 45 69, 45 70, 45 71, 45 72, 45 73, 45 74, 45 75, 45 76, 45 77, 45 78, 45 79, 45 80, 45 81, 45 82, 45 83, 45 84, 45 85, 45 86, 45 87, 45 88, 45 89, 45 90, 45 91, 45 92, 45 93, 45 94, 45 95, 45 96, 45 97, 45 98, 45 99, 46 47, 46 48, 46 49, 46 50, 46 51, 46 52, 46 53, 46 54, 46 55, 46 56, 46 57, 46 58, 46 59, 46 60, 46 61, 46 62, 46 63, 46 64, 46 65, 46 66, 46 67, 46 68, 46 69, 46 70, 46 71, 46 72, 46 73, 46 74, 46 75, 46 76, 46 77, 46 78, 46 79, 46 80, 46 81, 46 82, 46 83, 46 84, 46 85, 46 86, 46 87, 46 88, 46 89, 46 90, 46 91, 46 92, 46 93, 46 94, 46 95, 46 96, 46 97, 46 98, 46 99, 47 48, 47 49, 47 50, 47 51, 47 52, 47 53, 47 54, 47 55, 47 56, 47 57, 47 58, 47 59, 47 60, 47 61, 47 62, 47 63, 47 64, 47 65, 47 66, 47 67, 47 68, 47 69, 47 70, 47 71, 47 72, 47 73, 47 74, 47 75, 47 76, 47 77, 47 78, 47 79, 47 80, 47 81, 47 82, 47 83, 47 84, 47 85, 47 86, 47 87, 47 88, 47 89, 47 90, 47 91, 47 92, 47 93, 47 94, 47 95, 47 96, 47 97, 47 98, 47 99, 48 49, 48 50, 48 51, 48 52, 48 53, 48 54, 48 55, 48 56, 48 57, 48 58, 48 59, 48 60, 48 61, 48 62, 48 63, 48 64, 48 65, 48 66, 48 67, 48 68, 48 69, 48 70, 48 71, 48 72, 48 73, 48 74, 48 75, 48 76, 48 77, 48 78, 48 79, 48 80, 48 81, 48 82, 48 83, 48 84, 48 85, 48 86, 48 87, 48 88, 48 89, 48 90, 48 91, 48 92, 48 93, 48 94, 48 95, 48 96, 48 97, 48 98, 48 99, 49 50, 49 51, 49 52, 49 53, 49 54, 49 55, 49 56, 49 57, 49 58, 49 59, 49 60, 49 61, 49 62, 49 63, 49 64, 49 65, 49 66, 49 67, 49 68, 49 69, 49 70, 49 71, 49 72, 49 73, 49 74, 49 75, 49 76, 49 77, 49 78, 49 79, 49 80, 49 81, 49 82, 49 83, 49 84, 49 85, 49 86, 49 87, 49 88, 49 89, 49 90, 49 91, 49 92, 49 93, 49 94, 49 95, 49 96, 49 97, 49 98, 49 99, 50 51, 50 52, 50 53, 50 54, 50 55, 50 56, 50 57, 50 58, 50 59, 50 60, 50 61, 50 62, 50 63, 50 64, 50 65, 50 66, 50 67, 50 68, 50 69, 50 70, 50 71, 50 72, 50 73, 50 74, 50 75, 50 76, 50 77, 50 78, 50 79, 50 80, 50 81, 50 82, 50 83, 50 84, 50 85, 50 86, 50 87, 50 88, 50 89, 50 90, 50 91, 50 92, 50 93, 50 94, 50 95, 50 96, 50 97, 50 98, 50 99, 51 52, 51 53, 51 54, 51 55, 51 56, 51 57, 51 58, 51 59, 51 60, 51 61, 51 62, 51 63, 51 64, 51 65, 51 66, 51 67, 51 68, 51 69, 51 70, 51 71, 51 72, 51 73, 51 74, 51 75, 51 76, 51 77, 51 78, 51 79, 51 80, 51 81, 51 82, 51 83, 51 84, 51 85, 51 86, 51 87, 51 88, 51 89, 51 90, 51 91, 51 92, 51 93, 51 94, 51 95, 51 96, 51 97, 51 98, 51 99, 52 53, 52 54, 52 55, 52 56, 52 57, 52 58, 52 59, 52 60, 52 61, 52 62, 52 63, 52 64, 52 65, 52 66, 52 67, 52 68, 52 69, 52 70, 52 71, 52 72, 52 73, 52 74, 52 75, 52 76, 52 77, 52 78, 52 79, 52 80, 52 81, 52 82, 52 83, 52 84, 52 85, 52 86, 52 87, 52 88, 52 89, 52 90, 52 91, 52 92, 52 93, 52 94, 52 95, 52 96, 52 97, 52 98, 52 99, 53 54, 53 55, 53 56, 53 57, 53 58, 53 59, 53 60, 53 61, 53 62, 53 63, 53 64, 53 65, 53 66, 53 67, 53 68, 53 69, 53 70, 53 71, 53 72, 53 73, 53 74, 53 75, 53 76, 53 77, 53 78, 53 79, 53 80, 53 81, 53 82, 53 83, 53 84, 53 85, 53 86, 53 87, 53 88, 53 89, 53 90, 53 91, 53 92, 53 93, 53 94, 53 95, 53 96, 53 97, 53 98, 53 99, 54 55, 54 56, 54 57, 54 58, 54 59, 54 60, 54 61, 54 62, 54 63, 54 64, 54 65, 54 66, 54 67, 54 68, 54 69, 54 70, 54 71, 54 72, 54 73, 54 74, 54 75, 54 76, 54 77, 54 78, 54 79, 54 80, 54 81, 54 82, 54 83, 54 84, 54 85, 54 86, 54 87, 54 88, 54 89, 54 90, 54 91, 54 92, 54 93, 54 94, 54 95, 54 96, 54 97, 54 98, 54 99, 55 56, 55 57, 55 58, 55 59, 55 60, 55 61, 55 62, 55 63, 55 64, 55 65, 55 66, 55 67, 55 68, 55 69, 55 70, 55 71, 55 72, 55 73, 55 74, 55 75, 55 76, 55 77, 55 78, 55 79, 55 80, 55 81, 55 82, 55 83, 55 84, 55 85, 55 86, 55 87, 55 88, 55 89, 55 90, 55 91, 55 92, 55 93, 55 94, 55 95, 55 96, 55 97, 55 98, 55 99, 56 57, 56 58, 56 59, 56 60, 56 61, 56 62, 56 63, 56 64, 56 65, 56 66, 56 67, 56 68, 56 69, 56 70, 56 71, 56 72, 56 73, 56 74, 56 75, 56 76, 56 77, 56 78, 56 79, 56 80, 56 81, 56 82, 56 83, 56 84, 56 85, 56 86, 56 87, 56 88, 56 89, 56 90, 56 91, 56 92, 56 93, 56 94, 56 95, 56 96, 56 97, 56 98, 56 99, 57 58, 57 59, 57 60, 57 61, 57 62, 57 63, 57 64, 57 65, 57 66, 57 67, 57 68, 57 69, 57 70, 57 71, 57 72, 57 73, 57 74, 57 75, 57 76, 57 77, 57 78, 57 79, 57 80, 57 81, 57 82, 57 83, 57 84, 57 85, 57 86, 57 87, 57 88, 57 89, 57 90, 57 91, 57 92, 57 93, 57 94, 57 95, 57 96, 57 97, 57 98, 57 99, 58 59, 58 60, 58 61, 58 62, 58 63, 58 64, 58 65, 58 66, 58 67, 58 68, 58 69, 58 70, 58 71, 58 72, 58 73, 58 74, 58 75, 58 76, 58 77, 58 78, 58 79, 58 80, 58 81, 58 82, 58 83, 58 84, 58 85, 58 86, 58 87, 58 88, 58 89, 58 90, 58 91, 58 92, 58 93, 58 94, 58 95, 58 96, 58 97, 58 98, 58 99, 59 60, 59 61, 59 62, 59 63, 59 64, 59 65, 59 66, 59 67, 59 68, 59 69, 59 70, 59 71, 59 72, 59 73, 59 74, 59 75, 59 76, 59 77, 59 78, 59 79, 59 80, 59 81, 59 82, 59 83, 59 84, 59 85, 59 86, 59 87, 59 88, 59 89, 59 90, 59 91, 59 92, 59 93, 59 94, 59 95, 59 96, 59 97, 59 98, 59 99, 60 61, 60 62, 60 63, 60 64, 60 65, 60 66, 60 67, 60 68, 60 69, 60 70, 60 71, 60 72, 60 73, 60 74, 60 75, 60 76, 60 77, 60 78, 60 79, 60 80, 60 81, 60 82, 60 83, 60 84, 60 85, 60 86, 60 87, 60 88, 60 89, 60 90, 60 91, 60 92, 60 93, 60 94, 60 95, 60 96, 60 97, 60 98, 60 99, 61 62, 61 63, 61 64, 61 65, 61 66, 61 67, 61 68, 61 69, 61 70, 61 71, 61 72, 61 73, 61 74, 61 75, 61 76, 61 77, 61 78, 61 79, 61 80, 61 81, 61 82, 61 83, 61 84, 61 85, 61 86, 61 87, 61 88, 61 89, 61 90, 61 91, 61 92, 61 93, 61 94, 61 95, 61 96, 61 97, 61 98, 61 99, 62 63, 62 64, 62 65, 62 66, 62 67, 62 68, 62 69, 62 70, 62 71, 62 72, 62 73, 62 74, 62 75, 62 76, 62 77, 62 78, 62 79, 62 80, 62 81, 62 82, 62 83, 62 84, 62 85, 62 86, 62 87, 62 88, 62 89, 62 90, 62 91, 62 92, 62 93, 62 94, 62 95, 62 96, 62 97, 62 98, 62 99, 63 64, 63 65, 63 66, 63 67, 63 68, 63 69, 63 70, 63 71, 63 72, 63 73, 63 74, 63 75, 63 76, 63 77, 63 78, 63 79, 63 80, 63 81, 63 82, 63 83, 63 84, 63 85, 63 86, 63 87, 63 88, 63 89, 63 90, 63 91, 63 92, 63 93, 63 94, 63 95, 63 96, 63 97, 63 98, 63 99, 64 65, 64 66, 64 67, 64 68, 64 69, 64 70, 64 71, 64 72, 64 73, 64 74, 64 75, 64 76, 64 77, 64 78, 64 79, 64 80, 64 81, 64 82, 64 83, 64 84, 64 85, 64 86, 64 87, 64 88, 64 89, 64 90, 64 91, 64 92, 64 93, 64 94, 64 95, 64 96, 64 97, 64 98, 64 99, 65 66, 65 67, 65 68, 65 69, 65 70, 65 71, 65 72, 65 73, 65 74, 65 75, 65 76, 65 77, 65 78, 65 79, 65 80, 65 81, 65 82, 65 83, 65 84, 65 85, 65 86, 65 87, 65 88, 65 89, 65 90, 65 91, 65 92, 65 93, 65 94, 65 95, 65 96, 65 97, 65 98, 65 99, 66 67, 66 68, 66 69, 66 70, 66 71, 66 72, 66 73, 66 74, 66 75, 66 76, 66 77, 66 78, 66 79, 66 80, 66 81, 66 82, 66 83, 66 84, 66 85, 66 86, 66 87, 66 88, 66 89, 66 90, 66 91, 66 92, 66 93, 66 94, 66 95, 66 96, 66 97, 66 98, 66 99, 67 68, 67 69, 67 70, 67 71, 67 72, 67 73, 67 74, 67 75, 67 76, 67 77, 67 78, 67 79, 67 80, 67 81, 67 82, 67 83, 67 84, 67 85, 67 86, 67 87, 67 88, 67 89, 67 90, 67 91, 67 92, 67 93, 67 94, 67 95, 67 96, 67 97, 67 98, 67 99, 68 69, 68 70, 68 71, 68 72, 68 73, 68 74, 68 75, 68 76, 68 77, 68 78, 68 79, 68 80, 68 81, 68 82, 68 83, 68 84, 68 85, 68 86, 68 87, 68 88, 68 89, 68 90, 68 91, 68 92, 68 93, 68 94, 68 95, 68 96, 68 97, 68 98, 68 99, 69 70, 69 71, 69 72, 69 73, 69 74, 69 75, 69 76, 69 77, 69 78, 69 79, 69 80, 69 81, 69 82, 69 83, 69 84, 69 85, 69 86, 69 87, 69 88, 69 89, 69 90, 69 91, 69 92, 69 93, 69 94, 69 95, 69 96, 69 97, 69 98, 69 99, 70 71, 70 72, 70 73, 70 74, 70 75, 70 76, 70 77, 70 78, 70 79, 70 80, 70 81, 70 82, 70 83, 70 84, 70 85, 70 86, 70 87, 70 88, 70 89, 70 90, 70 91, 70 92, 70 93, 70 94, 70 95, 70 96, 70 97, 70 98, 70 99, 71 72, 71 73, 71 74, 71 75, 71 76, 71 77, 71 78, 71 79, 71 80, 71 81, 71 82, 71 83, 71 84, 71 85, 71 86, 71 87, 71 88, 71 89, 71 90, 71 91, 71 92, 71 93, 71 94, 71 95, 71 96, 71 97, 71 98, 71 99, 72 73, 72 74, 72 75, 72 76, 72 77, 72 78, 72 79, 72 80, 72 81, 72 82, 72 83, 72 84, 72 85, 72 86, 72 87, 72 88, 72 89, 72 90, 72 91, 72 92, 72 93, 72 94, 72 95, 72 96, 72 97, 72 98, 72 99, 73 74, 73 75, 73 76, 73 77, 73 78, 73 79, 73 80, 73 81, 73 82, 73 83, 73 84, 73 85, 73 86, 73 87, 73 88, 73 89, 73 90, 73 91, 73 92, 73 93, 73 94, 73 95, 73 96, 73 97, 73 98, 73 99, 74 75, 74 76, 74 77, 74 78, 74 79, 74 80, 74 81, 74 82, 74 83, 74 84, 74 85, 74 86, 74 87, 74 88, 74 89, 74 90, 74 91, 74 92, 74 93, 74 94, 74 95, 74 96, 74 97, 74 98, 74 99, 75 76, 75 77, 75 78, 75 79, 75 80, 75 81, 75 82, 75 83, 75 84, 75 85, 75 86, 75 87, 75 88, 75 89, 75 90, 75 91, 75 92, 75 93, 75 94, 75 95, 75 96, 75 97, 75 98, 75 99, 76 77, 76 78, 76 79, 76 80, 76 81, 76 82, 76 83, 76 84, 76 85, 76 86, 76 87, 76 88, 76 89, 76 90, 76 91, 76 92, 76 93, 76 94, 76 95, 76 96, 76 97, 76 98, 76 99, 77 78, 77 79, 77 80, 77 81, 77 82, 77 83, 77 84, 77 85, 77 86, 77 87, 77 88, 77 89, 77 90, 77 91, 77 92, 77 93, 77 94, 77 95, 77 96, 77 97, 77 98, 77 99, 78 79, 78 80, 78 81, 78 82, 78 83, 78 84, 78 85, 78 86, 78 87, 78 88, 78 89, 78 90, 78 91, 78 92, 78 93, 78 94, 78 95, 78 96, 78 97, 78 98, 78 99, 79 80, 79 81, 79 82, 79 83, 79 84, 79 85, 79 86, 79 87, 79 88, 79 89, 79 90, 79 91, 79 92, 79 93, 79 94, 79 95, 79 96, 79 97, 79 98, 79 99, 80 81, 80 82, 80 83, 80 84, 80 85, 80 86, 80 87, 80 88, 80 89, 80 90, 80 91, 80 92, 80 93, 80 94, 80 95, 80 96, 80 97, 80 98, 80 99, 81 82, 81 83, 81 84, 81 85, 81 86, 81 87, 81 88, 81 89, 81 90, 81 91, 81 92, 81 93, 81 94, 81 95, 81 96, 81 97, 81 98, 81 99, 82 83, 82 84, 82 85, 82 86, 82 87, 82 88, 82 89, 82 90, 82 91, 82 92, 82 93, 82 94, 82 95, 82 96, 82 97, 82 98, 82 99, 83 84, 83 85, 83 86, 83 87, 83 88, 83 89, 83 90, 83 91, 83 92, 83 93, 83 94, 83 95, 83 96, 83 97, 83 98, 83 99, 84 85, 84 86, 84 87, 84 88, 84 89, 84 90, 84 91, 84 92, 84 93, 84 94, 84 95, 84 96, 84 97, 84 98, 84 99, 85 86, 85 87, 85 88, 85 89, 85 90, 85 91, 85 92, 85 93, 85 94, 85 95, 85 96, 85 97, 85 98, 85 99, 86 87, 86 88, 86 89, 86 90, 86 91, 86 92, 86 93, 86 94, 86 95, 86 96, 86 97, 86 98, 86 99, 87 88, 87 89, 87 90, 87 91, 87 92, 87 93, 87 94, 87 95, 87 96, 87 97, 87 98, 87 99, 88 89, 88 90, 88 91, 88 92, 88 93, 88 94, 88 95, 88 96, 88 97, 88 98, 88 99, 89 90, 89 91, 89 92, 89 93, 89 94, 89 95, 89 96, 89 97, 89 98, 89 99, 90 91, 90 92, 90 93, 90 94, 90 95, 90 96, 90 97, 90 98, 90 99, 91 92, 91 93, 91 94, 91 95, 91 96, 91 97, 91 98, 91 99, 92 93, 92 94, 92 95, 92 96, 92 97, 92 98, 92 99, 93 94, 93 95, 93 96, 93 97, 93 98, 93 99, 94 95, 94 96, 94 97, 94 98, 94 99, 95 96, 95 97, 95 98, 95 99, 96 97, 96 98, 96 99, 97 98, 97 99, 98 99"; // Augmenter la taille du tableau pour éviter les erreurs de dépassement de mémoire
        ssize_t total_bytes_read = 0;
        ssize_t bytes_read;

        // Lire la sortie du tube par blocs jusqu'à la fin
        while ((bytes_read = read(pipe_fds[0], expected_output + total_bytes_read, sizeof(expected_output) - total_bytes_read - 1)) > 0)
        {
            total_bytes_read += bytes_read;
        }

        // Fermer l'extrémité de lecture du tube dans le processus parent
        close(pipe_fds[0]);

        // Vérifier si la lecture a réussi
        if (bytes_read >= 0)
        {
            expected_output[total_bytes_read] = '\0'; // Ajouter un caractère nul à la fin de la chaîne

            // Comparer la sortie obtenue avec la sortie attendue
            if (bytes_read == sizeof(expected_output) - 1 && memcmp(expected_output, expected_output, total_bytes_read) == 0)
                printf("Test: \033[1;32mApagnan! :)\033[0m\n");
            else
                printf("Test: \033[1;31mQUOICOUBEH :O\033[0m\n");

            // Afficher la sortie attendue et la sortie obtenue
            printf("Sortie attendue: %s\n", expected_output);
            printf("Sortie obtenue  : %.*s\n", (int)total_bytes_read, expected_output);
        }
        else
        {
            printf("Erreur lors de la lecture du tube\n");
        }
        close(pipe_fds[1]);
    }
}


