
#include <stdio.h>
#include <string.h>

#define MAX 100
#define WORD_LEN 50
#define MEANING_LEN 100

// Dictionary entry structure
struct DictionaryEntry {
    char word[WORD_LEN];
    char meaning[MEANING_LEN];
};

// Function prototypes
int searchWord(struct DictionaryEntry dict[], int count, char word[]);
void addWord(struct DictionaryEntry dict[], int *count);
void searchDictionary(struct DictionaryEntry dict[], int count);

int main() {
    struct DictionaryEntry dictionary[MAX];
    int wordCount = 0;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Add a new word\n");
        printf("2. Search for a word\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character left by scanf

        switch (choice) {
            case 1:
                addWord(dictionary, &wordCount);
                break;

            case 2:
                searchDictionary(dictionary, wordCount);
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Function to add a new word to the dictionary
void addWord(struct DictionaryEntry dict[], int *count) {
    if (*count >= MAX) {
        printf("Dictionary is full!\n");
        return;
    }

    printf("Enter the word: ");
    fgets(dict[*count].word, WORD_LEN, stdin);
    dict[*count].word[strcspn(dict[*count].word, "\n")] = 0;  // Remove newline

    printf("Enter the meaning: ");
    fgets(dict[*count].meaning, MEANING_LEN, stdin);
    dict[*count].meaning[strcspn(dict[*count].meaning, "\n")] = 0;  // Remove newline

    (*count)++;
    printf("Word added to the dictionary!\n");
}

// Function to search for a word in the dictionary
void searchDictionary(struct DictionaryEntry dict[], int count) {
    char word[WORD_LEN];

    printf("Enter the word to search: ");
    fgets(word, WORD_LEN, stdin);
    word[strcspn(word, "\n")] = 0;  // Remove newline

    int index = searchWord(dict, count, word);

    if (index != -1) {
        printf("Word: %s\n", dict[index].word);
        printf("Meaning: %s\n", dict[index].meaning);
    } else {
        printf("Word not found in the dictionary.\n");
    }
}

// Function to search for a word in the dictionary and return its index
int searchWord(struct DictionaryEntry dict[], int count, char word[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(dict[i].word, word) == 0) {
            return i;  // Word found, return index
        }
    }
    return -1;  // Word not found
}
