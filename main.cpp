#include <iostream>
#include <ctime>
#include "Character.h"

using namespace std;

void attack(Character& attacker, Character& target) {

    int minDamage = attacker.getAttack() / 2;
    int maxDamage = attacker.getAttack() - target.getDefense();
    if (maxDamage < minDamage)
        maxDamage = minDamage;
    int damage = rand() % (maxDamage - minDamage + 1) + minDamage;

    if (damage < 0)
        damage = 0;

    // Aplicar el daño al objetivo
    target.setHealth(target.getHealth() - damage);

    cout << attacker.getName() << " attacks " << target.getName() << " for " << damage << " damage!" << endl;
}

int main() {
    // Se crea el jugador y el enemigo
    Character player = Character("Jonh Wick", 100, 10, 5, 20);
    Character enemy = Character("ChapoGuzman", 100, 8, 4, 15);

    // Semilla para generación de números aleatorios
    srand(time(nullptr));

    // Mostrar el estado inicial de los personajes
    cout << "Initial Status:" << endl;
    cout << player.getName() << " - Health: " << player.getHealth() << endl;
    cout << enemy.getName() << " - Health: " << enemy.getHealth() << endl;
    cout << "---------------------------" << endl;

    // Bucle hasta que uno de los personajes muera
    while (player.getHealth() > 0 && enemy.getHealth() > 0) {
        // Turno del jugador
        attack(player, enemy);
        // Verificar si el enemigo ha muerto
        if (enemy.getHealth() <= 0) {
            cout << enemy.getName() << " has been defeated!" << endl;
            break;
        }

        // Turno del enemigo
        attack(enemy, player);
        // Verificar si el jugador ha muerto
        cout << "Remaining Health - " << player.getName() << ": " << player.getHealth() << ", " << enemy.getName() << ": " << enemy.getHealth() << endl;

        if (player.getHealth() <= 0) {
            cout << player.getName() << " has been defeated!" << endl;
            break;
        }
    }

    return 0;
}
