#include <stdio.h>
#include <time.h>
#include <string.h>
#include <malloc.h>
#include "helper_windows.h"
#include "colorize.h"

typedef struct user
{
    char username[20];
    char password[20];
    char nickname[20];
    char lastname[20];
    int *age;
    int *firstscore, *firsttime, *firstlevel;
    int *secondscore, *secondtime, *secondlevel;
    int *thirdscore, *thirdtime, *thirdlevel;
} user;

typedef struct Node
{
    char *text;
    struct Node *next;
} Node;

void push(char *data);
void filleasy();
void fillnorm();
void fillhard();
void border(int x, int y);
int log_reg();

Node *head = NULL, *tale = NULL;
int flag = 0, flag2 = 0, list_size = 0, word_size, word_it = 0, l, k;

int main()
{
    FILE *fp;
    Node *temp;
    char *str;
    int level = 0, score, random_file_access, random_number, wave = 1;
    float total_time, time_limit, time_per_wave;

    head = malloc(sizeof(Node));
    tale = malloc(sizeof(Node));
    temp = calloc(1, sizeof(Node));
    temp->text = calloc(20, sizeof(char));
    str = calloc(20, sizeof(char));

    head->text = NULL;
    head->next = NULL;
    tale->text = NULL;
    tale->next = NULL;

    srand(time(NULL));
    filleasy();
    fillnorm();
    fillhard();

    while (!log_reg())
        printf("");

    system("cls");
    setcolor(3);
    border(40, 19);
    setcolor(5);
    gotoxy(10, 3);
    printf("SELECT YOUR LEVEL...");
    gotoxy(17, 6);
    printf("1)Easy");
    gotoxy(16, 8);
    printf("1)Medium");
    gotoxy(17, 10);
    printf("1)Hard");
    setcolor(6);
    gotoxy(5, 15);
    printf("SELECTED LEVEL : ");
    scanf("%d", &level);

    switch (level)
    {
    case 1:
        time_limit = 10;
        time_per_wave = 0.2;
        break;

    case 2:
        time_limit = 8;
        time_per_wave = 0.3;
        break;

    case 3:
        time_limit = 5;
        time_per_wave = 0.2;
        break;
    }

    system("cls");
    border(40, 22);
    // HANDLE thread_id = start_listening(my_callback_on_key_arrival);

    for (int i = 0; i < 10; i++)
    {
        fp = fopen("words_easy.txt", "r");

        random_file_access = rand() % 50;
        for (int j = 0; j <= random_file_access; j++)
        {
            fscanf(fp, " %s", str);
        }

        push(str);
        fclose(fp);
    }

    while (word_it <= 10 && time_limit >= 1)
    {

        for (int counter = 0; counter < word_it; counter++)
        {

            if (flag == 1)
            {
                flag = 2;
                temp = head;
            }
            else
            {
                temp = temp->next;
            }
            gotoxy(20 - (strlen(temp->text) / 2), 2 * (word_it - counter));
            printf("%s\n", temp->text);
        }

        Sleep(100 * time_limit);
        system("cls");
        border(40, 22);
        word_it++;
        list_size++;

        // list_size نباید هیچ جا منها بشه که بدونیم در مجموع چند تا کلمه اومده پایین
        // list_size ---------> count of printed words
        if (list_size % 10 == 0)
        {
            wave++;
            random_number = rand() % 3;
            for (int i = 0; i < 10; i++)
            {

                random_number = rand() % wave % 3;
                switch (random_number)
                {
                case 0:
                    fp = fopen("words_easy.txt", "r");
                    break;

                case 1:
                    fp = fopen("words_norm.txt", "r");
                    break;

                case 2:
                    fp = fopen("words_hard.txt", "r");
                    break;
                }
                random_file_access = rand() % 50;
                for (int j = 0; j <= random_file_access; j++)
                {
                    fscanf(fp, " %s", str);
                }

                push(str);
            }
            time_limit = time_limit * (1 - time_per_wave);
        }
        flag = 1;
    }

    // HANDLE thread_id = start_listening(my_callback_on_key_arrival);

    // WaitForSingleObject(thread_id, INFINITE);
    system("cls");
    return 0;
}

void push(char *data)
{
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    temp->text = (char *)calloc(20, sizeof(char));
    temp->next = NULL;
    strcpy(temp->text, data);

    if (flag == 0)
    {
        head = temp;
        flag = 1;
    }
    else
    {
        tale->next = temp;
    }
    tale = temp;
    return;
}

void filleasy()
{
    FILE *fp;
    int word_size, rand_num, i = 0;
    char *word;
    fp = fopen("words_easy.txt", "w");

    for (int count = 0; count < 50; count++)
    {
        word_size = rand() % 10;
        while (!word_size)
            word_size = rand() % 10;
        word = calloc(1, (word_size * sizeof(char)) + 1);
        for (i = 0; i < word_size; i++)
        {
            rand_num = rand();

            // choose number or letter to create

            if (rand_num % 3 == 0)
            {
                // random number
                word[i] = (rand_num % 10) + 48;
            }
            else if (rand_num % 3 == 1)
            {
                // random small letter
                word[i] = (rand_num % 26) + 97;
            }
            else
            {
                // random large letter
                word[i] = (rand_num % 26) + 65;
            }
        }
        fprintf(fp, "%s\n", word);
    }
    fclose(fp);
}

void fillnorm()
{
    FILE *fp;
    int word_size, rand_num, i = 0;
    char *word;
    fp = fopen("words_norm.txt", "w");

    for (int count = 0; count < 50; count++)
    {
        word_size = rand() % 20;
        while (!word_size)
            word_size = rand() % 20;
        word = calloc(1, (word_size * sizeof(char)) + 1);
        for (i = 0; i < word_size; i++)
        {
            rand_num = rand();

            // choose number or letter to create

            if (rand_num % 3 == 0)
            {
                // random number
                word[i] = (rand_num % 10) + 48;
            }
            else if (rand_num % 3 == 1)
            {
                // random small letter
                word[i] = (rand_num % 26) + 97;
            }
            else
            {
                // random large letter
                word[i] = (rand_num % 26) + 65;
            }
        }
        fprintf(fp, "%s\n", word);
    }
    fclose(fp);
}
void fillhard()
{
    FILE *fp;
    int word_size, rand_num, i = 0, char_selector;
    char *word, chars[7] = {'!', '&', '^', '%', '$', '@', '_'};
    fp = fopen("words_hard.txt", "w");

    for (int count = 0; count < 50; count++)
    {
        word_size = rand() % 20;
        while (!word_size)
            word_size = rand() % 20;
        word = calloc(1, (word_size * sizeof(char)) + 1);
        for (i = 0; i < word_size; i++)
        {
            rand_num = rand();

            // choose number or letter to create

            if (rand_num % 4 == 0)
            {
                // random number
                word[i] = (rand_num % 10) + 48;
            }
            else if (rand_num % 4 == 1)
            {
                // random small letter
                word[i] = (rand_num % 26) + 97;
            }
            else if (rand_num % 4 == 2)
            {
                // random large letter
                word[i] = (rand_num % 26) + 65;
            }
            else
            {
                // random hard charracters
                char_selector = rand() % 7;
                word[i] = chars[char_selector];
            }
        }
        fprintf(fp, "%s\n", word);
    }
    fclose(fp);
}

void border(int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            gotoxy(i, j);
            if (i == 0 || j == 0 || x - i == 1 || y - j == 1)
                printf("*");
        }
    }
}

int log_reg()
{
    FILE *fp;
    user *input_user, *temp;
    int choose, wrong_password = 0, flag = 0;
    input_user = calloc(1, sizeof(user));
    temp = calloc(1, sizeof(user));

    setcolor(3);
    border(32, 15);
    setcolor(8);
    gotoxy(5, 2);
    setcolor(2);
    printf("Login/SignIn Please...");
    gotoxy(5, 5);
    printf("1. login\n");
    gotoxy(5, 7);
    printf("2. register\n");
    setcolor(8);
    gotoxy(5, 10);
    scanf("%d", &choose);
    system("cls");
    setcolor(3);
    border(50, 15);
    setcolor(8);
    if (choose == 1)
    {
        fp = fopen("users.txt", "r");

        gotoxy(5, 5);
        printf("enter your username : ");
        scanf(" %s", temp->username);

        while (flag != 1)
        {
            if (flag == 2)
            {
                system("cls");
                setcolor(3);
                border(50, 15);
                setcolor(8);
                gotoxy(5, 5);
                printf("enter your username : ");
                gotoxy(5, 2);
                setcolor(12);
                printf("there is no user with this username!");
                gotoxy(5, 3);
                printf("Please Check your username and try again...");
                setcolor(8);
                gotoxy(27, 5);
                scanf(" %s", temp->username);
                fseek(fp, 0, SEEK_SET);
            }

            while (fread(input_user, sizeof(user) + sizeof(char), 1, fp))
            {
                if (!strcmp(input_user->username, temp->username))
                {
                    flag = 1;
                    break;
                }
            }

            if (flag == 1)
            {
                gotoxy(5, 7);
                printf("enter your password : ");
                continue;
            }

            flag = 2;
        }

        scanf(" %s", temp->password);

        while (strcmp(temp->password, input_user->password))
        {
            system("cls");
            gotoxy(5, 5);
            printf("enter your username : %s", temp->username);
            setcolor(3);
            border(50, 15);
            setcolor(8);
            gotoxy(5, 2);
            setcolor(12);
            printf("password doesen't match.");
            gotoxy(5, 3);
            printf("please try again!");
            setcolor(8);
            gotoxy(5, 7);
            printf("enter your password : ");

            wrong_password++;
            scanf(" %s", temp->password);
            if (wrong_password > 9)
            {
                setcolor(12);
                printf("you tried many times. please try again\n");
                setcolor(8);
                Sleep(4000);
                system("cls");
                return 0;
            }
        }

        gotoxy(5, 11);
        setcolor(2);
        printf("welcome %s!", input_user->nickname);
        setcolor(8);
        Sleep(2000);
        fclose(fp);
        return 1;
    }

    else if (choose == 2)
    {
        fp = fopen("users.txt", "r");

        gotoxy(5, 5);
        printf("choose a username : ");
        scanf(" %s", temp->username);

        while (fread(input_user, sizeof(user) + sizeof(char), 1, fp))
            if (!strcmp(input_user->username, temp->username))
            {
                system("cls");
                setcolor(3);
                border(50, 15);
                setcolor(8);
                gotoxy(5, 2);
                setcolor(12);
                printf("this username has already been taken!");
                gotoxy(5, 3);
                printf("try another one!");
                setcolor(8);
                gotoxy(5, 5);
                printf("choose a username : ");
                fseek(fp, 0, SEEK_SET);
                scanf(" %s", temp->username);
            }
        system("cls");
        setcolor(3);
        border(55, 19);
        setcolor(8);
        gotoxy(5, 5);
        printf("choose a username : %s", temp->username);

        gotoxy(5, 7);
        printf("choose a password : ");
        scanf(" %s", temp->password);

        gotoxy(5, 9);
        printf("what's your first name : ");
        scanf(" %s", temp->nickname);

        gotoxy(5, 11);
        printf("and you last name : ");
        scanf(" %s", temp->lastname);

        gotoxy(5, 13);
        printf("How old are you : ");
        scanf(" %s", &temp->age);

        temp->firstscore = '0';
        temp->firstlevel = '0';
        temp->firsttime = '0';
        temp->secondscore = '0';
        temp->secondlevel = '0';
        temp->secondtime = '0';
        temp->thirdscore = '0';
        temp->thirdlevel = '0';
        temp->thirdtime = '0';

        gotoxy(23, 2);
        setcolor(2);
        printf("WELCOME!");
        setcolor(8);
        gotoxy(5, 16);
        printf("Ok done.Now you can login to your account! ");
        Sleep(4000);
        fclose(fp);

        fp = fopen("users.txt", "a");

        fwrite(temp, sizeof(user), 1, fp);
        fputc('\n', fp);
        fclose(fp);
        system("cls");
        return 0;
    }

    else
    {
        gotoxy(5, 5);
        printf("Somthing happend. please try again.");
        Sleep("5000");
        system("cls");
        system("cls");
        return 0;
    }
}

void my_callback_on_key_arrival(char c)
{
    if (flag2 == 0)
    {
        word_size = strlen(head->text);
        word_it = 0;
        flag2 = 1;
    }
    if (c == head->text[word_it])
    {
    }
    else
    {
    }
    word_it++;
    if (word_size == word_it)
    {
        head = head->next;
        flag2 = 0;
    }
}
