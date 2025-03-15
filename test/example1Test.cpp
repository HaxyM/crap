#include "../example/myawsomevariant/myawsomevariant.h"

void test1()
{
 MyAwsomeVariant<int, float> a;
 a.emplace<float>(42.0);
 const auto b = a;
 const MyAwsomeVariant<float, int> c = a;
}

void test2()
{
 MyAwsomeVariant<int, float> a;
 a.emplace<float>(42.0);
 auto b = std :: move(a);
 const MyAwsomeVariant<float, int> c = std :: move(b);
}

void test3()
{
 MyAwsomeVariant<int, float> a;
 a.emplace<float>(42.0);
 auto b = a;
 MyAwsomeVariant<float, int> c;
 c = a;
 b = a;
 c = b;
}

void test4()
{
 MyAwsomeVariant<int, float> a;
 a.emplace<float>(42.0);
 auto b = a;
 MyAwsomeVariant<float, int> c;
 c = std :: move(a);
 b = std :: move(c);
}

int main()
{
 test1();
 test2();
 test3();
 test4();
}
