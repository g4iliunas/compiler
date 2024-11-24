#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <stddef.h>
#include <stdint.h>

/*
mov eax, 5 = TOKEN_OPCODE(mov), TOKEN_REGISTER(eax), TOKEN_IMMEDIATE(5)
*/

typedef enum {
    TOKEN_OPCODE,
    TOKEN_REGISTER,
    TOKEN_IMMEDIATE,
    TOKEN_UNKNOWN
} TokenType;

typedef struct {
    TokenType type;
    size_t value;
} Token;

typedef struct token_node {
    Token token;
    struct token_node *next;
} TokenNode;

typedef struct {
    TokenNode *head;
    size_t size;
} TokenNodeList;

TokenNodeList *token_list_new();
void token_list_free(TokenNodeList *list);
int token_list_add(TokenNodeList *list, TokenType type, size_t value);

#endif