#include <iostream>
#include <cmath>
#include <string>

using namespace std;
struct Person {
    string name;
    int age;
    float height;
    float weight;
    float BMI;
};

void printPerson(Person p[], int number);
void createPerson(Person p[], int number);
int main() {
    int number;
    Person p[1000];
    cin>>number;
    createPerson(p,number);
    printPerson(p,number);
    return 0;
}
void printPerson(Person p[], int number) {
    int i, j;
    cout<<"Name\tAge\tHeight\tWeight\tBMI\tStatus\n";
    for (i = 0; i < number; i++)
    {
        cout<<p[i].name;
        //calculate BMI/
                   p[i].BMI=p[i].weight/(p[i].height * p[i].height) * 10000;
        printf("\t%.0d\t%.0f\t%.0f\t%.1f\t",p[i].age, p[i].height, p[i].weight, p[i].BMI);
        //judge status/
        if (p[i].BMI<18.5)
        {
            cout<<"Too thin\n";
        }
        else if(18.5<=p[i].BMI&&p[i].BMI<24)
        {
            cout<<"Normal\n";
        }
        else if(24<=p[i].BMI&&p[i].BMI<27)
        {
            cout<<"Too heavy\n";
        }
        else if(27<=p[i].BMI&&p[i].BMI<30)
        {
            cout<<"TOO too heavy\n";
        }
        else if(30<=p[i].BMI&&p[i].BMI<35)
        {
            cout<<"Too too too heavy\n";
        }
        else
        {
            cout<<"Too too too too heavy\n";
        }
    }

}
void createPerson(Person p[], int number){
    //prompt user to enter information/
                          int i;
    for ( i = 0; i < number; i++)
    {
        cin>>p[i].name;
        cin>>p[i].age;
        cin>>p[i].height;
        cin>>p[i].weight;
    }
}