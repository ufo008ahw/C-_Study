#include <vector>
#include "../include/rawClass.h"
#include "../include/operatorNew.h"
#include "../include/singleton.h"
#include "../include/constPointer.h"
#include "../include/cFunctionCompileCall.h"
#include "../include/unInheritedClass.h"
#include "../include/classStorage.h"
using namespace std;

static vector<rawClass*> testers;
static void loadTester()
{
	testers.push_back(new operatorNew);
	testers.push_back(singleton::getInstance());
	testers.push_back(new constPointer());
	testers.push_back(new cFunctionCall);
	testers.push_back(new classStorage);
}

static void doTest()
{
	for(int i = 0;i < testers.size();i++)
		testers[i]->doTest();
}

static void deleteTester()
{
	for(int i = 0;i < testers.size();i++)
		delete testers[i];
	testers.clear();
}