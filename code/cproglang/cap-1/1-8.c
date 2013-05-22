#include <stdio.h>

main() {
  int c;
  int tabs = 0;
  int newLines = 0;
  int spaces = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      ++newLines;
    } else if (c == '\t') {
      ++tabs;
    } else if (c == ' ') {
      ++spaces;
    }
  }
  printf("new lines: %d\ntabs: %d\nspaces: %d\n", newLines, tabs, spaces);
}
