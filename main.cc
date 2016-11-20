#include <iostream>
#include <string>
#include "grid.h"
#include "window.h"
using namespace std;

int main() {
  cin.exceptions(ios::eofbit|ios::failbit);
  string cmd, aux;
  Xwindow w;
  Grid g{w};
  int moves = 0;

  try {
    while (true) {
      cin >> cmd;
      if (cmd == "new") {
          int n;
          cin >> n;
          g.init(n);
      }
      else if (cmd == "init") {
          int r,c;
          while (true) {
              cin >> r >> c;
              if (r == -1 || c == -1) {
                  break;
              }
              g.init(r, c);
          }
          cout << g;
      }
      else if (cmd == "game") {
          cin >> moves;
          if (moves != 1) {
              cout << moves << " moves left" << endl;
          } else {
              cout << moves << " move left" << endl;
          }
          if (moves == 0) {
              if (g.isWon()) {
                  cout << "Won" << endl;
                  break;
              } else {
                  cout << "Lost" << endl;
                  break;
              }
          }
      }
      else if (cmd == "switch") {
          int r = 0, c = 0;
          cin >> r >> c;
          g.toggle(r, c);
          cout << g;
          moves--;
          if (moves != 1) {
              cout << moves << " moves left" << endl;
          } else {
              cout << moves << " move left" << endl;
          }
          if (moves == 0) {
              if (g.isWon()) {
                  cout << "Won" << endl;
                  break;
              } else {
                  cout << "Lost" << endl;
                  break;
              }
          } else {
              if (g.isWon()) {
                  cout << "Won" << endl;
                  break;
              }
          }
      }
    }
  }
  catch (ios::failure &) {
      return 0;
  }
    return 0;
}
