#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#include "evaluation.h"

void printInfixToPostfix(char * expression) {
  int N = strlen(expression);

  StackInitialize(N);

  for (int i = 0; i < N; i++) {
    if (expression[i] == ')') {
      printf("%c ", StackPop());
    }

    if ((expression[i] == '+') || (expression[i] == '*')) {
      StackPush(expression[i]);
    }

    if ((expression[i] >= '0') && (expression[i] <= '9')) {
      printf("%c ", expression[i]);
    }
  }
  printf("\n");
}

char * convertInfixToPostfix(char * expression) {
  int N = strlen(expression);
  char * output = (char * ) calloc(sizeof(char), N*2);
  int j = 0;

  StackInitialize(N);

  for (int i = 0; i < N; i++) {
    if (expression[i] == ')') {
      output[j++] = StackPop();
    }

    if ((expression[i] == '+') || (expression[i] == '-') || (expression[i] == '*')) {
      StackPush(expression[i]);
    }

    if ((expression[i] >= '0') && (expression[i] <= '9')) {
      output[j++] = expression[i];
    }
  }

  return output;
}

int evaluate(char * expression) {
  int N = strlen(expression);
  int i;
  char c;
  char s[2] = "x";

  StackInitialize(N);

  for (i=0; i<strlen(expression); ++i){
    s[0] = c=expression[i];

    if (isdigit(c)){
      StackPush(atoi(s));
    } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){
      int rightOperand = StackPop();
      int leftOperand = StackPop();

      switch (c) {
        case '+': 
          StackPush(leftOperand+rightOperand);
          break;
        case '-': 
          StackPush(leftOperand-rightOperand);
          break;
        case '*': 
          StackPush(leftOperand*rightOperand);
          break;
        case '/': 
          StackPush(leftOperand/rightOperand);
          break;
        case '^': 
          StackPush((int) pow(leftOperand, rightOperand));
          break;
        default: 
          break;
        }
      }
  }

  int result = StackPop();

  return result;
}