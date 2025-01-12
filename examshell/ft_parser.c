#include "examshell.h"

#include <stdlib.h>
#include <stdio.h>

void handle_quote(char c, int *squote, int *dquote)
{
    if (c == '\'' && !(*dquote)) // Si on rencontre un simple quote hors d'un double quote
        *squote = !(*squote);    // Alterne l'état du simple quote
    if (c == '"' && !(*squote))
        *dquote = !(*dquote);
}

int word_len(char *str)
{
    int i = 0;
    int squote = 0;
    int dquote = 0;

    while (str[i] != '\0' && (str[i] != ' ' || squote || dquote))
    {
        handle_quote(str[i], &squote, &dquote);
        i++;
    }
    return i;
}

int word_count(char *str)
{
    int i = 0;
    int count = 0;
    int squote = 0;
    int dquote = 0;

    while (str[i] != '\0')
    {
        if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
        {
            count++;
            while (str[i] != '\0' && (str[i] != ' ' || squote || dquote))
            {
                handle_quote(str[i], &squote, &dquote);
                i++;
            }
        }
        else
            i++;
    }
    return count;
}

char *split_word(char *str, int index)
{
    int i = 0;
    char *temp;
    int in_single_quote;
    int in_double_quote;

    i = 0;
    in_single_quote = 0;
    in_double_quote = 0;
    temp = (char *)malloc(sizeof(char) * (word_len(&str[index]) + 1));
    if (!temp)
        return (NULL);
    while (str[index] != '\0' && (str[index] != ' '
        || in_single_quote || in_double_quote))
    {
        handle_quote(str[index], &in_single_quote, &in_double_quote);
        temp[i++] = str[index++];
    }
    temp[i] = '\0';
    return (temp);
}


char **parse_command(char const *input)
{
    int i;
    int j;
    char **split;

    if (!input)
        return (NULL);
    i = 0;
    j = 0;
    split = (char **)malloc(sizeof(char *) * (word_count((char *)input) + 2));
    if (!split)
        return (NULL);
    while (input[i] != '\0')
    {
        if (input[i] != ' ')
        {
            split[j++] = split_word((char *)input, i);
            i += word_len((char *)input + i);
        }
        else
            i++;
    }
    split[j] = NULL;
    return (split);
}