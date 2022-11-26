#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <io.h>

using namespace std;

struct BinaryTree {
	float sum = 0;
	bool cod;
	bool flag = true;
	struct BinaryTree* top = nullptr;
};

BinaryTree* add(float a, float b, bool c, BinaryTree* tree, BinaryTree* buf) {
	if (tree != nullptr)
		if (tree->top == nullptr)
			tree->cod = c;
	if (tree == nullptr) {
		tree = new BinaryTree;
		tree->sum = a + b;
	}
	else
		tree->top = add(a, b, c, tree->top, buf);
	return tree;
}

BinaryTree* koren(BinaryTree* tree) {
	if (tree->top == nullptr)
		return tree;
	else
		koren(tree->top);
}

BinaryTree* add(BinaryTree* buf, bool c, BinaryTree* tree) {
	if (tree != nullptr) {
		tree->flag = false;
		if (tree->top == nullptr)
			tree->cod = c;
	}
	if (tree == nullptr)
		tree = buf;
	else
		tree->top = add(buf, c, tree->top);
	return(tree);
}

BinaryTree* entropVder(BinaryTree* tree, float& sum) {
	sum = tree->sum;
	if (tree->top == nullptr)
		return tree;
	else
		entropVder(tree->top, sum);
}

BinaryTree* comecod(BinaryTree* tree, string& cod) {
	if (tree->top != nullptr) {
		if (tree->cod)
			cod = '1' + cod;
		else
			cod = '0' + cod;
	}
	if (tree->top == nullptr)
		return tree;
	else
		comecod(tree->top, cod);
}

long double size_cod(string cod[], int count, float entr[]) {
	long double l = 0;
	for (int i = 0; i < count; i++)
		l = l + entr[i] * size(cod[i]);
	return l;
}

void s_f(int el[], long double l, long double H, int& unic_counter, string fail, string cod[]) {
	fail = fail + ".s-f";
	ofstream fout(fail);
	fout.precision(30);
	fout << H << endl << l << endl << endl;
	fout.precision(3);
	for (int i = 0; i < unic_counter; i++)
		fout << el[i] << '\t' << cod[i] << endl;
	fout.close();
}

void sort(int mas1[], float mas2[], int mas3[], int N) {
	for (int a = 0; a < N; a++)
		for (int i = 0; i < N - a; i++) {
			if (mas2[i] < mas2[i + 1]) {
				int buf1 = mas1[i];
				mas1[i] = mas1[i + 1];
				mas1[i + 1] = buf1;
				buf1 = mas3[i];
				mas3[i] = mas3[i + 1];
				mas3[i + 1] = buf1;
				float buf2 = mas2[i];
				mas2[i] = mas2[i + 1];
				mas2[i + 1] = buf2;
			}
		}
}
bool arrayOutput(int mas255[], string fail, int& unic_counter, int& all_counter) {
	unsigned char a = ' ';
	ifstream fin(fail, ios_base::binary);
	if (!fin.is_open()) {
		cout << fail << " - error_open" << endl;
		return true;
	}
	else {
		while (!fin.eof()) {
			a = fin.get();
			if (mas255[abs(int(a))] == 0)
				unic_counter++;
			mas255[abs(int(a))]++;
			all_counter++;
		}
	}
	fin.close();
	return false;
}

void create_tab(int el[], int N[], float entr[], long double& H, int& unic_counter, string fail) {
	fail = fail + ".tab";
	ofstream fout(fail);
	fout.precision(30);
	fout << H << endl << endl;
	fout.precision(3);
	for (int i = 0; i < unic_counter; i++)
		fout << el[i] << '\t' << N[i] << endl;
	fout.close();
}

void Hof(int el[], long double l, long double H, int& unic_counter, string fail, string cod[]) {
	fail = fail + ".haf";
	ofstream fout(fail);
	fout.precision(30);
	fout << H << endl << l << endl << endl;
	fout.precision(3);
	for (int i = 0; i < unic_counter; i++)
		fout << el[i] << '\t' << cod[i] << endl;
	fout.close();
}

void Hoffman(BinaryTree hof[], int count) {
	float min1 = 1, min2 = min1;
	int ind1 = 0, ind2 = 0;
	BinaryTree* buf = nullptr;
	for (int i = 0; i < count; i++) {
		if (hof[i].flag == true) {
			float entr = 0;
			entropVder(&hof[i], entr);
			if (entr <= min2) {
				min1 = min2;
				ind1 = ind2;
				min2 = entr;
				ind2 = i;
			}
			else if (entr <= min1) {
				min1 = entr;
				ind1 = i;
			}
		}
	}
	add(min1, min2, 0, &hof[ind1], buf);
	buf = koren(&hof[ind1]);
	add(buf, 1, &hof[ind2]);
	if (min1 + min2 >= 1)
		return;
	Hoffman(hof, count);
}

void HOFFMAN(float entr[], long double H, int count, string fail, int el[]) {
	BinaryTree* hof = new BinaryTree[count];
	for (int i = 0; i < count; i++)
		hof[i].sum = entr[i];
	Hoffman(hof, count);
	string* cod = new string[count];
	for (int i = 0; i < count; i++)
		comecod(&hof[i], cod[i]);
	delete[] hof;
	long double l = size_cod(cod, count, entr);
	Hof(el, l, H, count, fail, cod);
	delete[] cod;
}

void devine(float entr[], string cod[], int start, int end) {
	if (end - start == 1) return;
	float top = entr[start], bot = 0;
	for (int i = start + 1; i < end; i++) {
		bot = bot + entr[i];
	}
	float top1 = top;
	int ind = start;
	for (int i = ind + 1; i < end; i++) {
		top1 = top1 + entr[i];
		float bot1 = 0;
		for (int a = i + 1; a < end; a++) {
			bot1 = bot1 + entr[a];
		}
		if (abs(top - bot) > abs(top1 - bot1)) {
			top = top1;
			bot = bot1;
			ind = i;
		}
		else
			break;
	}
	for (int i = start; i <= ind; i++)
		cod[i] = cod[i] + '0';
	for (int i = ind + 1; i < end; i++)
		cod[i] = cod[i] + '1';
	devine(entr, cod, start, ind + 1);
	devine(entr, cod, ind + 1, end);
}

void ShenonFano(float entr[], int counter, int el[], long double H, string fail) {
	string* cod = new string[counter];
	devine(entr, cod, 0, counter);
	size_cod(cod, counter, entr);
	long double l = size_cod(cod, counter, entr);
	s_f(el, l, H, counter, fail, cod);
	delete[] cod;
}

void table(string fail) {
	int mas255[256] = { 0 };
	int all_counter = 0;
	int unic_counter = 0;
	if (arrayOutput(mas255, fail, unic_counter, all_counter))
		return;
	int* el = new int[unic_counter];
	float* entr = new float[unic_counter];
	int* N = new int[unic_counter];
	el[0] = 0;
	int b = 0;
	for (int i = 0; i < 256; i++)
		if (mas255[i] != 0) {
			el[b] = i;
			entr[b] = float(mas255[i]) / all_counter;
			N[b] = mas255[i];
			b++;
		}
	sort(el, entr, N, unic_counter);
	long double H = 0;
	for (int i = 0; i < unic_counter; i++)
		H = H + entr[i] * (log(entr[i]) / log(2));
	H = abs(H);
	create_tab(el, N, entr, H, unic_counter, fail);
	ShenonFano(entr, unic_counter, el, H, fail);
	HOFFMAN(entr, H, unic_counter, fail, el);
	delete[] el, entr, N;
}

int main() {
	string var;
	cout << "Enter your number - ";
	cin >> var;
	table("text" + var + ".txt");
	table("text" + var + ".doc");
	table("text" + var + ".docx");
	table("Pic" + var + ".JPG");
	table("Pic" + var + ".bmp");
	table("Arh" + var + ".rar");
	cout << "Files created" << endl;
}
