// Mad-lib
// формирует краткую историю на основе пользовательского ввода

#include <iostream>
#include <string>
using namespace std;

void sayHello();
string askText(string txt);
int askNum(string txt);
void tellStory(string name, string noun, int number, string bodyPart, string verb);

int main()
{
    sayHello();
    string name = askText("Please enter a name: ");
    string noun = askText("Please enter a plural noun: ");
    int number = askNum("Please enter a number: ");
    string bodyPart = askText("Please enter a body part: ");
    string verb = askText("Please enter a verb: ");
    tellStory(name, noun, number, bodyPart, verb);
    return 0;
}

void sayHello()
{
    cout << "\nWelcome to Mad Lib.\n\n";
    cout << "Answer the following questions to help create a new story.\n";
}
string askText(string txt)
{
    string out;
    cout << txt;
    cin >> out;
    return out;
}
int askNum(string txt)
{
    int out;
    cout << txt;
    cin >> out;
    return out;
}
void tellStory(string name, string noun, int number, string bodyPart, string verb)
{
    cout << "\nHere's your story:\n";
    cout << "The famous explorer " << name << " had nearly given up ";
    cout << "a life-long quest to find The Lost City of " << noun;
    cout << " when one day, the " << noun << " found the explorer. ";
    cout << "Surrounded by " << number << ' ' << noun;
    cout << ", a tear came to " << name << "'s bellybutton. ";
    cout << "After all this time, the guest was finally over. ";
    cout << "And then, the " << noun << " promptly devoured " << name;
    cout << ". The moral of the story? Be careful what you " << verb << " for.\n";
}