#include<iostream>

using namespace std;


// Абстрактный класс травоядных животных
class Herbivore {
public:
    virtual ~Herbivore() {}
    virtual void EatGrass() = 0;
    virtual double GetWeight() const = 0;
    virtual bool IsAlive() const = 0;
};

// Абстрактный класс плотоядных животных
class Carnivore {
public:
    virtual ~Carnivore() {}
    virtual void Eat(Herbivore& herbivore) = 0;
    virtual double GetPower() const = 0;
    virtual bool IsAlive() const = 0;
};


class Wildebeest : public Herbivore {
public:
    Wildebeest() : weight(100), alive(true) {}
    virtual void EatGrass() { weight += 10; }
    virtual double GetWeight() const { return weight; }
    virtual bool IsAlive() const { return alive; }
private:
    double weight;
    bool alive;
};


class Bison : public Herbivore {
public:
    Bison() : weight(200), alive(true) {}
    virtual void EatGrass() { weight += 10; }
    virtual double GetWeight() const { return weight; }
    virtual bool IsAlive() const { return alive; }
private:
    double weight;
    bool alive;
};


class Lion : public Carnivore {
public:
    Lion() : power(50), alive(true) {}
    virtual void Eat(Herbivore& herbivore) {
        if (power > herbivore.GetWeight()) {
            power += 10;
            herbivore.~Herbivore();
        } else {
            power -= 10;
        }
    }
    virtual double GetPower() const { return power; }
    virtual bool IsAlive() const { return alive; }
private:
    double power;
    bool alive;
};

class Wolf : public Carnivore {
public:
    Wolf() : power(30), alive(true) {}
    virtual void Eat(Herbivore& herbivore) {
        if (power > herbivore.GetWeight()) {
            power += 10;
            herbivore.~Herbivore();
        } else {
            power -= 10;
        }
    }
    virtual double GetPower() const { return power; }
    virtual bool IsAlive() const { return alive; }
private:
    double power;
    bool alive;
};

class Continent {
public:
    virtual Herbivore* createHerbivore() = 0; // Создание травоядного животного
    virtual Carnivore* createCarnivore() = 0; // Создание плотоядного животного
    virtual ~Continent() {}
};

class Africa : public Continent {
public:
    Herbivore* createHerbivore() override {
        return new Wildebeest();
    }
    Carnivore* createCarnivore() override {
        return new Lion();
    }
};

class NorthAmerica : public Continent {
public:
    Herbivore* createHerbivore() override {
        return new Bison();
    }
    Carnivore* createCarnivore() override {
        return new Wolf();
    }
};

class AnimalWorld {
public:
    void MealsHerbivores(Continent* continent) {
        Herbivore* herbivore = continent->createHerbivore();
        if (herbivore) {
            cout << "Herbivore eats grass." << endl;
            herbivore->EatGrass();
        } else {
            cout << "There are no herbivores on this continent." << endl;
        }
    }
    void NutritionCarnivores(Continent* continent) {
        Carnivore* carnivore = continent->createCarnivore();
        Herbivore* herbivore = continent->createHerbivore();
        if (carnivore && herbivore) {
            cout << "Carnivore eats herbivore." << endl;
            carnivore->Eat(*herbivore);
        } else if (!carnivore) {
            cout << "There are no carnivores on this continent." << endl;
        } else {
            cout << "There are no herbivores on this continent." << endl;
        }
    }
};


int main()
{
    Continent* africa = new Africa();
    Continent* northAmerica = new NorthAmerica();

    Herbivore* wildebeest = africa->createHerbivore();
    Herbivore* bison = northAmerica->createHerbivore();

    Carnivore* lion = africa->createCarnivore();
    Carnivore* wolf = northAmerica->createCarnivore();

    AnimalWorld world;
    world.MealsHerbivores(africa);
    world.NutritionCarnivores(northAmerica);

    return 0;
}