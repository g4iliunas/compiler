#include "tokenizer.h"
#include <stdlib.h>
#include <string.h>

TokenList *token_list_new()
{
    TokenList *list = (TokenList *)malloc(sizeof(TokenList));
    if (!list)
        return NULL;
    list->head = NULL;
    list->size = 0;
    return list;
}

void token_list_free(TokenList *list)
{
    /* free every token in list */
    TokenNode *node = list->head;
    while (node) {
        TokenNode *prev = node;
        node = node->next;
        free(prev);
    }
    free(list);
}

int token_list_add(TokenList *list, TokenType type, size_t value)
{
    TokenNode *new = (TokenNode *)malloc(sizeof(TokenNode));
    if (!new)
        return 1;

    new->token.type = type;
    new->token.value = value;
    new->next = NULL;

    TokenNode *node = list->head;
    if (node) {
        /* traversing to the end */
        while (node->next)
            node = node->next;
        node->next = new;
    }
    else {
        list->head = new;
    }

    list->size++;
    return 0;
}