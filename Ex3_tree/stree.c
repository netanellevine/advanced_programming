#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <limits.h>
#include <unistd.h>

#define COLOR_BLUE "\x1b[34m" // Macro for blue color
#define COLOR_RESET "\x1b[0m" // Macro to reset color

// Global variables to hold the counts of directories and files
int dirCount = -1;
int fileCount = 0;

// Function to print permissions of a file or directory
void printFilePerms(mode_t mode)
{
    printf((S_ISDIR(mode)) ? "d" : "-");
    printf((mode & S_IRUSR) ? "r" : "-");
    printf((mode & S_IWUSR) ? "w" : "-");
    printf((mode & S_IXUSR) ? "x" : "-");
    printf((mode & S_IRGRP) ? "r" : "-");
    printf((mode & S_IWGRP) ? "w" : "-");
    printf((mode & S_IXGRP) ? "x" : "-");
    printf((mode & S_IROTH) ? "r" : "-");
    printf((mode & S_IWOTH) ? "w" : "-");
    printf((mode & S_IXOTH) ? "x" : "-");
}

// Function to print owner of a file or directory
void printFileOwner(uid_t uid)
{
    printf("%s", getpwuid(uid)->pw_name);
}

// Function to print group owner of a file or directory
void printFileGroup(gid_t gid)
{
    printf("%s", getgrgid(gid)->gr_name);
}

// Function to print size of a file or directory
void printFileSize(off_t size)
{
    printf("%ld", (long)size);
}

// Function to count size of a directory
int countDirectorySize(const char *path)
{
    DIR *dir = opendir(path);
    if (dir == NULL)
    {
        perror("opendir");
        exit(EXIT_FAILURE);
    }
    struct dirent *entry;
    int num_entries = 0;
    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_name[0] == '.')
            continue;
        num_entries++;
    }
    closedir(dir);
    return num_entries;
}

// Recursive function to print a directory tree
void printTreeRecursive(const char *path, const char *prefix, const char *name, int is_last)
{
    struct stat st;
    if (lstat(path, &st) != 0)
    {
        perror("lstat");
        exit(EXIT_FAILURE);
    }

    S_ISDIR(st.st_mode) ? dirCount++ : fileCount++;

    printf("%s", prefix);
    printf(is_last ? "└── " : "├── ");

    printf("[");
    printFilePerms(st.st_mode);
    printf("  ");
    printFileOwner(st.st_uid);
    printf("  ");
    printFileGroup(st.st_gid);
    printf("  ");
    printFileSize(st.st_size);
    printf("]");

    // If it's a directory, print it in blue
    if (S_ISDIR(st.st_mode))
    {
        printf(COLOR_BLUE "  %s\n" COLOR_RESET, name);
    }
    else
    {
        printf("  %s\n", name);
    }

    if (S_ISDIR(st.st_mode))
    {
        DIR *dir = opendir(path);
        if (dir == NULL)
        {
            perror("opendir");
            return;
        }

        struct dirent **namelist;
        int n;

        n = scandir(path, &namelist, NULL, alphasort);
        if (n < 0)
        {
            perror("scandir");
            return;
        }

        int i;
        for (i = 0; i < n; i++)
        {
            char *entry_name = namelist[i]->d_name;
            if (entry_name[0] == '.')
            {
                free(namelist[i]);
                continue;
            }

            char *new_path = malloc(PATH_MAX);
            snprintf(new_path, PATH_MAX, "%s/%s", path, entry_name);

            char *new_prefix = malloc(strlen(prefix) + 5);
            sprintf(new_prefix, "%s%s", prefix, is_last ? "    " : "│   ");

            printTreeRecursive(new_path, new_prefix, entry_name, i == n - 1);

            free(new_path);
            free(namelist[i]);
            free(new_prefix);
        }
        free(namelist);
        closedir(dir);
    }
}

void usage(char *program_name)
{
    fprintf(stderr, "Usage: %s <directory>\n", program_name);
    fprintf(stderr, "Or: %s (to use the current directory as the default)\n", program_name);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    const char *path;

    if (argc == 1)
    {
        path = "."; // Use the current directory if no arguments are provided
    }

    else if (argc == 2)
    {
        path = argv[1];
        if (access(path, F_OK) == -1)
        {
            perror("Error");
            return EXIT_FAILURE;
        }
    }

    else
    {
        usage(argv[0]);
    }

    printTreeRecursive(path, "", path, 1);

    printf("\n %d directories, %d files\n", dirCount, fileCount);

    return 0;
}
