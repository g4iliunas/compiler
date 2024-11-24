#include "tokenizer.h"
#include <stdio.h>

int main(void)
{
    const uint8_t machine_code[] = "\x31\xC0\xC3\xB8\x05\x00\x00\x00\xC3";
    TokenList *tokens = tokenize(machine_code, sizeof(machine_code) - 1);
    printf("tokens: %ld\n", tokens->size);

    TokenNode *node = tokens->head;
    while (node) {
        Token *token = &node->token;
        if (token->type == TOKEN_OPCODE) {
            printf("opcode: 0x%lx\n", token->value);
        }
        else if (token->type == TOKEN_REGISTER) {
            printf("register: 0x%lx\n", token->value);
        }
        else if (token->type == TOKEN_IMMEDIATE) {
            printf("immediate value: %ld\n", token->value);
        }
        else if (token->type == TOKEN_UNKNOWN) {
            printf("unknown value: %ld\n", token->value);
        }
        node = node->next;
    }

    token_list_free(tokens);

    return 0;
}