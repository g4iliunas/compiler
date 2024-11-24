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

TokenList *tokenize(const uint8_t *data, size_t len)
{
    TokenList *list = token_list_new();
    if (!list)
        return NULL;

    for (size_t i = 0; i < len; i++) {
        switch (data[i]) {
        case 0x66: {
            // tokenize 16bit instructions
            switch ((data[++i])) {
            }
            break;
        }
        case 0x31: {
            // xor /r
            token_list_add(list, TOKEN_OPCODE, data[i++]);
            token_list_add(list, TOKEN_REGISTER, data[i]);
            break;
        }
        case 0xc3 ... 0xcb: {
            // ret
            token_list_add(list, TOKEN_OPCODE, data[i]);
            break;
        }

        // todo: add more mov opcodes
        case 0x89: {
            // mov /r (moves to eax)
            token_list_add(list, TOKEN_OPCODE, data[i++]);
            token_list_add(list, TOKEN_REGISTER, data[i]);
            break;
        }
        case 0xb8: {
            // mov rd id (moves to eax)
            token_list_add(list, TOKEN_OPCODE, data[i++]);
            token_list_add(list, TOKEN_IMMEDIATE, *(uint32_t *)&data[i]);
            i += 3; // need to -1
            break;
        }
        default: {
            token_list_add(list, TOKEN_UNKNOWN, 0);
            break;
        }
        }
    }

    return list;
}