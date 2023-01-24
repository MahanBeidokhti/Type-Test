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
    int firstscore, *firstday, *firstmonth, *firstyear, *firstlevel;
    int secondscore, *secondday, *secondmonth, *secondyear, *secondlevel;
    int thirdscore, *thirdday, *thirdmonth, *thirdyear, *thirdlevel;
} user;

// text -> value of each Node
// colors -> flag of each letter for its color
// star -> flag of each word to check if should print as a word or stars
// wrong -> flag of each word to check if a word typed correctly or not
typedef struct Node
{
<<<<<<< Updated upstream
    char text[20];
    struct Node *next;
} Node;

=======
    char *text;
    int *colors;
    int star;
    int wrong;
    int score;
    struct Node *next;
} Node;

void my_callback_on_key_arrival(char c);
void push(char *data);
>>>>>>> Stashed changes
void filleasy();
void fillnorm();
void fillhard();
void border(int x, int y);
int log_reg();

<<<<<<< Updated upstream
=======
Node *head = NULL, *tale = NULL;
user *input_user;
// user_count -> to show the line that the logged in user is in there
// flag2 -> checking first char of any word in my_callback... func
// list_sizee -> count of every words added to linked list
// word_it -> count of words, showing in the display
// star_random -> random word selector to hide a word by putting star on it.
// conter -> iterator for printing characters of every word
int user_count = 0, flag = 0, flag2 = 0, score = 0, list_size = 0, word_size, word_it = 1, letter, star_random, counter = 0, word_level = 1, runtime;
char *username;

>>>>>>> Stashed changes
int main()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    FILE *fp;
<<<<<<< Updated upstream
    Node *word, **words;
    int level = 0, score, random_file_access, random_number;
=======
    Node *temp;
    user *temperory;
    char *str;
    int level = 0, random_file_access, random_number, wave = 1;
>>>>>>> Stashed changes
    float total_time, time_limit, time_per_wave;
    word = calloc(1, sizeof(Node));
    words = calloc(1, sizeof(Node *));

    srand(time(NULL));
    filleasy();
    fillnorm();
    fillhard();

    while (!log_reg())
        printf("");

    system("cls");
    setcolor(3);
    border(40, 29);
    gotoxy(13, 2);
    setcolor(1);
    printf("Score Board: ");
    setcolor(20);
    gotoxy(12, 4);
    setcolor(7);
    printf("scr|lvl| date");
    gotoxy(10, 6);
    if (input_user->firstlevel == 0)
        printf("1. %d | %d | %d:%d:%d", input_user->firstscore, input_user->firstlevel, input_user->firstday, input_user->firstmonth, input_user->firstyear);
    else
        printf("1. %d | %d | %d:%d:%d", input_user->firstscore, input_user->firstlevel, input_user->firstday, input_user->firstmonth + 1, input_user->firstyear - 25);

    gotoxy(10, 8);
    if (input_user->secondlevel == 0)
        printf("2. %d | %d | %d:%d:%d", input_user->secondscore, input_user->secondlevel, input_user->secondday, input_user->secondmonth, input_user->secondyear);
    else
        printf("2. %d | %d | %d:%d:%d", input_user->secondscore, input_user->secondlevel, input_user->secondday, input_user->secondmonth + 1, input_user->secondyear - 25);
    gotoxy(10, 10);
    if (input_user->thirdlevel == 0)
        printf("3. %d | %d | %d:%d:%d", input_user->thirdscore, input_user->thirdlevel, input_user->thirdday, input_user->thirdmonth, input_user->thirdyear);
    else
        printf("3. %d | %d | %d:%d:%d", input_user->thirdscore, input_user->thirdlevel, input_user->thirdday, input_user->thirdmonth + 1, input_user->thirdyear - 25);
    setcolor(5);
    gotoxy(10, 13);
    printf("SELECT YOUR LEVEL...");
    gotoxy(17, 16);
    printf("1)Easy");
    gotoxy(16, 18);
    printf("2)Medium");
    gotoxy(17, 20);
    printf("3)Hard");
    setcolor(6);
    gotoxy(5, 25);
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

<<<<<<< Updated upstream
    fp = fopen("words_easy.txt", "r");
=======
    system("cls");
    border(40, 22);
    setcolor(14);
    HANDLE thread_id = start_listening(my_callback_on_key_arrival);

    for (int i = 0; i < 10; i++)
    {
        fp = fopen("words_easy.txt", "r");

        random_file_access = rand() % 50;
        for (int j = 0; j <= random_file_access; j++)
        {
            fscanf(fp, " %s", str);
        }
>>>>>>> Stashed changes

    for (int wave = 0; time >= 1; wave++)
    {
<<<<<<< Updated upstream
        random_number = rand() % 3;
        for (int i = 0; i < 10; i++)
=======

        for (counter = 0; counter < word_it; counter++)
>>>>>>> Stashed changes
        {
            random_file_access = rand() % 10;

            for (int j = 0; j <= random_file_access; j++)
            {
                fscanf(fp, "%s\n", &word->text);
            }
<<<<<<< Updated upstream

            fseek(fp, 0, SEEK_SET);
            Sleep(1000);
        }
=======
            if (temp == head || temp->star == 0)
            {
                gotoxy(20 - (strlen(temp->text) / 2), 2 * (word_it - counter));
                for (int k = 0; k < strlen(temp->text); k++)
                {
                    switch (temp->colors[k])
                    {
                    case 0:
                        setcolor(14);
                        break;

                    case 1:
                        setcolor(2);
                        break;

                    case 2:
                        setcolor(12);
                        break;
                    }
                    printf("%c", temp->text[k]);
                    setcolor(14);
                }
                printf("\n");
            }
            else
            {
                gotoxy(1, 2 * (word_it - counter));
                for (int k = 0; k < 38; k++)
                {
                    printf("*");
                }
            }
        }

        Sleep(100 * time_limit);
        system("cls");
        setcolor(6);
        border(40, 22);
        setcolor(14);
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
                    word_level = 1;
                    break;

                case 1:
                    fp = fopen("words_norm.txt", "r");
                    word_level = 2;
                    break;

                case 2:
                    fp = fopen("words_hard.txt", "r");
                    word_level = 3;
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
        runtime += time_limit;
        flag = 1;
>>>>>>> Stashed changes
    }
    runtime /= 10;
    system("cls");
    border(40, 10);
    if (word_it > 10)
    {
        gotoxy(14, 3);
        printf("GAME OVER!");
        gotoxy(4, 7);
        printf("your words, reached to maximum!");
        Sleep(3000);
    }
    else
    {
        gotoxy(11, 3);
        printf("Congratulations!");
        gotoxy(13, 7);
        printf("you made it!");
        Sleep(3000);
    }
    system("cls");
    border(40, 10);
    gotoxy(13, 4);
    printf("your score : %d", score);
    gotoxy(9, 7);
    printf("your survive time : %d", runtime);
    Sleep(2000);

    input_user->thirdlevel = input_user->secondlevel;
    input_user->thirdscore = input_user->secondscore;
    input_user->thirdday = input_user->secondday;
    input_user->thirdmonth = input_user->secondmonth;
    input_user->thirdyear = input_user->secondyear;
    input_user->secondlevel = input_user->firstlevel;
    input_user->secondscore = input_user->firstscore;
    input_user->secondday = input_user->firstday;
    input_user->secondmonth = input_user->firstmonth;
    input_user->secondyear = input_user->firstyear;
    input_user->firstlevel = level;
    input_user->firstscore = score;
    input_user->firstday = tm.tm_mday;
    input_user->firstmonth = tm.tm_mon;
    input_user->firstyear = tm.tm_year;

    fp = fopen("users.txt", "r+");
    for (int file_it = 1; file_it < user_count; file_it++)
    {
        fread(temperory, sizeof(user), 1, fp);
    }

    fwrite(input_user, sizeof(user), 1, fp);
    fclose(fp);
    system("cls");

    return 0;
    WaitForSingleObject(thread_id, INFINITE);
}

<<<<<<< Updated upstream
=======
void push(char *data)
{
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    temp->text = (char *)calloc(20, sizeof(char));
    temp->colors = (int *)calloc(20, sizeof(int));
    temp->next = NULL;
    temp->star = 0;
    strcpy(temp->text, data);

    // پنج درصد احتمال اینکه کلمه مخدوش نمایش داده شود
    star_random = rand() % 20;

    if (flag == 0)
    {
        head = temp;
        flag = 1;
    }

    else
    {
        tale->next = temp;
    }

    switch (word_level)
    {
    case 1:
        temp->score = 1;
        break;
    case 2:
        temp->score = 2;
        break;
    case 3:
        temp->score = 3;
        break;
    }

    if (star_random == 0)
    {
        temp->star = 1;
        temp->score++;
    }

    tale = temp;
    return;
}

>>>>>>> Stashed changes
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
                printf("$");
        }
    }
}

int log_reg()
{
    FILE *fp;
    user *temp;
    int choose, wrong_password = 0, flag = 0;
    input_user = calloc(1, sizeof(user));
    temp = calloc(1, sizeof(user));

    setcolor(3);
    border(32, 15);
    setcolor(14);
    gotoxy(5, 2);
    setcolor(2);
    printf("Login/SignIn Please...");
    gotoxy(5, 5);
    printf("1. login\n");
    gotoxy(5, 7);
    printf("2. register\n");
    setcolor(14);
    gotoxy(5, 10);
    scanf("%d", &choose);
    system("cls");
    setcolor(3);
    border(50, 15);
    setcolor(14);
    if (choose == 1)
    {
        fp = fopen("users.txt", "r");
        fseek(fp, 0, SEEK_SET);
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
                setcolor(14);
                gotoxy(5, 5);
                printf("enter your username : ");
                gotoxy(5, 2);
                setcolor(12);
                printf("there is no user with this username!");
                gotoxy(5, 3);
                printf("Please Check your username and try again...");
                setcolor(14);
                gotoxy(27, 5);
                scanf(" %s", temp->username);
                fseek(fp, 0, SEEK_SET);
            }

            while (fread(input_user, sizeof(user) + sizeof(char), 1, fp))
            {
                user_count++;
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
            setcolor(14);
            gotoxy(5, 2);
            setcolor(12);
            printf("password doesen't match.");
            gotoxy(5, 3);
            printf("please try again!");
            setcolor(14);
            gotoxy(5, 7);
            printf("enter your password : ");

            wrong_password++;
            scanf(" %s", temp->password);
            if (wrong_password > 9)
            {
                setcolor(12);
                printf("you tried many times. please try again\n");
                setcolor(14);
                Sleep(4000);
                system("cls");
                return 0;
            }
        }

        gotoxy(5, 11);
        setcolor(2);
        printf("welcome %s!", input_user->nickname);
        username = calloc(20, sizeof(char));
        strcpy(username, input_user->username);
        setcolor(14);
        fclose(fp);
        Sleep(2000);
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
                setcolor(14);
                gotoxy(5, 2);
                setcolor(12);
                printf("this username has already been taken!");
                gotoxy(5, 3);
                printf("try another one!");
                setcolor(14);
                gotoxy(5, 5);
                printf("choose a username : ");
                fseek(fp, 0, SEEK_SET);
                scanf(" %s", temp->username);
            }
        system("cls");
        setcolor(3);
        border(55, 19);
        setcolor(14);
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

        temp->firstscore = 0;
        temp->firstlevel = 0;
        temp->firstday = 0;
        temp->firstmonth = 0;
        temp->firstyear = 0;
        temp->secondscore = 0;
        temp->secondlevel = 0;
        temp->secondday = 0;
        temp->secondmonth = 0;
        temp->secondyear = 0;
        temp->thirdscore = 0;
        temp->thirdlevel = 0;
        temp->thirdday = 0;
        temp->thirdmonth = 0;
        temp->thirdyear = 0;

        gotoxy(23, 2);
        setcolor(2);
        printf("WELCOME!");
        setcolor(14);
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
<<<<<<< Updated upstream
=======

void my_callback_on_key_arrival(char c)
{
    if (flag2 == 0)
    {
        word_size = strlen(head->text);
        head->wrong = 0;
        letter = 0;
        flag2 = 1;
    }

    gotoxy(20 - (strlen(head->text) / 2) + letter, 2 * word_it);

    if (c == head->text[letter])
    {
        setcolor(2);
        printf("%c", head->text[letter]);
        head->colors[letter] = 1;
        setcolor(14);
        score += 0;
        letter++;
    }
    else if (c != 8)
    {
        setcolor(12);
        printf("%c", head->text[letter]);
        head->colors[letter] = 2;
        setcolor(14);
        head->wrong = 1;
        letter++;
    }
    else
    {
        gotoxy(20 - (strlen(head->text) / 2) + letter - 1, 2 * word_it);
        setcolor(14);
        printf("%c", head->text[letter - 1]);
        head->colors[letter - 1] = 0;
        if (head->wrong == 1)
            head->wrong = 0;
        gotoxy(20 - (strlen(head->text) / 2) + letter - 1, 2 * word_it);
        letter--;
    }
    if (word_size == letter)
    {
        gotoxy(20 - (strlen(head->text) / 2), 2 * (word_it));
        for (int it = 0; it < strlen(head->text); it++)
        {
            printf(" ");
        }
        if (head->wrong != 0)
        {
            score += head->score;
            if (head->star != 0 && score != 0)
                score++;
        }
        head = head->next;
        word_it--;
        flag2 = 0;
    }
}
>>>>>>> Stashed changes
