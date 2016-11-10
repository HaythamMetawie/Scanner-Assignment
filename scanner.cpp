#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;

bool isSpace(char s) { return (s == ' ' || s == '\t' || s == '\n'); }

bool isSymbol(char c) { return (c == '+' || '-' || '*' || '/' || '=' || '<' || '(' || ')' || ';' || ':='); }


enum states { START, INCOMMENT, INNUM, INID, INASSIGN, DONE };
//enum res_words { IF, THEN, ELSE, END, REPEAT, UNTIL, READ, WRITE };

string RES_WORDS[] = { "if","then","else","end","repeat","until","read","write" };

states state = START; //initial state

void getToken(string l)
{
	string mytoken;
	bool res_flag = 0;
	int i = 0;
	while (state != DONE) {
		switch (state) {
		case START:
			if (isSpace(l[i])) {
				i++;
				if (i == l.length()) state = DONE;
				else state = START;
			}
			else if (isdigit(l[i])) {
				state = INNUM;
			}
			else if (isalpha(l[i])) {
				state = INID;
			}
			else if (l[i] == ':') {
				state = INASSIGN;
			}
			else if (l[i] == '{') {
				i++;
				state = INCOMMENT;
			}
			else if (isSymbol(l[i])) {
				switch (l[i]) {
				case '+': cout << l[i] << " :plus" << endl; break;
				case '-': cout << l[i] << " :minus" << endl; break;
				case '*': cout << l[i] << " :multiply" << endl; break;
				case '/': cout << l[i] << " :divide" << endl; break;
				case '=': cout << l[i] << " :equal" << endl; break;
				case '<': cout << l[i] << " :less than" << endl; break;
				case '(': cout << l[i] << " :left bracket" << endl; break;
				case ')': cout << l[i] << " :right bracket" << endl; break;
				case ';': cout << l[i] << " :semicolon" << endl; break;
				//case ':': cout << l[i] << l[i + 1] << " :assign" << endl; i++; break;
				default: cout << l[i] << " :special symbol"; break;
				}
				i++;
				if (i == l.length()) state = DONE;
				else state = START;
			}
			else state = DONE;
			break;

		case INCOMMENT:
			if (state == INCOMMENT) {
				while (l[i] != '}') {
					i++;
				}
				i++;
				if (i == l.length()) state = DONE;
				else state = START;
			}
			break;

		case INNUM:
			while (isdigit(l[i])) {
				mytoken += l[i];
				i++;
			}
			cout << mytoken << " :digit" << endl;
			mytoken = "";
			if (i == l.length()) state = DONE;
			else state = START;
			break;

		case INID:
			while (isalpha(l[i])) {
				mytoken += l[i];
				i++;
			}
			for (int i = 0; i < 8; i++)
			{
				if (RES_WORDS[i] == mytoken) res_flag = 1;
			}
			if (res_flag) cout << mytoken << " :reserved word" << endl;
			else cout << mytoken << " :identifier" << endl;
			mytoken = "";
			res_flag = 0;
			if (i == l.length()) state = DONE;
			else state = START;
			break;

		case INASSIGN:
			if (l[i] == ':') {
				i += 2;
				cout << ":=" << " :assign" << endl;
				state = START;
			}
			else {
				if (i == l.length()) state = DONE;
				else state = START;
			}
			break;
		case DONE:
			break;
		}
	}
}
/***********************************************************************************************************/
/**********************************************************************************************************/

int main() {

	ifstream f;
	string line, code;

     f.open("test_code.txt");
	while (!f.eof()) {
		getline(f, line);
		code += line;
	}
    getToken(code);

	return 0;
}
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;

bool isSpace(char s) { return (s == ' ' || s == '\t' || s == '\n'); }

bool isSymbol(char c) { return (c == '+' || '-' || '*' || '/' || '=' || '<' || '(' || ')' || ';' || ':='); }


enum states { START, INCOMMENT, INNUM, INID, INASSIGN, DONE };
//enum res_words { IF, THEN, ELSE, END, REPEAT, UNTIL, READ, WRITE };

string RES_WORDS[] = { "if","then","else","end","repeat","until","read","write" };

states state = START; //initial state

void getToken(string l)
{
	string mytoken;
	bool res_flag = 0;
	int i = 0;
	while (state != DONE) {
		switch (state) {
		case START:
			if (isSpace(l[i])) {
				i++;
				if (i == l.length()) state = DONE;
				else state = START;
			}
			else if (isdigit(l[i])) {
				state = INNUM;
			}
			else if (isalpha(l[i])) {
				state = INID;
			}
			else if (l[i] == ':') {
				state = INASSIGN;
			}
			else if (l[i] == '{') {
				i++;
				state = INCOMMENT;
			}
			else if (isSymbol(l[i])) {
				switch (l[i]) {
				case '+': cout << l[i] << " :plus" << endl; break;
				case '-': cout << l[i] << " :minus" << endl; break;
				case '*': cout << l[i] << " :multiply" << endl; break;
				case '/': cout << l[i] << " :divide" << endl; break;
				case '=': cout << l[i] << " :equal" << endl; break;
				case '<': cout << l[i] << " :less than" << endl; break;
				case '(': cout << l[i] << " :left bracket" << endl; break;
				case ')': cout << l[i] << " :right bracket" << endl; break;
				case ';': cout << l[i] << " :semicolon" << endl; break;
				//case ':': cout << l[i] << l[i + 1] << " :assign" << endl; i++; break;
				default: cout << l[i] << " :special symbol"; break;
				}
				i++;
				if (i == l.length()) state = DONE;
				else state = START;
			}
			else state = DONE;
			break;

		case INCOMMENT:
			if (state == INCOMMENT) {
				while (l[i] != '}') {
					i++;
				}
				i++;
				if (i == l.length()) state = DONE;
				else state = START;
			}
			break;

		case INNUM:
			while (isdigit(l[i])) {
				mytoken += l[i];
				i++;
			}
			cout << mytoken << " :digit" << endl;
			mytoken = "";
			if (i == l.length()) state = DONE;
			else state = START;
			break;

		case INID:
			while (isalpha(l[i])) {
				mytoken += l[i];
				i++;
			}
			for (int i = 0; i < 8; i++)
			{
				if (RES_WORDS[i] == mytoken) res_flag = 1;
			}
			if (res_flag) cout << mytoken << " :reserved word" << endl;
			else cout << mytoken << " :identifier" << endl;
			mytoken = "";
			res_flag = 0;
			if (i == l.length()) state = DONE;
			else state = START;
			break;

		case INASSIGN:
			if (l[i] == ':') {
				i += 2;
				cout << ":=" << " :assign" << endl;
				state = START;
			}
			else {
				if (i == l.length()) state = DONE;
				else state = START;
			}
			break;
		case DONE:
			break;
		}
	}
}
/***********************************************************************************************************/
/**********************************************************************************************************/

int main() {

	ifstream f;
	string line, code;

     f.open("test_code.txt");
	while (!f.eof()) {
		getline(f, line);
		code += line;
	}
    getToken(code);

	return 0;
}
