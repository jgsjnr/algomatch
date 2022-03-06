#include <iostream>
#include <iomanip>
#include <list>
#define TEN 10

int calculateDigits(int value){
    int result = 1;
    if(value >= 10){
        value = value/10;
        result += calculateDigits(value);
    };
    return result;
};

class Game{
    private:
        int id;
        std::string name;
        int biased;
        int calculateBiased(int rank, int biased){
            int digest = 0;
            if(rank >= 1 && rank <= 10) digest = biased * 3;
            else if(rank >= 11 && rank <= 50) digest = biased * 2;
            else if(rank >= 51 && rank <= 99) digest = biased * 1;
            else digest = biased * 0;
            return digest;
        };
    public:
        Game(int id, std::string name, int biased, int rank){
            this->id = id;
            this->name = name;
            this->biased = calculateBiased(biased, rank);
        };
        Game(){};
        ~Game(){};
        int getId(){return id;};
        std::string getName(){return this->name;};
        int getBiased(){return this->biased;};
};


class User{
    private:
        std::string name;
        int id;
        int hype;
        int value;
        int rank;
        int calculateHype(int rank){
            int digest = 0;
            if(rank >= 1 && rank <= 10) digest = rank * 3;
            else if(rank >= 11 && rank <= 50) digest = rank * 2;
            else if(rank >= 51 && rank <= 99) digest = rank * 1;
            else digest = rank * 0;
            return digest;
        };
    public:
        User(int id, std::string name, int rank, int value){
            this->id = id;
            this->name = name;
            this->hype = calculateHype(rank);
            this->value = value;
            this->rank = rank;
        };
        User(){};
        ~User(){};
        int getHype(){return this->hype;};
        int getValue(){return this->value;};
        int getId(){return this->id;};
        int getRank(){return this->rank;};
        void setName(std::string name){this->name = name;}; //When the player try to modify her name
        std::string getName(){return this->name;};
};

class Matcher{
    private:
        float digest;
        void setBiased(int biased){
            if(biased == 0 || biased == NULL){
                this->biased = 0;
            } else this->biased = biased;
        }
    public:
        User Player;
        Game Playing;
        Matcher(User Player){
            this->setBiased(0);
            this->digits = calculateDigits(Player.getValue());
            this->Player = Player;
        };
        Matcher(Game Playing, User Player){
            this->setBiased(Playing.getBiased());
            this->digits = calculateDigits(Player.getValue());
            this->Player = Player;
            this->Playing = Playing;
        };
        Matcher(){};
        ~Matcher(){};
        double generateMatchValue(double value, int digits){
            double matchValue;
            if(this->biased != 0){
                value = value+this->biased;
                digits = calculateDigits(value);
            };
            if(digits == 1){matchValue = value/TEN;}
            else{matchValue = value/pow(TEN, digits);};
            return matchValue;
        };
        void setResult(){this->digest = generateMatchValue(Player.getValue(), this->digits);};
        double getResult(){return this->digest;};
        int getDigits(){return this->digits;};
    protected:
        int biased;
        int digits;
      
};


class Match{
    public:
        Matcher A;
        Matcher B;
        Match(Matcher A, Matcher B){
            this->A = A;
            this->B = B;
        };
        ~Match(){};
        void testMatch(double aPlayer, double bPlayer){
            double sub = aPlayer - bPlayer;
            std::cout << std::fixed << std::setprecision(10);
            std::cout << "Valor de SUB: " << sub << std::endl;
            if(sub >= 0.05 && sub <= 0.1){
                for(double i = 0; i< tam; i++){
                    possibilities.push_front(this->generateRand());
                };
                it = possibilities.begin();
                while((sub >= possibilities.front() && sub <= possibilities.front()) && possibilities.front() != NULL){
                    std::next(it);
                }
                std::cout << "Match!" << std::endl;
            }else{
                std::cout << "Unmatch!" << std::endl;
            }
        };
        double generateRand(){
            srand (time(NULL));
            double f = (double)rand() / 0.99;
            return f;
        }
    private:
        std::list<double> possibilities;
        std::list<double>::iterator it;
        int tam = 10;
        int match;
};



int main(){
    Game Warzone(1, "Warzone", 10, 10);
    Game Warzone_1(1, "Warzone", 51, 13);
    User Player(1, "Player", 10, 500);
    User Player_1(2, "Player_1", 13, 452);
    Matcher Finder(Warzone, Player);
    Matcher Finder_1(Warzone_1, Player_1);
    Match Find(Finder, Finder_1);
    Finder.setResult();
    Finder_1.setResult();
    Find.testMatch(Finder.getResult(), Finder_1.getResult());
    std::cout << Finder.Playing.getBiased() << std::endl;
    std::cout << std::fixed << std::setprecision(10);
    std::cout << "Ola: " << Finder.Player.getName() << " Rank: ==" << Finder.Player.getRank() << "==" << std::endl;
    std::cout << "Voce iniciou uma busca para: " << Finder.Playing.getName() << std::endl;
    std::cout << "Seu numero de match e: " << Finder.getResult() << std::endl;
    if(Finder.Player.getRank() >= 1 && Finder.Player.getRank() <= 10){
        std::cout << "Seu nivel de HYPE esta: " << Finder.Player.getHype() << std::endl;
        std::cout << "Vai ser mais facil encontrar partidas pra voce jogador ;)" << std::endl;
    }else if(Finder.Player.getRank() >= 11 && Finder.Player.getRank() <= 50){
        std::cout << "Seu nivel de HYPE esta: " << Finder.Player.getHype() << std::endl;
        std::cout << "Esta otimo, mas pode melhorar, continue assim e mais ;)" << std::endl << "partidas vao ser encontradas para voce." << std::endl;
    }else if(Finder.Player.getRank() >= 51 && Finder.Player.getRank() <= 99){
        std::cout << "Seu nivel de HYPE esta: " << Finder.Player.getHype() << std::endl;
        std::cout << "Parece pequeno mas ainda esta no topo, continue assim e mais ;)" << std::endl << "partidas vao ser encontradas para voce." << std::endl;
    }else if(Finder.Player.getRank() >= 100){
        std::cout << "Seu nivel de HYPE esta: " << Finder.Player.getHype() << std::endl;
        std::cout << "Nao desista, nem todos conseguem de primeira ;)" << std::endl << "aumente seu HYPE para encontrar mais partidas." << std::endl;
    };
    std::cout << "Ola: " << Finder_1.Player.getName() << " Rank: ==" << Finder_1.Player.getRank() << "==" << std::endl;
    std::cout << "Voce iniciou uma busca para: " << Finder_1.Playing.getName() << std::endl;
    std::cout << "Seu numero de match e: " << Finder_1.getResult() << std::endl;
    if(Finder_1.Player.getRank() >= 1 && Finder_1.Player.getRank() <= 10){
        std::cout << "Seu nivel de HYPE esta: " << Finder_1.Player.getHype() << std::endl;
        std::cout << "Vai ser mais facil encontrar partidas pra voce jogador ;)" << std::endl;
    }else if(Finder_1.Player.getRank() >= 11 && Finder_1.Player.getRank() <= 50){
        std::cout << "Seu nivel de HYPE esta: " << Finder_1.Player.getHype() << std::endl;
        std::cout << "Esta otimo, mas pode melhorar, continue assim e mais ;)" << std::endl << "partidas vao ser encontradas para voce." << std::endl;
    }else if(Finder_1.Player.getRank() >= 51 && Finder_1.Player.getRank() <= 99){
        std::cout << "Seu nivel de HYPE esta: " << Finder_1.Player.getHype() << std::endl;
        std::cout << "Parece pequeno mas ainda esta no topo, continue assim e mais ;)" << std::endl << "partidas vao ser encontradas para voce." << std::endl;
    }else if(Finder_1.Player.getRank() >= 100){
        std::cout << "Seu nivel de HYPE esta: " << Finder_1.Player.getHype() << std::endl;
        std::cout << "Nao desista, nem todos conseguem de primeira ;)" << std::endl << "aumente seu HYPE para encontrar mais partidas." << std::endl;
    };
}
