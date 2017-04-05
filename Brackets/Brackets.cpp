#include <iostream>
#include <iterator>
#include <stack>
#include <set>
#include <map>
#include <algorithm>

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid amount of arguments" << std::endl;
		return 1;
	}

	std::string input(argv[1]);
	std::map<char, char> dict
	{
		std::make_pair('}', '{'), 
		std::make_pair(']', '['), 
		std::make_pair(')', '(')
	};

	std::set<char> dict_start;

	std::transform(dict.begin(), dict.end(), std::inserter(dict_start, dict_start.begin()),
    [](const std::pair<char, char>& key_value) {
        return key_value.second;
    });

    std::cout << "Trace: ";
    std::copy(dict_start.begin(), dict_start.end(),
              std::ostream_iterator<char>(std::cout, " "));
    std::cout << std::endl;

	std::stack<char> st;
	for (auto& c : input)
	{
		if (dict.find(c) != dict.end() && st.empty())
		{
			std::cout << "Invalid sequence of brackets" << std::endl;
			return 2;
		} 

		if (dict_start.find(c) != dict_start.end())
		{
			st.push(c);
			continue;
		}

		if (dict.find(c) != dict.end() && !st.empty())
		{
			if (dict.at(c) == st.top())
				st.pop();
			else
			{
				std::cout << "Invalid sequence of brackets" << std::endl;
				return 3;
			}
		}
	}

	return 0;
}