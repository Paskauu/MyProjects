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

int SearchArrayChar(char Array[], int ArraySize, char IndexToSeach) {
    for (int i = 0; i < ArraySize; i++) {
        if (Array[i] == IndexToSeach) {
            return i;
        }
    }
    return 0;
}

int SearchArrayString(std::string Array[], int ArraySize, std::string IndexToSeach) {
    for (int i = 0; i < ArraySize; i++) {
        if (Array[i] == IndexToSeach) {
            std::cout << Array[1];
        }
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
    std::string CorrectAnswers[] = {
        "Lunch and Dinner",
        "Tomorrow",
        "A towel",
        "A promise"
    };
    char AnswersLetters[] = {'A','B','C','D'};
    char UserAnswer;
    int QuestionsArraySize = sizeof(Questions)/sizeof(Questions[0]);
    int AnswersArraySize = sizeof(Answers[0])/sizeof(Answers[0][0]);
    int AnswersLettersArraySize = sizeof(AnswersLetters)/sizeof(AnswersLetters[0]);
    Shuffle(Questions, QuestionsArraySize);
    int UserScore = 0;

    for(int i  = 0; i < QuestionsArraySize; i++) {
        std::cout << "###############################" << '\n';
        std::cout << i + 1 << "ª) " << Questions[i] << '\n';
        for(int j = 0; j < AnswersArraySize; j++) {
            std::cout << AnswersLetters[j] << ") " << Answers[i][j] << '\n';
        }
        std::cout << "Answer" << '\n' << "-> ";
        std::cin >> UserAnswer;
        UserAnswer = SearchArrayChar(AnswersLetters,AnswersLettersArraySize,toupper(UserAnswer));
        if (Answers[i][UserAnswer] == CorrectAnswers[i]) {
            UserScore++;
        }
    }

    std::cout << "Your final Score is: " << UserScore << "/" << QuestionsArraySize;

    return 0;
}
