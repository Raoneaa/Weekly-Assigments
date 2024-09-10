#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h> // Include for assertions

#define MAX_INGREDIENTS 10

//Struct for an ingredient
typedef struct {
    char name[50];
    double price;
} Ingredient;

//Struct for a recipe
typedef struct {
    char name[50];
    Ingredient ingredients[MAX_INGREDIENTS];
    int ingredient_count;
} Recipe;

//Node for the BST
typedef struct Node {
    Recipe recipe;
    struct Node* left;
    struct Node* right;
} Node;

//Function to create a new node
Node* createNode(Recipe recipe) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->recipe = recipe;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a recipe into the BST, use the number of ingredients to decide left or right
Node* insert(Node* root, Recipe recipe) {
    // if it is the first reciper added then it makes it the root for the rest
    if(root == NULL) {
         root = createNode(recipe);
        return root;
    }
    // if its less than the current root then it sends it left
    if(recipe.ingredient_count < root->recipe.ingredient_count){
        root->left = insert(root->left,recipe);
    }
    // if its greater than the current root than it adds it to the right
    else if(recipe.ingredient_count > root->recipe.ingredient_count){
        root->right = insert(root->right,recipe);
    }
    return root;
}


//This function should count all nodes in the tree recursively
int countNodes(Node* root) {
    // base case
    if(root == NULL){
        return 0;
    }
    //adds to the count
    int count = 1;
    // checks all the left then goes to the right of each root until the leave is found
    count += countNodes(root->right);
    count += countNodes(root->left);
    return count; // returns the count at the end
}


//This function should return the price of all ingredients combined
double calculateTotalPrice(Node* root) {
    // base case
    if(root == NULL){
        return 0;
    }
    double total = 0; // initializing the total
// loops for howerer many ingrediens there are then adds that to the total
    for (int i = 0; i < root->recipe.ingredient_count; i++) {
        total += root->recipe.ingredients[i].price;
    }
    // calls the left root to count those
    total += calculateTotalPrice(root->left);
    // calls the right root
    total += calculateTotalPrice(root->right);

    return total;
}

// This function makes sure everything in the tree is where it should be
void getRecipesInArray(Node* root, Recipe* recipes, int* index) {
    if (root != NULL) {
        getRecipesInArray(root->left, recipes, index);
        recipes[*index] = root->recipe;
        (*index)+=1;
        getRecipesInArray(root->right, recipes, index);
    }
}

// Function to free the BST
void freeBST(Node* root) {
    if (root != NULL) {
        freeBST(root->left);
        freeBST(root->right);
        free(root);
    }
}


int main() {
    Node* root = NULL;


    Ingredient tomato = {"Tomato", 1.2};
    Ingredient noodles = {"Noodles", 0.8};
    Ingredient cheese = {"Cheese", 2.5};
    Ingredient lettuce = {"Lettuce", 0.5};
    Ingredient bread = {"Bread", 1.0};
    Ingredient ham = {"Ham", 2.0};
    Ingredient chocolate = {"Chocolate", 10.0};

    // Creating recipes
    Recipe recipe1 = {"Pasta", {tomato, noodles, cheese}, 3};
    Recipe recipe2 = {"Salad", {lettuce, tomato}, 2};
    Recipe recipe3 = {"Ham Sandwich", {bread, ham, cheese, lettuce}, 4};
    Recipe recipe4 = {"Death By Chocolate", {chocolate,chocolate,chocolate,chocolate,chocolate},5};

    // Insert recipes into the BST
    root = insert(root, recipe1);
    root = insert(root, recipe2);
    root = insert(root, recipe3);
    root = insert(root, recipe4);

    //Validate the number of nodes in the BST
    int nodeCount = countNodes(root);
    assert(nodeCount == 4);

    //Retrieve the recipes in an array for validation
    Recipe retrievedRecipes[4];
    int index = 0;
    getRecipesInArray(root, retrievedRecipes, &index);

    //Check da tree structure
    assert(retrievedRecipes[0].ingredient_count == 2);
    assert(retrievedRecipes[1].ingredient_count == 3);
    assert(retrievedRecipes[2].ingredient_count == 4);
    assert(retrievedRecipes[3].ingredient_count == 5);

    //calculate the price
    double price = calculateTotalPrice(root);
    assert(price == 62.2);

    //Free le BST
    freeBST(root);

    printf("All tests passed successfully! :3\n");
    return 0;
}
