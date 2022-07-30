#include <iostream>
#include<string>

/* Fizz/Buzz
 * 1から100まで（100も含む）の数全てを数え上げていき
 * 3の倍数の時に“Fizz\n”
 * 5の倍数の時に“Buzz\n”
 * 3と5の倍数の時に“FizzBuzz\n”
 * 上記いずれでもなければ、その数+"\n"を出力するプログラムを作成せよ。
 */

int main()
{
	std::string num = "";
	for (int i = 1; i <= 100; i++)
	{
		if (i % 3 == 0)num+="Fizz";
		if (i % 5 == 0)num+="Buzz";
		if (num == "")num += std::to_string(i);
		std::cout << num << "\n";
		num = "";
	}
    return EXIT_SUCCESS;
}
