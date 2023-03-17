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

void printPerson(Person p[], int amt) {
    cout<<"Name\tAge\tHeight\tWeight\tBMI\tStatus\n";

    for (int i=0;i<amt;i++){


        cout<<p[i].name<<"\t"<<p[i].age<<"\t"<<p[i].height<<"\t"<<p[i].weight<<"\t";

        printf("%.1f",p[i].BMI);

        if (p[i].BMI<18.5){
            cout<<"\tToo Thin";
        }
        else if (18.5<=p[i].BMI && p[i].BMI<24){
            cout<<"\tNormal";
        }
        else if (24<=p[i].BMI && p[i].BMI<27){
            cout<<"\tToo Heavy";
        }
        else if (27<=p[i].BMI && p[i].BMI<30){
            cout<<"\tToo Too Heavy";
        }
        else if (30<=p[i].BMI && p[i].BMI<35){
            cout<< "\tToo Too Too Heavy";
        }
        else{
            cout<< "\tToo Too Too Too Heavy";

        }

        printf("\n");




    }
}
void createPerson(Person p[],int amt){
    for (int i=0;i<amt;i++){
        cin>>p[i].name;
        cin>>p[i].age;
        cin>>p[i].height;
        cin>>p[i].weight;
        p[i].BMI=p[i].weight/((p[i].height)/100*(p[i].height)/100);

    }
}
int main() {
    int amt;
    Person *p;
    cin>>amt;
    p= new Person[amt];


    createPerson(p,amt);
    printPerson(p,amt);

    return 0;
}