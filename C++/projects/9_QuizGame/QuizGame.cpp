#include <iostream>
#include <algorithm>

int Shuffle(std::string Array[], int Arraysize) {
    for(int i = 0; i < Arraysize ; i++) {
        int RandomIndex = rand() % Arraysize;
        std::string TempValue = Array[i];
        Array[i] = Array[RandomIndex];
        Array[RandomIndex] = TempValue;
    }
    return 0;
}

int main() {
    srand (time(NULL));
    std::string Questions[] = {
        "What are two things you can never eat for breakfast?",
        "What is always coming but never arrives?",
        "What gets wetter the more it dries?",
        "What can be broken but never held?"
    };
    std::string Answers[][4] = {
        {"Lunch and Dinner","Apple and Banana","Eggs and Bacon","Pizza and Ice cream"},
        {"Tomorrow", "The end", "The moon", "My true love"},
        {"A towel", "A cloud", "A plate", "Cutlery"},
        {"A promise", "A Glass Cup", "Water", "Love"}
    };
    char AnswersLetters[] = {'a','b','c','d'};
    char UserAnswer;
    int UserCorrectAnswers;
    int QuestionsArraySize = sizeof(Questions)/sizeof(Questions[0]);
    int AnswersArraySize = sizeof(Answers[0])/sizeof(Answers[0][0]);
    Shuffle(Questions, QuestionsArraySize);


    for(int i  = 0; i < QuestionsArraySize; i++) {
        std::cout << i + 1 << "ª) " << Questions[i] << '\n';
        Shuffle(Answers[i],AnswersArraySize);
        for(int j = 0; j < AnswersArraySize; j++) {
            std::cout << AnswersLetters[j] << ") " << Answers[i][j] << '\n';
        }
        std::cout << "Answer" << '\n' << "-> ";
        std::cin >> UserAnswer;
        
    }

    return 0;
}
