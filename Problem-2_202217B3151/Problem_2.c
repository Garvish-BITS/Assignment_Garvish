#include <stdio.h>
#include <stdlib.h>

// Define structure for a polynomial term
typedef struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
} Term;

// Function declarations
Term* createTerm(int coefficient, int exponent);
void insertTerm(Term** poly, int coefficient, int exponent);
Term* addPolynomials(Term* poly1, Term* poly2);
void displayPolynomial(Term* poly);
void freePolynomial(Term* poly);

int main() {
    Term* poly1 = NULL;
    Term* poly2 = NULL;
    Term* result = NULL;

    int numTerms, coefficient, exponent;

    // Get the first polynomial
    printf("Enter the number of terms for the first polynomial: ");
    scanf("%d", &numTerms);
    for (int i = 0; i < numTerms; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coefficient, &exponent);
        insertTerm(&poly1, coefficient, exponent);
    }

    // Get the second polynomial
    printf("Enter the number of terms for the second polynomial: ");
    scanf("%d", &numTerms);
    for (int i = 0; i < numTerms; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coefficient, &exponent);
        insertTerm(&poly2, coefficient, exponent);
    }

    // Add the two polynomials
    result = addPolynomials(poly1, poly2);

    // Display the result
    printf("The resultant polynomial is: ");
    displayPolynomial(result);

    // Free allocated memory
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}

// Create a new term
Term* createTerm(int coefficient, int exponent) {
    Term* newTerm = (Term*)malloc(sizeof(Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

// Insert a term into the polynomial in descending order of exponents
void insertTerm(Term** poly, int coefficient, int exponent) {
    Term* newTerm = createTerm(coefficient, exponent);
    if (*poly == NULL || (*poly)->exponent < exponent) {
        newTerm->next = *poly;
        *poly = newTerm;
    } else {
        Term* temp = *poly;
        while (temp->next != NULL && temp->next->exponent > exponent) {
            temp = temp->next;
        }
        if (temp->next != NULL && temp->next->exponent == exponent) {
            temp->next->coefficient += coefficient;
            free(newTerm);
        } else {
            newTerm->next = temp->next;
            temp->next = newTerm;
        }
    }
}

// Add two polynomials
Term* addPolynomials(Term* poly1, Term* poly2) {
    Term* result = NULL;
    Term* temp1 = poly1;
    Term* temp2 = poly2;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->exponent == temp2->exponent) {
            insertTerm(&result, temp1->coefficient + temp2->coefficient, temp1->exponent);
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (temp1->exponent > temp2->exponent) {
            insertTerm(&result, temp1->coefficient, temp1->exponent);
            temp1 = temp1->next;
        } else {
            insertTerm(&result, temp2->coefficient, temp2->exponent);
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL) {
        insertTerm(&result, temp1->coefficient, temp1->exponent);
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        insertTerm(&result, temp2->coefficient, temp2->exponent);
        temp2 = temp2->next;
    }

    return result;
}

// Display the polynomial
void displayPolynomial(Term* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    Term* temp = poly;
    while (temp != NULL) {
        if (temp->coefficient > 0 && temp != poly) {
            printf("+");
        }
        printf("%dx^%d ", temp->coefficient, temp->exponent);
        temp = temp->next;
    }
    printf("\n");
}

// Free the allocated memory for the polynomial
void freePolynomial(Term* poly) {
    Term* temp;
    while (poly != NULL) {
        temp = poly;
        poly = poly->next;
        free(temp);
    }
}