/**
 * Nainicializujte studenta se zadaným věkem a jménem.
 * Počet bodů i nejlepší přítel by měli být nastaveni na nulu.
 */
typedef struct Student{
char jmeno[30];
int age;
int points;
struct Student* best_friend;

}Student;
void student_init(Student* student, int age, const char* name) {
    Student age =age;
}

/**
 * Spočítejte, kolik studentů v předaném poli má maximálně zadaný věk.
 * Příklad:
 *   Student students[3];
 *   students[0].age = 18;
 *   students[1].age = 19;
 *   students[2].age = 16;
 *
 *   count_young_students(students, 3, 18); // 2
 */
int count_young_students(Student* students, int count, int maximum_age) {}

/**
 * Přiřaďte studentům body na základě výsledků testů.
 * V poli `points` jsou body pro jednotlivé studenty v poli `students`.
 * Parameter `count` obsahuje počet studentů a testů.
 */
void assign_points(Student* students, const int* points, int count) {}

/**
 * Vraťe v parametru `good_students` pole studentů, kteří mají alespoň 51 bodů a v
 * parametru `good_student_count` jejich počet.
 * Budete muset dynamicky naalokovat nové pole s odpovídající velikostí.
 */
void filter_good_students(
    const Student* students,
    int count,
    Student** good_students,
    int* good_student_count
);

/**
 * Otestujte, jestli je student šťastný.
 * Student je šťastný, pokud:
 * 1) Má alespoň 51 bodů, a zároveň
 * 2) Jeho nejlepší přítel je šťastný
 *
 * Pokud student nemá nejlepšího přítele, pokládejte podmínku 2) za splněnou.
 */
int student_is_happy(Student* student) {}