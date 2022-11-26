#include <iostream>

using namespace std;
const int len_str = 100;

bool is_a_text(char my_string[])
{
	__asm
	{
		mov ebx, dword ptr[my_string]
		mov al, byte ptr[ebx]
		mov ah, 0
		start_cycle:
			cmp al, 0
			je string_more_max
			cmp al, 46
			je end_of_string
			cmp al, 32
			je is_a_char
			cmp al, 48
			jb not_a_string
			cmp al, 58
			jb is_a_char
			cmp al, 65
			jb not_a_string
			cmp al, 91
			jb is_a_char
			cmp al, 97
			jb not_a_string
			cmp al, 123
			jb is_a_char
			cmp al, 128
			jb not_a_string
			cmp al, 176
			jb is_a_char
			cmp al, 224
			jb not_a_string
			cmp al, 242
			jb is_a_char
			jmp not_a_string
			is_a_char :
		cmp ah, 99
			je string_more_max
			inc ebx
			inc ah
			mov al, byte ptr[ebx]
			jmp start_cycle
			string_more_max :
		mov byte ptr[ebx], 46
			mov byte ptr[ebx + 1], 0
			end_of_string :
			mov al, 1
			jmp end_my_proc
			not_a_string :
		mov al, 0
			end_my_proc :
	}
}

bool proverka(char my_string[])
{
	__asm
	{
		mov ebx, dword ptr[my_string]
		mov ah, byte ptr[ebx]
		mov al, 1
		start_cycle:
		cmp ah, 46
			je end_my_proverka
			cmp ah, 48
			jb not_a_digit
			cmp ah, 57
			ja not_a_digit
			mov ah, byte ptr[ebx + 1]
			cmp ah, 96
			jb condition_false
			cmp ah, 123
			ja condition_false
			not_a_digit :
		inc ebx
			mov ah, byte ptr[ebx]
			jmp start_cycle
			condition_false :
		mov al, 0
			end_my_proverka :
	}
}

void first_rule(char my_string[])
{
	__asm
	{
		mov ebx, dword ptr[my_string]
		mov al, byte ptr[ebx]
		start_cycle:
		cmp al, 46
			je end_first_rule
			cmp al, 128
			jb next_char
			cmp al, 159
			ja next_char
			cmp al, 145
			jb another_method
			mov ah, 159
			sub ah, al
			mov al, 128
			add al, ah
			mov byte ptr[ebx], al
			jmp next_char
			another_method :
		mov ah, al
			sub ah, 128
			mov al, 159
			sub al, ah
			mov byte ptr[ebx], al
			next_char :
		inc ebx
			mov al, byte ptr[ebx]
			jmp start_cycle
			end_first_rule :
	}
}

void second_rule(char my_string[])
{
	__asm
	{
		mov ebx, dword ptr[my_string]
		mov al, byte ptr[ebx]
		mov edx, 0
		start_counting_cycle:
		cmp al, 0
			je end_counting
			inc edx
			inc ebx
			mov al, byte ptr[ebx]
			jmp start_counting_cycle
			end_counting :
		mov ebx, dword ptr[my_string]
			mov al, byte ptr[ebx]
			start_cycle :
			cmp al, 46
			je end_second_rule
			mov ah, byte ptr[ebx + 1]
			xor ah, al
			je obrabotka
			inc ebx
			dec edx
			mov al, byte ptr[ebx]
			jmp start_cycle
			obrabotka :
		mov ecx, edx
			cld
			lea di, byte ptr[ebx]
			lea si, byte ptr[ebx + 1]
			rep movsb
			dec edx
			jmp start_cycle
			end_second_rule :
	}
}

int main(int argc, char* argv[])
{
	cout << "Input string:\n";
	char my_string[len_str + 1];
	cin >> my_string;
	if (!is_a_text(my_string))
	{
		cout << "\nEto ne tekst\n";
		cin.get();
		return 0;
	}
	cout << "Yslovie proverki: posle kazhdoi cifri idet strochnaya latinskaya bukva: " << endl;

	if (proverka(my_string))
	{
		cout << "true\nYslovie_1: kazhdaya zaglavnaya bukva russkogo alfavita menyaetsa na protivopolozhnuyu:\n";
		first_rule(my_string);
	}
	else
	{
		cout << "false\nYslovie_2: izmenit grupu simvolov ostaviv tolko odin literal:\n";
		second_rule(my_string);
	}
	cout << my_string << "\nNazhmite ENTER dlya vihoda";
	cin.get();
	cin.get();
	return 0;
}


