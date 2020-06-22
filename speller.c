bool check(const char *word)

{

int len = strlen(word);



char lword[len + 1];



for (int i = 0; i < len; i++)

{

lword[i] = tolower(word[i]);

}



lword[len] = '\0';



// hash the word and store it in a variable called hash_code

int hash_code = hash(lword);



// set a temporary variable, to store the linked list

node *temp = table[hash_code];



// while the link list exists

while (temp != NULL)

{

// check if the word in the dictionary matches with the word in the hash table

if (strcasecmp(temp -> word, lword) != 0)

{

temp = temp -> next;

}

else

{



return true;

}



}



return false;

}

// Loads dictionary into memory, returning true if successful else false

bool load(const char *dictionary)

{



// open up dictionary file

FILE *dictionary_file = fopen(dictionary, "r");



// check to see if file is null

if (dictionary == NULL)

{

// if so, exit the loop

return false;

}



// set an array in which to store words

char word[LENGTH + 1];



// read strings from file one at a time

while (fscanf(dictionary_file,"%s", word) != 1)

{

// read the string using fscanf

fscanf(dictionary_file, "%s", word);





// create a new node for each word using malloc

node *n = malloc(sizeof(node));

n -> next = NULL;



// check if malloc is null

if (n == NULL)

{

return false;

}



// copy each word into a node using strcpy

strcpy(n -> word, word);



// hash word to obtain a hash value

int num = hash(n -> word);



// if hashtable is empty, insert node into hash table at that location

if (table[num] == NULL)

{

table[num] = n;

n -> next = NULL;



}

else

{

// if hashtable is not empty, append node into hash table at that location

n -> next = table[num];

table[num] = n;

}

dic_size++;



}

fclose(dictionary_file);

return true;

}