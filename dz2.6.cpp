#include <iostream>
#include <vector>

class Butterfly
{
private:
	std::string stagename;
	int day;
public:
	Butterfly(int i)
	{
		day = i;
	}
	void checkstage()
	{
		if (day == 24)
		{
			day = 0;
		}
		if (day < 8)
		{
			stagename = "caterpillar";
		}
		else if (day > 7 && day < 16)
		{
			stagename = "chrysalis  "; //пробелы после слова для того, чтобы в консоли красиво было
		}
		else if (day > 15)
		{
			stagename = "butterfly  ";
		}
	}
	void currentday()
	{
		checkstage();
		std::cout << "Stage: " << stagename << "    " << "Days: " << day << std::endl;
	}
	void stagechange()
	{
		day += 1;
		currentday();
	}
};

int main()
{
	Butterfly b1{ 0 }, b2{ 2 }, b3{ 4 }, b4{ 7 }, b5{ 9 }, b6{ 12 }, b7{ 15 }, b8{ 16 }, b9{ 19 }, b10{ 23 };
	std::vector<Butterfly*> vec{ &b1, &b2, &b3, &b4, &b5, &b6, &b7, &b8, &b9, &b10 };
	std::cout << "Original vector: " << std::endl;
	for (int i = 0; i < vec.size(); i++)
	{
		vec[i]->currentday();
	}
	std::cout << std::endl << "Edited vector: " << std::endl;
	for (int i = 0; i < vec.size(); i++)
	{
		vec[i]->stagechange();
	}
}