#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void move(int n,string a,string b,string c,vector<string> &step)
{
	string temp1;
    if(n==1)
    {
    	temp1 = "1 from " + a + " to " + c;
    	step.push_back(temp1);
    }
    else
    {
        move(n-1,a,c,b,step);            //第n-1个要从a通过c移动到b
		stringstream ss;
		ss << n;
		string temp1;
		ss >> temp1;
		temp1 = temp1 + " from " + a + " to " + c;
		step.push_back(temp1);
        move(n-1,b,a,c,step);            //n-1个移动过来之后b变开始盘，b通过a移动到c，这边很难理解
    }
}

main()
{
    int n;
    cin >> n;
    vector<string> step;
    move(n,"A","B","C",step);
    cout << step.size() << endl;
    for(int i = 0; i != step.size(); i++)
    {
    	cout << step[i] << endl;
    }
}