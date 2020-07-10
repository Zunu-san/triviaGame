#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <conio.h>
using namespace std;

void game(int NumPlay, int NumRounds, int NumQues, string questions[100][5]);
void swap(string *a, string *b);
void swapInt(int *a, int *b);
void randomize(string array[100][5]);
void randomizeInt(int array);
void question(int QuesNum, string (*questions)[5], int *points, int i, int j, int k);
void findwinner(int n, int *points, int *winnerpoints, int *winner);

int main()
{
    int NumPlay, NumRounds, NumQues, newgame;
    bool gameflag = true;
    string questions[100][5] =
    {
        /*{"Carl and the Passions changed band name to what?",
         "The thrashmen",
         "Sublime",
         "Midnight oil",
         "Beach Boys"},
        {"How many rings are on the Olympic flag?",
         "Four",
         "Six",
         "Seven",
         "Five"},
        {"What colour is vermilion a shade of",
         "Green",
         "Blue",
         "Yellow",
         "Red"}*/
        {"Carl and the Passions changed band name to what?", "The thrashmen", "Sublime", "Midnight oil", "Beach Boys"},
        {"How many rings are on the Olympic flag?", "Four", "Six", "Seven", "Five"},
        {"What colour is vermilion a shade of", "Green", "Blue", "Yellow", "Red"},
        {"King Zog ruled which country?", "Netherlands", "Sweden", "England", "Albania"},
        {"What colour is Spock's blood?", "Red", "Blue", "Purple", "Green"},
        {"Where in your body is your patella?", "In your head", "In your Leg", "In your throat", "In your knee"},
        {"Where can you find London bridge today?", "It was destroyed in world war II", "New York", "Manchester", "Arizona"},
        {"Who was the first man in space?", "Vladimir Putin", "Aleksei Leonov", "Neil Armstrong", "Yuri Gagarin"},
        {"What would you do with a Yashmak?", "Drive it", "Eat it", "Mount it", "Wear it"},
        {"Who betrayed Jesus to the Romans?", "Thomas", "Joseph", "Peter", "Judas"},
        {"Which animal doesn't lay eggs?", "Snakes", "All of them lay eggs", "Platypus", "Peacocks"},
        {"On television what was Flipper?", "A bird", "A mouse", "A dog", "A dolphin"},
        {"Who's band was The Quarrymen?", "Michael Jackson", "Angus Young", "Kurt Cobain", "John Lennon"},
        {"How many years lasted the Hundred Years War?", "78", "99", "100", "116"},
        {"What was the color of the White Horse of the Marshall Lopez?", "He didn't rode a horse", "Black", "Brown", "White"},
        {"Who are the Patriots?", "None", "La-Le-Li-Lo-Lu", "La-Li-Le-Lu-Lo", "La-Li-Lu-Le-Lo"},
        {"AVENGERS...", "...Prepared", "...Together", "...United", "...Assemble"},
        {"How many pokemon are there?", "1097", "151", "650", "807"},
        {"Pi is equal to:", "3.141537...", "3.141763...", "3.141678...", "3.141592..."},
        {"Who is Guillermo del Toro?", "An actor", "A cheff", "A musician", "A movie director"},
        {"How much blood is in the human body", "Around 10 liters", "Around 7 liters", "Around 3 liters", "Around 5 liters"},
        {"1 out of 4 is lying", "This is not the correct Answer", "This is definetly not the correct answer", "This might not be the correct answer", "This is most probably the correct answer"},
        {"How many elements are in the periodic table?", "78", "112", "98", "118"},
        {"In what year did Michael Jackson die?", "2005", "2006", "2011", "2009"},
        {"There are 86 goats, all but 6 die, how many are left?", "0", "86", "80", "6"},
        {"Who was the King of swing?", "Antonio Cesaro", "Arthur Duckworth", "Allan Reuss", "Benny Goodman"},
        {"Who was the first man to fly across the channel?", "Matthew Webb", "Gilles de Rais", "Enrique Tirabocchi", "Louis Bleriot"},
        {"Who starred as Rocky Balboa?", "Arnold Schwarzenegger", "Jean-Claude Van Damme", "Mel Gibson", "Sylvester Stallone"},
        {"In which war was the charge of the Light Brigade?", "WW1", "Franco-Prussian War", "WW2", "Crimean War"},
        {"Who invented the televisi�n?", "Alexander Graham Bell", "Nikola Tesla", "John Locke", "John Logie Baird"},
        {"Who would use a mashie niblick?", "Jockey", "Cricketer", "Footballer", "Golfer"},
        {"In the song who killed Cock Robin?", "Eagle", "Lion", "Bat", "Sparrow"},
        {"What do deciduos tres do?", "Gain leaves in autumn", "Lose their leaves in summer", "Nothing", "Lose their leaves in Winter"},
        {"In golf what name is given to the No 3 wood?", "Steel", "Fork", "Lofter", "Spoon"},
        {"If you have caries  who would consult?", "Nutritionist", "Otolaryngologist", "Nothing just waits to die", "Dentist"},
        {"What other name is Mellor�s famously known by?", "Lolita", "Opus Nigrum", "A hundred years of solitude", "Lady Chatterlys Lover"},
        {"Which of these is not a power that superman has?", "Super strenght", "Super Speed", "Super kissing", "Telepathic Immunity"},
        {"How many feet in a fathom", "3", "4", "5", "6"},
        {"What is the order 66?", "A videogame", "A historic group of dictators", "A combo in a fast food restaurant", "A command to kill all the jedi"},
        {"Name the legless fighter pilot of ww2", "Jack Churchill", "Simo Hayha", "Soichi Yokoi", "Douglas Bader"},
        {"What was the name of inn in Treasure Island?", "Tabard", "Ye Olde Good Inn", "Admiral Graf Spee", "Admiral Benbow"},
        {"What was Erich Weiss better known as?", "Evel Knive", "Lord Byron", "Criss Angel", "Harry Houdini"},
        {"Who sailed in the Ni�a, Pinta and Santa Maria?", "Vasco Da Gama", "Francis Drake", "Fernando de Magallanes", "Cristoforo Colombo"},
        {"Which leader died in St Helena?", "Julius Caesar", "Adolf Hitler", "Attila", "Napoleon Bonaparte"},
        {"Who wrote Gone with the wind?", "Ernest Hemingway", "Jane Austen", "Charles Dickens", "Margaret Mitchel"},
        {"What does Ring a Ring of Roses refer to?", "Spanish flu", "Yellow fever", "Covid 19", "The black death"},
        {"Whose nose grew when he told a lie?", "Tinkerbell", "The Cinderella", "Elric of Melnibone", "Pinocchio"},
        {"Who has won the most Oscars?", "Leonardo DiCaprio", "Katherine Hepburn", "Walter Brennan", "Walt Disney"},
        {"What would a Scotsman do with a spirtle?", "Drink Whiskey", "Sing Auld Lang Syne", "Caber toss", "Eat porridge"},
        {"Which award has the words for valour on it?", "Iron Cross", "Pour le Merite", "George Cross", "Victoria Cross"},
        {"Where is the capital of the strawberry?", "Ita", "Caaguazu", "Caacupe", "Aregua"},
        {"How many primary types of tastes are there?", "2", "4", "7", "5"},
        {"In what year did the World War 2 end?", "1972", "1920", "1952", "1945"},
        {"Who's the King of Pop?", "The Weekend", "Bruno Mars", "Justin Bieber", "Michael Jackson"},
        {"What does the acronym NASA stands for?", "National Administration of Space Astronauts", "National Administration of Space Aircrafts", "National Astrologic and Space Asociation", "National Aeronautics and Space Administration"},
        {"Who's the king of rock?", "Slash", "Jimmy Hendrix", "Johnny B. Good", "Elvis Presley"},
        {"What studies the Cartohraphy?", "Terrestrial Movement", "Correct Writing", "Carts", "Maps"},
        {"What is the largest country?", "India", "United States", "Brazil", "Russia"},
        {"What is the third planet of our solar system?", "Jupiter", "Mars", "Mercury", "Earth"},
        {"In which part of the body is the Insuline produced?", "Stomach", "Veins", "Kidneys", "Pancreas"},
        {"What architectonic style does the Notre Dame Cathedral use?", "Renaissance", "Neo-Classical", "Baroque", "Gothic"},
        {"How many legs does a spider have?", "12", "10", "6", "8"},
        {"How many legs does a centipede have?", "From 25 to 522", "More than 400", "Exactly 100", "From 30 to 354"},
        {"What is the official language of China?", "Cantonese", "Thai", "Chinese", "Mandarin"},
        {"What was the first metal used by men?", "Lead", "Zinc", "Iron", "Copper"},
        {"What is a prime number?", "A number that is not composite", "A number that is not a product of two smaller natural numbers", "A number that can only be divided by 1 and itself", "All answers are right"},
        {"What mammal is the only one that can fly?", "Flying squirrel", "Flies", "Birds", "Bats"},
        {"What is smaller?", "A cell", "A proton", "A molecule", "An atom"},
        {"How many sides does an Equilateral Triangle have?", "Five", "Six", "Four", "Three"},
        {"How many meanings does the word 'set' have?", "12", "6", "5", "430"},
        {"How many calories does being sit for 7 hours burn?", "75", "35", "8", "701"},
        {"What is the name of the protagonist of Rocky?", "Bruce", "Arnold", "Silvester", "Rocky"},
        {"What is the most expensive metal in the world?", "Vibranium", "Platinum", "Gold", "Rhodium"},
        {"What animals have the most effective way to repeat words and phrases?", "Monkeys", "Gorillas", "Parrots", "Crows"},
        {"Which of these aliments does expire?", "Alcohol", "Instant Coffee", "Honey", "Eggs"},
        {"How many stars are there in the chinese flag?", "Twelve", "Eight", "Six", "Five"},
        {"What is the largest organ in the human body?", "Brain", "Pancreas", "Lung", "Skin"},
        {"How many oscars does the actress Katharine Hepburn have?", "Two", "Zero", "Twelve", "Four"},
        {"How many sides does a Myriagon have?", "100000", "1000", "100", "10000"},
        {"How much percentage of the earth is actually water?", "60%", "80%", "30%", "70%"},
        {"What is a Drosophila", "A fobia for dresses", "A chemical compound", "A mythological criature", "A fly"},
        {"What is the capital of Venezuela?", "Lima", "Venezuela", "Quito", "Caracas"},
        {"Which one of these is not a real word in the english language?", "Tittynope", "Serendipity", "Gobbledygook", "Fhalontropia"},
        {"What european country shares a border with Brazil?", "Belgium", "England", "Germany", "France"},
        {"Which letter is related to a printing color, potassium and scoring in baseball?", "P", "X", "B", "K"},
        {"The three actors who played Iron Man, Magneto and Dr Strange also played...", "Dr Dolittle", "Indiana Jones", "James Bond", "Sherlock Holmes"},
        {"Which of these organs cannot be transplanted?", "Skin", "Lungs", "A kidney", "The brain"},
        {"In which of these countries you cannot find Coca Cola?", "Portugal", "India", "Africa", "Cuba"},
        {"The Canary Islands are named after what animals?", "Fish", "Cats", "Birds", "Dogs"},
        {"How many countries do not use the metric system?", "33", "15", "8", "3"},
        {"What is the most popular name in the world?", "Shang", "James", "John", "Muhammad"},
        {"How many countries have the color purple in their national flag?", "Twelve", "Seven", "Five", "Two"},
        {"How many countries still have a royal family?", "10", "8", "5", "43"},
        {"9% of the forests of the world are in...", "Asia", "The Amazonas", "Africa", "Canada"},
        {"What is the most spoken language on earth?", "Hindi", "Spanish", "English", "Mandarin"},
        {"How many countries recognize sign language as an official language?", "3", "23", "15", "41"},
        {"How many countries start with 'The'?", "6", "3", "5", "2"},
        {"What does ants and humans have in common?", "Both appeared for the first time in the same period of history", "The social interactions", "Amount of hours to sleep", "All of their respective populations weight the same"},
        {"Where is the largest city in the world?", "India", "USA", "Russia", "Japan"},
        {"What relationship is between Luke and Leia from Star Wars?", "They're enemies", "They're a couple", "They're partners", "They're siblings"}
    };
    cout << "WELCOME TO THE MULTIPLAYER TRIVIA GAME" << endl
         << "In this game, from 2 up to 5 players can compete with each other answering questions of general knowledge, in" << endl
         << "which every right answer will give each player a certain amount of points to decide who is the smarty pants and" << endl
         << "who is the dumb of the group, these questions can be about any general theme, like science, medicine, math, etc."  << endl
         << "But dont worry my nerdy friend, because there are questions about movies, videogames and every sort of thing that you" << endl
         << "may like, stuffed into a mix of questions for everyone to respond, so good luck and may the force be with you." << endl;
    system("pause");
    system("cls");
    while (gameflag)
    {
        cout << "How many are going to play? (2-5): " << endl;
        cin >> NumPlay;
        while (2 > NumPlay || NumPlay > 5)
        {
            cout << "Please select the adecuate range, only 2 to 5 players. Try again: " << endl;
            cin >> NumPlay;
        }
        cout << "How many rounds do you want? (1-4): " << endl;
        cin >> NumRounds;
        while (1 > NumRounds || NumRounds > 4)
        {
            cout << "You can only choose between 1-4 rounds. Try again: " << endl;
            cin >> NumRounds;
        }
        cout << "And how many questions per round? (1-5): " << endl;
        cin >> NumQues;
        while (1 > NumQues || NumQues > 5)
        {
            cout << "Please, select from 1 to 5 questions. Try again: " << endl;
            cin >> NumQues;
        }
        system("cls");
        game(NumPlay, NumRounds, NumQues, questions);
        cout << "Wanna play again? (Y/N): " << endl;
        newgame = getch();
        while (newgame != 89 && newgame != 121 && newgame != 78 && newgame != 110)
        {
            cout << "Y or N, is not that hard to choose... Try again: " << endl;
            newgame = getch();
        }
        if (newgame == 89 || newgame == 121)
        {
            cout << "So here we go again..." << endl;
        }
        else if (newgame == 78 || newgame == 110)
        {
            cout << "Please come back later :D" << endl;
            gameflag = false;
        }
    }
}
void game(int NumPlay, int NumRounds, int NumQues, string questions[100][5])
{
    randomize(questions);
    int winners = 0;
    int winnerpoints = 0;
    int points[NumPlay];
    int untie;
    for (int i = 0; i < NumPlay; i++)
    {
        points[i] = 0;
    }
    for (int i = 0; i < NumRounds; i++)
    {
        for (int j = 0; j < NumPlay; j++)
        {
            for (int k = 0; k < NumQues; k++)
            {
                question(i * NumQues * NumPlay + j * NumQues + k, questions, &points[0], i, j, k);
                cout << "Points: " << points[j] << endl;
                system("pause");
                system("cls");
            }
        }
    }
    findwinner(NumPlay, &points[0], &winnerpoints, &winners);
    if (winners > 1)
    {
        cout << "There was a tie between: " << endl;
        for (int i = 0; i < NumPlay; i++)
        {
            if (points[i] == winnerpoints)
            {
                cout << "Player " << i+1 << endl;
            }
        }
        cout << "Wanna untie? (Y/N): " << endl;
        untie = getch();
        while (untie != 89 && untie != 121 && untie != 78 && untie != 110)
        {
            cout << "Press Y if you wanna untie, N if you don't want to, even a toddler could understand? Try again: " << endl;
            untie = getch();
        }
        if (untie == 89 || untie == 121)
        {
            cout << "One round, one question each, let the games begin." << endl;
            game(winners, 1, 1, questions);
        }
    }
    else
    {
        cout << "The smarty pants is... PLAYER " << endl;
        for (int i = 0; i < NumPlay; i++)
        {
            if (points[i] == winnerpoints)
            {
                cout << i + 1 << endl;
            }
        }
    }
    system("pause");
}
void swap(string *a, string *b)
{
    string temp = *a;
    *a = *b;
    *b = temp;
}
void swapInt(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void randomize(string array[100][5])
{
    srand(time(NULL));
    for (int i = 99; i >= 0; i--)
    {
        int j = rand() % (i + 1);
        for (int k = 0; k < 5; k++)
        {
            swap(&array[i][k], &array[j][k]);
        }
    }
}
void randomizeInt(int array[4])
{
    srand(time(NULL));
    for (int i = 3; i >= 0; i--)
    {
        int j = rand() % (i + 1);
        swapInt(&array[i], &array[j]);
    }
}
void question(int QuesNum, string (*questions)[5], int *points, int i, int j, int k)
{
    int n[4] = {1, 2, 3, 4};
    int ans;
    string cans = *(*(questions + QuesNum) + 4);
    bool endtime = false;
    randomizeInt(n);
    clock_t start = clock();
    while (!_kbhit())
    {
        cout << "Round " << i + 1 << "! Fight!" << endl
             << "Player " << j + 1 << "'s turn" << endl
             << "Question number " << k + 1 << ":" << endl
             << *(*(questions + QuesNum) + 0) << endl
             << endl
             << "1. " << *(*(questions + QuesNum) + n[0]) << endl
             << "2. " << *(*(questions + QuesNum) + n[1]) << endl
             << "3. " << *(*(questions + QuesNum) + n[2]) << endl
             << "4. " << *(*(questions + QuesNum) + n[3]) << endl
             << endl
             << "Time left: " << 10 - (clock() - start) / CLOCKS_PER_SEC << endl
             << "Answer: " << endl;
        if (((clock () - start)/ CLOCKS_PER_SEC ) >= 10)
        {
            endtime = true;
            goto ENDTIMER;
        }
        system("cls");
    }
    ans = getch() - 48;
    cout << "Round " << i + 1 << "! Fight!" << endl
         << "Player " << j + 1 << "'s turn" << endl
         << "Question number " << k + 1 << ":" << endl
         << *(*(questions + QuesNum) + 0) << endl
         << endl
         << "1. " << *(*(questions + QuesNum) + n[0]) << endl
         << "2. " << *(*(questions + QuesNum) + n[1]) << endl
         << "3. " << *(*(questions + QuesNum) + n[2]) << endl
         << "4. " << *(*(questions + QuesNum) + n[3]) << endl
         << endl
         << "Time left: " << 10 - (clock() - start) / CLOCKS_PER_SEC << endl;
ENDTIMER:
    if(endtime)
    {
             cout << "Time ended" << endl
                  << "The right answer was '" << cans << "'" << endl;

    }
    else if ((1 > ans || ans > 4) && !endtime)
    {
        cout << "Answer: " << endl
             << "You wanted to know what happened if you pressed another number right? Well now you know." << endl
             << "By the way, the answer was '" << cans << "'" << endl;
    }
    else if (cans == *(*(questions + QuesNum) + n[ans - 1]))
    {
        cout << "Answer: " << ans << ". " << *(*(questions + QuesNum) + n[ans - 1]) << endl
             << "C-C-C-COOORRRRECT!!!" << endl;
        *(points + j) += 10;
    }
    else
    {
        cout << "Answer: " << ans << ". " << *(*(questions + QuesNum) + n[ans - 1]) << endl
             << "You seriously don't know? The correct answer is '" << cans << "', everyone knows that." << endl;
    }
}
void findwinner(int n, int *points, int *winnerpoints, int *winners)
{
    for (int i = 0; i < n; i++)
    {
        if (*(points + i) > *winnerpoints)
        {
            *winnerpoints = *(points + i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (*(points + i) == *winnerpoints)
        {
            (*winners) += 1;
        }
    }
}
