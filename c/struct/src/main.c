#include <stdio.h>

struct human
{
    char * name;
    int age;
};


struct human _make_human_v1(char * name, int age) {
    struct human human_;
    human_.name = name;
    human_.age = age;
    return human_;
}


void make_people() {
    struct human human1, human2;
    human1 = _make_human_v1("Oleg", 37);
    human2 = _make_human_v1("Vasilisa", 26);
    struct human human3 = { "Boka", 46 };
    struct human human4 = {
        .name = "Joka",
        .age = 25,
    };

    printf("Human: %s, age = %d\n", human1.name, human1.age);
    printf("Human: %s, age = %d\n", human2.name, human2.age);
    printf("Human: %s, age = %d\n", human3.name, human3.age);
    printf("Human: %s, age = %d\n", human4.name, human4.age);
}


struct human _add_age(struct human human1, struct human human2) {
    human1.age += human2.age;
    return human1;
}


void sum_ages() {
    struct human human1, human2;
    human1 = _make_human_v1("Oleg", 37);
    human2 = _make_human_v1("Vasilisa", 26);
    printf("Human: %s, age = %d\n", human1.name, human1.age);
    printf("Human: %s, age = %d\n", human2.name, human2.age);
    struct human human3 = _add_age(human1, human2);
    human3.name = "Vasileg";
    printf("Human: %s, age = %d\n", human1.name, human1.age);
    printf("Human: %s, age = %d\n", human2.name, human2.age);
    printf("Human: %s, age = %d\n", human3.name, human3.age);
}


void test_pointers() {
    struct human *ph;
    (*ph).name = "Luka";
    (*ph).age = 84;
    printf("Human: %s, age = %d\n", (*ph).name, (*ph).age);
    ph->name = "Matthaeum";
    ph->age = 74;
    printf("Human: %s, age = %d\n", ph->name, ph->age);
}


int main() {
    printf("===========================\n");
    make_people();
    printf("===========================\n");
    sum_ages();
    printf("===========================\n");
    test_pointers();
    return 0;
}
