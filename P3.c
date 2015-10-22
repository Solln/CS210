/**************************************************************************
 *
 * Filename: P3.c
 *
 * Synopsis: P3.5
 *
 * Purpose: Braintrainer quiz which contains 24 questions, times the users input
 *          and gives the user their mark at the end.
 *
 * Author:
 *      Darren Lowe, Reg no: 201519214
 *
 * Group:
 *      Thu 3-5
 *
 * Promise: I confirm that this submission is all my own work.
 *
 *          (Signed)_____________________________________(Darren Lowe)
 *
 *
 * Version: See VERSION below
 *
 *********************************************************************/

/**************************REVISION HISTORY:**************************
 *
 *
 * Change P3.1 - Added white space to make code more readable
 *               as the code was very bunched and difficult to read
 *
 * Change P3.2 - Replaced 10 of the questions within the code
 *               as requested from the brief.
 *
 * Change P3.3 - Changed the Answers from ABCD to 1234 again as requested
 *               by the brief
 *
 * Change P3.4 - Changed the countdown to 3 seconds rather than 5 to avoid
 *               the long waiting time
 *
 * Change P3.5 - Added Revision and changed some comments to make code clearer
 *
 *     
 ***********************************************************************/

#define VERSION "p3 by Darren. Updated: 21/10/2015\n"

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define DEBUG 0

/* The following timing-related macros are based on the reaction.c
 * versions except that they are time_t and time() specific rather
 * than clock_t and clock() specific since the latter aren't
 * suitable for timing I/O bound programs.
 */
static time_t _startTime,_stopTime;   /* 'private' variables */
#define SNAP() (_startTime = time(NULL))
#define SHOT() (_stopTime  = time(NULL))
#define ELAPSED() (difftime(_stopTime,_startTime))
#define RUNTIME() (difftime(time(NULL),_startTime))
/* PAUSE(): a crude delay system - it waits for d seconds to expire. */
#define PAUSE(d) {SNAP();while ((int)RUNTIME() < d);}

/* The following macro is used to purge unwanted input */
#define consume() {char _xx; while(scanf("%c",&_xx),_xx!='\n');}

/* INERR is the Invalid Input Error */
#define INERR -1

/* NQA = Number of Question Answers. Array indices: 0 to NQA-1 */
/* Array index of 0 is a special debugging/dumping easter egg! */
#define NQA 5

char *options = "?1234Q!"; /* Maps input characters to indices */
/* Offset map is 0123456 for the above options character string */
/* An offset of 0 is the special debugging/dumping easter egg  */
/* Or an offset of 0 may be an error detect/trap/handle value  */
/* Last (offset) of the answer options is the Quit easter egg! */
#define QUIT 5
#define SHRIEK (QUIT+1)

typedef struct {
    char *pQuestion;      /* pointer to the question text (string)  */
    char *pAnswers[NQA];  /* pointers to the answer texts (strings) */
    int  correctAnswer;   /* number (index) of the correct answer   */
    int  traineeAnswer;   /* number (index) of the trainee's answer */
    time_t aTime;         /* records the time of answer to question */
} Question_t;

Question_t questions[] = { /* Initialisation of the test's Q&As */
    /*
     * The first (0th) entry is preamble. The question text is the
     * introduction, the answers are ignored, and the time recorded
     * in the aTime field is the time that the test started. This
     * makes the reporting the time taken for each answer very simple.
     */
    {"\nWelcome to Darren's LLP Brain Trainer Test"
        "\nPlease type any key to start the test ", /* Introductory text  */
        {"","","","",""},0, /* All other fields will be unused except for... */
        0,(time_t)NULL},    /* ...aTime which records the time the test began */
    /*
     * The following initialisations are for the actual Q&As and the
     * trainee's (eventual) answers and timestamps
     */
    {"The process of bootstrapping an early computer using paper tape is akin to laying tracks in front of
        "a train immediately before it runs over them. Which animation character performed a similar trick?\n",
        {"?","Buzz Lightyear\n","Slinky Dog\n","Mr Incredible\n","Gromit\n"},4,
        0,(time_t)NULL},
    
    {"What is the original meaning of the acronym RISC?\n",
        {"?","Rationalised Instruction Set Computer\n","Relax, It’s Smeed’s Class-test\n",
            "Reduced Instruction Set Computer\n","Regular Instruction Set Computer\n"},1,
        0,(time_t)NULL},
    
    {"In C what output does a printf(“-%d”,025) produce?\n",
        {"?","-025\n","-21\n","-25\n","-%d\n"},3,
        0,(time_t)NULL},
    
    {"What must all C programs include?\n",
        {"?","Comments\n","main()\n","printf\n","#define\n"},2,
        0,(time_t)NULL},
    
    {"What is an alternative notation for the C statement x = x * 3; ?",
        {"?","x = *3;\n","x *= 3;\n","x * 3 = x\n","x = 3*;\n"},2,
        0,(time_t)NULL},
    
    {"What is the || operator in C?\n",
        {"?","Conditional\n","Bitwise XOR\n",
            "Logical OR\n","Bitwise OR\n"},3,
        0,(time_t)NULL},
    
    {"Which of the following is not a factor in the CPU performance equation?\n",
        {"?","Instruction count\n","Clock rate\n","CPI\n","Instruction length\n"},4,
        0,(time_t)NULL},
    
    {"If multiply instructions take 6 cycles and account for 20% of the instructions executed\n"
        "and the other 80% of instructions have an average CPI of 1.5 cycles, what percentage\n"
        "of time does the CPU spend doing multiplication?\n",
        {"?","20%\n","25%\n","50%\n","80%\n"},1,
        0,(time_t)NULL},
    
    {"Given a native MIPS rating of 1000 and a CPI of 2 what is the clock rate of the processor?\n",
        {"?","500 MHz\n","1 GHz\n","2 GHz\n","4GHz\n"},3,
        0,(time_t)NULL},
    
    {"What is the CPI of a 500 Mhz processor that executes 800 million instructions in 2 seconds?\n",
        {"?","0.625\n","1.25\n",
            "1.6\n","4.0\n"},1,
        0,(time_t)NULL},
    
    {"Who first used the term \"Big Endian\" in his book Gulliver's Travels?\n",
        {"?","Danny Cohen\n","Jonathan Swift\n",
            "J R R Tolkien\n","Jamie Gulliver\n"},2,
        0,(time_t)NULL},
    
    {"In C which of the following would declare b as an array of 5 pointers\n"
        "to int?\n",
        {"?","int b[5];\n","*int b[5];\n","int **b[5];\n","int *b[5];\n"},4,
        0,(time_t)NULL},
    
    {"What does the sw stand for in a movswl instruction?\n",
        {"?","Stack Word \n","Segment Word \n",
            "Sign-extended Word\n","Semi-Word\n"},3,
        0,(time_t)NULL},
    
    {"In C what output does the a printf(\"-%d\",031) produce?\n",
        {"?","-031\n","-31\n","-25\n","-%d\n"},3,
        0,(time_t)NULL},
    
    {"If the register %ax has been allocated to a variable in C what is the\n"
        "most likely type of the variable declaration?\n",
        {"?","short int\n","float\n","long int\n","char\n"},1,
        0,(time_t)NULL},
    
    {"In C which of the following operators yields the address of its operand?\n",
        {"?","+\n","*\n","&\n","[ ]\n"},3,
        0,(time_t)NULL},
    
    {"What is the most likely/valid assembly language equivalent of the C\n"
        "statement 'i=i+s;'?\n",
        {"?","leal (i,s),%eax\n","addl (i+s),%eax\n",
            "addl %ebx,%eax\n","addl %ax,%bx,%ax\n"},3,
        0,(time_t)NULL},
    
    {"What is the most likely/valid assembly language equivalent of the C\n"
        "statement 'i++;'?\n",
        {"?","incl %eax\n","addl 4,%eax\n",
            "addl (%edx),%ecx\n","leal (%ax,1),%ax\n"},1,
        0,(time_t)NULL},
    
    {"What would you expect to be the first assembly language instruction\n"
        "of a C function?\n",
        {"?","pushl %esp\n","movl %esp,%ebp\n","pushl %ebp\n","movl %ebp,%esp\n"},3,
        0,(time_t)NULL},
    
    {"What would you expect to be the last assembly language instruction\n"
        "of a C function?\n",
        {"?","leave\n","movl %ebp,%esp\n","ret\n","popl %ebp\n"},3,
        0,(time_t)NULL},
    
    {"Given a C program file named hello.c which of the following would\n"
        "produce an assembler listing?\n",
        {"?","gcc hello.c\n","gcc -S hello.c\n",
            "gcc -O hello.c\n","gcc -A hello.c\n"},2,
        0,(time_t)NULL},
    
    {"What is the purpose of an ‘addl $16,%esp’ immediately after a\n"
        "call _printf?\n",
        {"?","The stack space used is reclaimed\n",
            "The return value of printf() is accessed\n",
            "The return value of printf() is saved\n",
            "The parameters to printf() are restored\n"},1,
        0,(time_t)NULL},
    
    {"Which of the following is not a valid type in C?\n",
        {"?","long char\n","unsigned char\n","signed char\n","char\n"},1,
        0,(time_t)NULL},
    
    {"What is the range of numbers that can be represented in a 16-bit\n"
        "unsigned short representation?\n",
        {"?","0 to 65535\n","-32767 to 32767\n",
            "-32768 to 32768\n","-32768 to 32767\n"},1,
        0,(time_t)NULL}
};






void Countdown( int delay ) {
    /* Cut delay to be in range 0 to 9 seconds... */
    if (delay %= 10) { /*...and if it's 0 don't bother counting down */
        printf("Seconds to go before the test starts: %1d",delay);
        while (delay--) {
            fflush(stdout); /* Flush output otherwise the lack of a newline... */
            PAUSE(1);       /* ...means text won't appear before/after pausing */
            printf("\b%1d",delay); /* \b (backspace) to 'update' the countdown */
        }
    }
}






int GetAnswer( char *options ) {
    char answer,next,*location;
    scanf("%c",&answer);  /* Expect a single character answer */
    if ('\n' == answer)   /* If there was no input then... */
        return(INERR);      /* ...return invalid input error */
    scanf("%c",&next);    /* Expect the end-of-line to be next */
    if ('\n' != next) {   /* If the next character was not eol */
        consume();          /* ...ignore it, and all that follow */
        return (INERR);     /* ...and return invalid input error */
    }
    /* At this point we satisfy the single character condition.
     * Now, use strchr() to check the input against the options
     * and if there's a match then return the offset into the
     * options string, otherwise return the invalid input error.
     */
    if (NULL == (location = strchr(options,toupper((int)answer))))
        return (INERR);   /* No match: return the invalid input error */
    else
        return (location-options); /* Matched: return option offset */
}






void MarkAnswers(Question_t questions[], /* (pointer to) the questions */
                 int nQs, /* the number of questions to be marked  */
                 char *options,  /* pointer to the answer options  */
                 int verbose) /* verbose output? 0 is no, non-0 is yes */
{
    int iQ,  /* index of the question */
    iAnswer, /* index of the correct answer */
    uAnswer, /* index of the user's answer */
    nCorrect = 0; /* number of correct answers */
    Question_t *pQ;  /* This pointer should help keep code short and quick */
    
    for ( iQ = 1 ; iQ <= nQs ; iQ++) {         /* For each question: */
        pQ = &questions[iQ]; /* The pointer shortens expressions to... */
        iAnswer = pQ->correctAnswer; /* ...pick out the correct answer */
        uAnswer = pQ->traineeAnswer; /* ...pick out the user's answer  */
        if (iAnswer == uAnswer) { /* If user's answer was correct...*/
            nCorrect++ ;          /* ...increment the correct tally */
        }
        if (verbose) { /* Verbose output includes the following:... */
            printf("Q%d) %s",iQ,pQ->pQuestion);    /* Question text */
            printf("\tCorrect answer:\t%c. %s",    /* Correct answer */
                   options[iAnswer],pQ->pAnswers[iAnswer]);
            printf("\tYour answer:\t%c. %s",         /* User's answer */
                   options[uAnswer],pQ->pAnswers[uAnswer]);
            printf("\tYour answer was %s\n",       /* Mark the answer */
                   (iAnswer == uAnswer)?"correct":"wrong");
            printf("\tTime taken to answer the question: %d seconds\n",
                   (int)difftime(pQ->aTime,questions[iQ-1].aTime));
        }
    } /* end for */
    
    printf("\nNumber of questions answered correctly:\t%d\n",nCorrect);
    printf("Number of questions answered wrongly:\t%d\n",nQs-nCorrect);
    
}





void AskQuestions(Question_t questions[], /* (pointer to) the questions */
                  int nQs, /* the number of questions to be asked */
                  int nAs) /* the number of answers for each question */
{
    int iQ, /* index of the question */
    iA, /* index for the answers */
    uAnswer; /* user's answer (index) */
    Question_t *pQ; /* This pointer should help keep code short and quick */
    
    for ( iQ = 1 ; /* Notes: Skip the 0th element as it's special. So,... */
         iQ <= nQs ; /* ...nQs is also the upper bound of questions[]... */
         /* ...iQ++ later on since we may need to repeat a question */ ) {
        /* Using a pointer to the current question helps keep expressions short */
        pQ = &questions[iQ];
        
        printf("\nQ%d) %s",iQ,pQ->pQuestion); /* Output a question followed... */
        for ( iA = 1 ; iA <= nAs ; iA++ )     /* ...by the possible options... */
            printf("\t%c. %s",options[iA],pQ->pAnswers[iA]);   /* ...for an answer */
        
        printf("Answer: "); /* Prompt for the answer... */
        switch ( (uAnswer=GetAnswer(options)) ) {/* ...and check answer is AOK */
            case SHRIEK:
                MarkAnswers(questions,--iQ,options,1); /* Quit with attitude */
                /* Fall through to the normal QUIT */
            case QUIT:
                printf("Quitting\n"); /* If it's an 'easter egg' to quit... */
                exit(0); /* ...then exit without further ado. */
            case INERR:
            case 0:  printf("Invalid input - ignored. I'll repeat the question.\n");
                continue; /* Invalid: so just continue with same question */
            default: pQ->traineeAnswer = uAnswer;    /* Note the answer... */
                pQ->aTime = time(NULL);         /* ...& current time. */
                iQ++; /* Valid: so iQ++ here moves onto next question */
                break; /* Defensive! Not really needed as default is last */
        }
    }
}






int main( int argc, char *argv[] ) {
    int nQs,nAs,verbose;
    
    printf(VERSION);
    /* The following (compile time) calculations of the number of questions
     * (nQs) and the number of possible answers (nAs) allows the program to
     * adjust itself automatically to the size of the data set.
     * Note: the -1 allows for the fact that as a defensive measure the 0th
     * array elements aren't counted thus allowing the indices into arrays to
     * be in the range 1 to nQs and 1 to nAs respectively. I.e. we consider
     * the arrays to have a lower bound of 1 rather than a lower bound of 0.
     * I.e. this give a more intuitive mapping of the question answers, for
     * example, where A -> 1, B -> 2, etc.
     */
    nQs = (int)(sizeof(questions)/sizeof(questions[0]))-1;
    nAs = (int)(sizeof(questions[0].pAnswers)/sizeof(questions[0].pAnswers[0]))-1;
    
#if DEBUG
    printf("Number of questions is: %d\n",nQs);
    printf("Number of answers is: %d\n",nAs);
#endif
    
    printf("%s",questions[0].pQuestion); /* 0th 'question' is the preamble */
    GetAnswer("Y");   /* Wait for a response - any, in fact, will do! */
    printf("\nThere are %d questions in this test. Good luck!\n\n",nQs);
    
    Countdown(3);     /* Output some typical Brain Trainer eye candy! */
    puts("");
    
    questions[0].aTime = SNAP(); /* Record the start time of the test */
    AskQuestions(questions,nQs,nAs); /* Self-explanatory I trust! */
    SHOT();                        /* Record the end time of the test */
    
    printf("\nThanks for taking Darren's LLP Brain Trainer Test!\n"
           "You completed the test in %d seconds\n",(int)ELAPSED());
    printf("Would you like the verbose version of your results? [Y/N]: ");
    verbose = (GetAnswer("NY") == 1);   /* Wait for a response */
    MarkAnswers(questions,nQs,options,verbose); /* Report the test results */
    
    return(0);
}

/* Example Code Output for version P3.5 ...
 
 
 Welcome to Darren's LLP Brain Trainer Test
 Please type any key to start the test h
 
 There are 24 questions in this test. Good luck!
 
 Seconds to go before the test starts: 0
 
 Q1) The process of bootstrapping an early computer using paper tape is akin to laying tracks in front of a train immediately before it runs over them. Which animation character performed a similar trick?
	1. Buzz Lightyear
	2. Slinky Dog
	3. Mr Incredible
	4. Gromit
 Answer: 1
 
 Q2) What is the original meaning of the acronym RISC?
	1. Rationalised Instruction Set Computer
	2. Relax, It’s Smeed’s Class-test
	3. Reduced Instruction Set Computer
	4. Regular Instruction Set Computer
 Answer: 2
 
 Q3) In C what output does a printf(“-%d”,025) produce?
	1. -025
	2. -21
	3. -25
	4. -%d
 Answer: 3
 
 Q4) What must all C programs include?
	1. Comments
	2. main()
	3. printf
	4. #define
 Answer: 4
 
 Q5) What is an alternative notation for the C statement x = x * 3; ?	1. x = *3;
	2. x *= 3;
	3. x * 3 = x
	4. x = 3*;
 Answer: 3
 
 Q6) What is the || operator in C?
	1. Conditional
	2. Bitwise XOR
	3. Logical OR
	4. Bitwise OR
 Answer: 2
 
 Q7) Which of the following is not a factor in the CPU performance equation?
	1. Instruction count
	2. Clock rate
	3. CPI
	4. Instruction length
 Answer: 1
 
 Q8) If multiply instructions take 6 cycles and account for 20% of the instructions executed
 and the other 80% of instructions have an average CPI of 1.5 cycles, what percentage
 of time does the CPU spend doing multiplication?
	1. 20%
	2. 25%
	3. 50%
	4. 80%
 Answer: 2
 
 Q9) Given a native MIPS rating of 1000 and a CPI of 2 what is the clock rate of the processor?
	1. 500 MHz
	2. 1 GHz
	3. 2 GHz
	4. 4GHz
 Answer: 3
 
 Q10) What is the CPI of a 500 Mhz processor that executes 800 million instructions in 2 seconds?
	1. 0.625
	2. 1.25
	3. 1.6
	4. 4.0
 Answer: 4
 
 Q11) Who first used the term "Big Endian" in his book Gulliver's Travels?
	1. Danny Cohen
	2. Jonathan Swift
	3. J R R Tolkien
	4. Jamie Gulliver
 Answer: 3
 
 Q12) In C which of the following would declare b as an array of 5 pointers
 to int?
	1. int b[5];
	2. *int b[5];
	3. int **b[5];
	4. int *b[5];
 Answer: 2
 
 Q13) What does the sw stand for in a movswl instruction?
	1. Stack Word
	2. Segment Word
	3. Sign-extended Word
	4. Semi-Word
 Answer: 1
 
 Q14) In C what output does the a printf("-%d",031) produce?
	1. -031
	2. -31
	3. -25
	4. -%d
 Answer: 2
 
 Q15) If the register %ax has been allocated to a variable in C what is the
 most likely type of the variable declaration?
	1. short int
	2. float
	3. long int
	4. char
 Answer: 3
 
 Q16) In C which of the following operators yields the address of its operand?
	1. +
	2. *
	3. &
	4. [ ]
 Answer: 4
 
 Q17) What is the most likely/valid assembly language equivalent of the C
 statement 'i=i+s;'?
	1. leal (i,s),%eax
	2. addl (i+s),%eax
	3. addl %ebx,%eax
	4. addl %ax,%bx,%ax
 Answer: 3
 
 Q18) What is the most likely/valid assembly language equivalent of the C
 statement 'i++;'?
	1. incl %eax
	2. addl 4,%eax
	3. addl (%edx),%ecx
	4. leal (%ax,1),%ax
 Answer: 2
 
 Q19) What would you expect to be the first assembly language instruction
 of a C function?
	1. pushl %esp
	2. movl %esp,%ebp
	3. pushl %ebp
	4. movl %ebp,%esp
 Answer: 1
 
 Q20) What would you expect to be the last assembly language instruction
 of a C function?
	1. leave
	2. movl %ebp,%esp
	3. ret
	4. popl %ebp
 Answer: 2
 
 Q21) Given a C program file named hello.c which of the following would
 produce an assembler listing?
	1. gcc hello.c
	2. gcc -S hello.c
	3. gcc -O hello.c
	4. gcc -A hello.c
 Answer: 3
 
 Q22) What is the purpose of an ‘addl $16,%esp’ immediately after a
 call _printf?
	1. The stack space used is reclaimed
	2. The return value of printf() is accessed
	3. The return value of printf() is saved
	4. The parameters to printf() are restored
 Answer: 4
 
 Q23) Which of the following is not a valid type in C?
	1. long char
	2. unsigned char
	3. signed char
	4. char
 Answer: 3
 
 Q24) What is the range of numbers that can be represented in a 16-bit
 unsigned short representation?
	1. 0 to 65535
	2. -32767 to 32767
	3. -32768 to 32768
	4. -32768 to 32767
 Answer: 2
 
 Thanks for taking Darren's LLP Brain Trainer Test!
 You completed the test in 20 seconds
 Would you like the verbose version of your results? [Y/N]: n
 
 Number of questions answered correctly:	3
 Number of questions answered wrongly:	21
 
 
 */

