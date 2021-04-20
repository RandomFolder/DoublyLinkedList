#include <iostream>
#include <conio.h>

using namespace std;

struct Number
{
	int num;
	Number* next_num;
	Number* prev_num;
};

Number* head = NULL;

int CountElements()
{
	int count = 1;
	Number* element = head;
	if (head == NULL)
	{
		return 0;
	}
	while (element)
	{
		element = element->next_num;
		count++;
	}
	return count - 1;
}

void AddNum()
{
	int number, index;
	cout << "insert number: ";
	cin >> number;
	cout << "Enter index: ";
	cin >> index;
	if (index > CountElements() + 1) index = CountElements() + 1;
	if (index < 1) index = 1;
	Number* num1 = new Number;
	num1->num = number;
	if (index == 1)
	{
		num1->next_num = head;
		num1->prev_num = NULL;
		if (head) head->prev_num = num1;
		head = num1;
		return;
	}
	Number* num2 = head;
	for (int i = 1; i < index - 1; i++)
		num2 = num2->next_num;
	num1->next_num = num2->next_num;
	if (num1->next_num) num1->next_num->prev_num = num1;
	num1->prev_num = num2;
	num2->next_num = num1;
}

void AddNumbers()
{
	int index, num_of_el;
	Number* beginning = head;
	cout << "Enter index: ";
	cin >> index;
	cout << "Enter number of elements: ";
	cin >> num_of_el;
	if (index > CountElements() + 1) index = CountElements() + 1;
	if (index < 1) index = 1;
	if (index == 1)
	{
		bool adding1stEl = true;
		for (int i = 1; i <= num_of_el; i++)
		{
			int number;
			cout << "insert number: ";
			cin >> number;
			Number* new_num = new Number;
			new_num->num = number;
			if (adding1stEl)
			{
				new_num->next_num = head;
				new_num->prev_num = NULL;
				if (head) head->prev_num = new_num;
				head = new_num;
				beginning = head;
				adding1stEl = false;
			}
			else
			{
				new_num->next_num = beginning->next_num;
				if (new_num->next_num) new_num->next_num->prev_num = new_num;
				new_num->prev_num = beginning;
				beginning->next_num = new_num;
				beginning = beginning->next_num;
			}
		}
		return;
	}
	for (int i = 1; i < index - 1; i++)
		beginning = beginning->next_num;
	for (int i = 1; i <= num_of_el; i++)
	{
		int number;
		cout << "insert number: ";
		cin >> number;
		Number* new_num = new Number;
		new_num->num = number;
		new_num->next_num = beginning->next_num;
		if (new_num->next_num) new_num->next_num->prev_num = new_num;
		new_num->prev_num = beginning;
		beginning->next_num = new_num;
		beginning = beginning->next_num;
	}
}

void ShowList(bool backw)
{
	Number* element = head;
	if (element == NULL)
	{
		cout << "list is empty" << endl;
		return;
	}
	if (!backw)
	{
		int index = 1;
		while (element)
		{
			cout << element->num << '[' << index << ']' << '\t';
			element = element->next_num;
			index++;
		}
	}
	else
	{
		for (int i = 1; i < CountElements(); i++)
			element = element->next_num;
		int index = CountElements();
		for (int i = 1; i <= CountElements(); i++)
		{
			cout << element->num << '[' << index << ']' << '\t';
			element = element->prev_num;
			index--;
		}
	}
	cout << endl << endl;
}

void ChangeElement()
{
	int new_num, index;
	Number* element = head;
	cout << "insert new number: ";
	cin >> new_num;
	cout << "Enter index: ";
	cin >> index;
	if (index > CountElements()) index = CountElements();
	if (index < 1) index = 1;
	if (head)
	{
		for (int i = 1; i < index; i++)
			element = element->next_num;
		element->num = new_num;
	}
}

void DeleteNumberFromAList()
{
	Number* element = head;
	int needed_index, cur_index = 1;
	if (head == NULL)
		return;
	cout << "Enter index: ";
	cin >> needed_index;
	if (needed_index > CountElements()) needed_index = CountElements();
	if (needed_index < 1) needed_index = 1;
	if (needed_index == 1)
	{
		head = head->next_num;
		head->prev_num = NULL;
		delete element;
		return;
	}
	while (cur_index != needed_index - 1)
	{
		element = element->next_num;
		cur_index++;
	}
	Number* deleted_num = element->next_num;
	element->next_num = deleted_num->next_num;
	if (element->next_num) element->next_num->prev_num = element;
	delete deleted_num;
}

void DeleteListFromNthPos()
{
	int index;
	Number* element = head;
	if (head == NULL)
		return;
	cout << "Enter index: ";
	cin >> index;
	if (index > CountElements()) index = CountElements();
	if (index < 1) index = 1;
	if (index == 1)
	{
		while (head)
		{
			element = head;
			head = head->next_num;
			delete element;
		}
		return;
	}
	for (int i = 1; i < index - 1; i++)
		element = element->next_num;
	while (element->next_num)
	{
		Number* deleted_el = element->next_num;
		element->next_num = deleted_el->next_num;
		if (element->next_num) element->next_num->prev_num = element;
		delete deleted_el;
	}
}

void DeleteFromStartToEnd()
{
	int beginning, end;
	Number* element = head;
	if (head == NULL)
		return;
	cout << "Enter first index: ";
	cin >> beginning;
	if (beginning > CountElements()) beginning = CountElements();
	if (beginning < 1) beginning = 1;
	cout << "Enter last index: ";
	cin >> end;
	if (end > CountElements()) end = CountElements();
	if (end < 1) end = 1;
	if (beginning == 1)
	{
		for (int i = 1; i <= end; i++)
		{
			element = head;
			head = head->next_num;
			delete element;
		}
		return;
	}
	for (int i = 1; i < beginning - 1; i++)
		element = element->next_num;
	for (int i = beginning; i <= end; i++)
	{
		Number* deleted_el = element->next_num;
		element->next_num = deleted_el->next_num;
		if (element->next_num) element->next_num->prev_num = element;
		delete deleted_el;
	}
}

int main()
{
	head = NULL;
	int cursor_pos_x = 41, cursor_pos_y = 0;
	char menu[10][42] = { "1)add element                            ", "2)change element                         ", "3)delete element                         ", "4)show list length                       ", "5)delete list starting from nth element  ", "6)delete list from nth index to mth      ", "7)add multiple elements                  ", "8)print list forwards                    ", "9)print list backwards                   ",  "10)exit                                  "};
	bool running = true, showListLen = false, backwards = false;

	while (running)
	{
		system("cls");
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 42; j++)
			{
				(i == cursor_pos_y && j == cursor_pos_x) ? (cout << '<') : (cout << menu[i][j]);
			}
			cout << endl;
		}
		cout << endl;
		ShowList(backwards);

		if (showListLen)
			cout << "list consists of " << CountElements() << " elements";

		switch (_getch())
		{
		case 72:
			(cursor_pos_y == 0) ? (cursor_pos_y = 9) : (cursor_pos_y--);
			showListLen = false;
			break;
		case 80:
			(cursor_pos_y == 9) ? (cursor_pos_y = 0) : (cursor_pos_y++);
			showListLen = false;
			break;
		case 13:
			switch (cursor_pos_y)
			{
			case 0:
				AddNum();
				break;
			case 1:
				ChangeElement();
				break;
			case 2:
				DeleteNumberFromAList();
				break;
			case 3:
				showListLen = true;
				break;
			case 4:
				DeleteListFromNthPos();
				break;
			case 5:
				DeleteFromStartToEnd();
				break;
			case 6:
				AddNumbers();
				break;
			case 7:
				backwards = false;
				break;
			case 8:
				backwards = true;
				break;
			case 9:
				running = false;
				break;
			}
		}
	}
	return 0;
}