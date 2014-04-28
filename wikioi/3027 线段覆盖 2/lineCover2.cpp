#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
	int begin;
	int end;
	int value;
}line;

struct cmp_line
{
	bool operator()(const line &line_a, const line &line_b)
	{
		if(line_a.end < line_b.end)
		{
			return true;
		}
		return false;
	}
};

int max_value(vector<line> &lines)
{
	int max = 0;
	int last_end = 0;
	int total_end = lines.back().end + 1;
	int *step_max = new int[total_end];
	for(int i = 0; i != total_end; i++)
	{
		step_max[i] = 0;
	}
	for(int i = 0; i != lines.size(); i++)
	{
		line temp_line = lines[i];
		for(int j = last_end; j != temp_line.end; j++)
		{
			step_max[j] = max;
		}
		last_end = temp_line.end;
		step_max[temp_line.end] = max > (step_max[temp_line.begin] + temp_line.value) ? max : (step_max[temp_line.begin] + temp_line.value);
		max = step_max[temp_line.end];
	}
	return max;
}

int main()
{
	int n = 0;
	cin >> n;
	vector<line> lines(n);
	for(int i = 0; i != n; i++)
	{
		line temp_line;
		cin >> temp_line.begin;
		cin >> temp_line.end;
		cin >> temp_line.value;
		lines[i] = temp_line;
	}
	sort(lines.begin(), lines.end(), cmp_line());
	cout << max_value(lines) << endl;
	return 0;
}
